#include "AddTextDialog.hpp"
#include "ui_addtextdialog.h"

AddTextDialog::AddTextDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTextDialog)
{
    ui->setupUi(this);
    this->ui->labelError->setPalette(QColor(255, 255, 0));
    this->checkData();
}

AddTextDialog::~AddTextDialog()
{
    for (size_t i = 0; i < this->m_texts.size(); i++)
    {
        delete (this->m_texts[i].first);
        delete (this->m_texts[i].second);
    }
    delete ui;
}

void AddTextDialog::checkData(void) const
{
    if (std::find(this->m_ids.begin(), this->m_ids.end(), this->ui->lineID->text()) != this->m_ids.end())
        this->ui->labelError->setText("Warning : ID must be unique");
    else
        this->ui->labelError->setText("");
    this->ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(this->ui->lineID->text() != "" && this->ui->labelError->text() == "");
}

void AddTextDialog::init(const std::vector<Language> &presents, const std::vector<QString> &ids)
{
    QLabel *tmpLabel;
    QTextEdit *tmpText;

    this->ui->tabWidget->setCurrentIndex(0);
    this->m_ids = ids;
    this->checkData();
    for (size_t i = 0; i < this->m_texts.size(); i++)
    {
        delete (this->m_texts[i].first);
        delete (this->m_texts[i].second);
    }
    this->m_texts.clear();
    for (size_t i = 0; i < LANGUAGE_NUMBER; i++)
        if (std::find(presents.begin(), presents.end(), langTab[i].language) != presents.end())
        {
            tmpLabel = new QLabel(langTab[i].text.toUtf8() + " :", this->ui->scrollContentLanguages);
            tmpLabel->setProperty("Language", langTab[i].language);
            tmpText = new QTextEdit(this->ui->scrollContentLanguages);
            static_cast<QFormLayout *>(this->ui->scrollContentLanguages->layout())->addRow(tmpLabel, tmpText);
            this->m_texts.push_back(std::make_pair(tmpLabel, tmpText));
        }
    this->ui->comboNext->clear();
    this->ui->comboNext->addItem("None");
    for (size_t i = 0; i < ids.size(); i++)
        this->ui->comboNext->addItem(ids[i]);
}

Text *AddTextDialog::getValue(void) const
{
    Text *text = new Text(this->ui->lineID->text());

    for (size_t i = 0; i < this->m_texts.size(); i++)
        text->setText(*static_cast<Language*>(this->m_texts[i].first->property("Language").data()), this->m_texts[i].second->toPlainText());
    if (this->ui->comboNext->currentIndex() != 0)
        text->setNext(this->ui->comboNext->currentText());
    for (int i = 0; i < this->ui->listPrev->count(); i++)
        text->addPrev(this->ui->listPrev->item(i)->text());
    for (int i = 0; i < this->ui->listParent->count(); i++)
        text->addParent(this->ui->listParent->item(i)->text());
    for (int i = 0; i < this->ui->listSon->count(); i++)
        text->addChild(this->ui->listSon->item(i)->text());
    return (text);
}

void AddTextDialog::on_lineID_textChanged(const QString &)
{
    this->checkData();
}
