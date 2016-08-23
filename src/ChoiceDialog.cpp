#include "ChoiceDialog.hpp"
#include "ui_choicedialog.h"

ChoiceDialog::ChoiceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChoiceDialog)
{
    ui->setupUi(this);
}

ChoiceDialog::~ChoiceDialog()
{
    delete ui;
}

void ChoiceDialog::init(const QString &title, const QString &label, const std::vector<QString> &choices)
{
    this->setWindowTitle(title);
    this->ui->labelChoice->setText(label);
    this->ui->selectChoice->clear();
    for (size_t i = 0; i < choices.size(); i++)
        this->ui->selectChoice->addItem(choices[i].toUtf8());
}

const QString ChoiceDialog::getChosen(void)
{
    return (this->ui->selectChoice->currentText());
}
