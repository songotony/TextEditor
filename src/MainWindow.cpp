#include "MainWindow.hpp"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_choiceDial(new ChoiceDialog(this)),
    m_textDial(new AddTextDialog(this))
{
    ui->setupUi(this);
    this->ui->tabBar->addTab("English");
    this->ui->tabBar->addTab("+");
    this->ui->tabBar->setCurrentIndex(0);
    this->ui->tabBar->setTabData(0, ENGLISH);
    this->ui->tabBar->setTabData(1, NONE);
    this->ui->tabBar->setSelectionBehaviorOnRemove(QTabBar::SelectLeftTab);
    this->m_choiceDial->setModal(true);
    this->m_textDial->setModal(true);
    this->m_lastIndex = 0;
    connect(this->m_choiceDial, SIGNAL(accepted()), this, SLOT(languageChosen()));
    connect(this->m_textDial, SIGNAL(accepted()), this, SLOT(textCreated()));
    connect(this->ui->tabBar, SIGNAL(currentChanged(int)), this, SLOT(selectTab(int)));
    connect(this->ui->tabBar, SIGNAL(tabCloseRequested(int)), this, SLOT(removeTab(int)));
}

MainWindow::~MainWindow()
{
    delete this->m_textDial;
    delete this->m_choiceDial;
    delete ui;
}

void MainWindow::selectTab(int index)
{
    std::vector<Language> present;
    std::vector<QString> choices;

    if (index == -1)
        return;
    if (index == this->ui->tabBar->count() - 1)
    {
        for (int i = 0; i < this->ui->tabBar->count() - 1; i++)
            present.push_back(*static_cast<Language *>(this->ui->tabBar->tabData(i).data()));
        for (size_t i = 0; i < LANGUAGE_NUMBER; i++)
            if (std::find(present.begin(), present.end(), langTab[i].language) == present.end())
                choices.push_back(langTab[i].text);
        this->m_choiceDial->init("Add language", "Language :", choices);
        this->m_choiceDial->show();
        this->ui->tabBar->setCurrentIndex(this->m_lastIndex);
        return;
    }
    this->m_lastIndex = index;
}

void MainWindow::removeTab(int index)
{
    if (index == -1)
        return;
    this->ui->tabBar->removeTab(index);
    if (this->ui->tabBar->count() == 2)
        this->ui->tabBar->setTabsClosable(false);
}

void MainWindow::languageChosen(void)
{
    QString selected = this->m_choiceDial->getChosen();

    for (size_t i = 0; i < LANGUAGE_NUMBER; i++)
        if (langTab[i].text == selected)
        {
            this->ui->tabBar->insertTab(this->ui->tabBar->count() - 1, langTab[i].text);
            this->ui->tabBar->setTabData(this->ui->tabBar->count() - 2, langTab[i].language);
            this->ui->tabBar->setCurrentIndex(this->ui->tabBar->count() - 2);
            break;
        }
    this->ui->tabBar->setTabsClosable(true);
    this->ui->tabBar->tabButton(this->ui->tabBar->count() - 1, QTabBar::RightSide)->hide();
}

void MainWindow::textCreated(void)
{
    Text *text = this->m_textDial->getValue();
    QStringList strList(text->getID());
    QTreeWidgetItem *item;

    this->m_texts.push_back(text);
    strList.push_back(text->getText(*static_cast<Language *>(this->ui->tabBar->tabData(this->ui->tabBar->currentIndex()).data())));
    item = new QTreeWidgetItem(strList);
    this->ui->treeText->addTopLevelItem(item);
}

void MainWindow::on_addButton_clicked()
{
    std::vector<Language> present;
    std::vector<QString> ids;

    for (size_t i = 0; i < this->m_texts.size(); i++)
        ids.push_back(this->m_texts[i]->getID());
    for (size_t i = 0; i < this->ui->tabBar->count() - 1; i++)
        present.push_back(*static_cast<Language *>(this->ui->tabBar->tabData(static_cast<int>(i)).data()));
    this->m_textDial->init(present, ids);
    this->m_textDial->show();
}
