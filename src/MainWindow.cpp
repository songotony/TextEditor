#include "MainWindow.hpp"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->tabBar->addTab("English");
    this->ui->tabBar->addTab("+");
    this->ui->tabBar->setCurrentIndex(0);
    this->ui->tabBar->setTabData(0, ENGLISH);
    this->ui->tabBar->setTabData(1, NONE);
    connect(this->ui->tabBar, SIGNAL(currentChanged(int)), this, SLOT(selectTab(int)));
    connect(this->ui->tabBar, SIGNAL(tabCloseRequested(int)), this, SLOT(removeTab(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectTab(int index)
{
    if (index == -1)
        return;
    if (index == this->ui->tabBar->count() - 1)
    {
        this->ui->tabBar->setCurrentIndex(this->ui->tabBar->count() - 2);
    }
}

void MainWindow::removeTab(int index)
{
    if (index == -1)
        return;
}
