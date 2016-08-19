#include "LanguageDialog.hpp"
#include "ui_languagedialog.h"

LanguageDialog::LanguageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LanguageDialog)
{
    ui->setupUi(this);
}

LanguageDialog::~LanguageDialog()
{
    delete ui;
}
