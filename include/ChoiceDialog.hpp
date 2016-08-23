#ifndef LANGUAGEDIALOG_HPP
#define LANGUAGEDIALOG_HPP

#include <QDialog>

#include <vector>

#include "Language.hpp"

namespace Ui {
class ChoiceDialog;
}

class ChoiceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChoiceDialog(QWidget *parent = 0);
    ~ChoiceDialog();

public:
    void init(const QString &, const QString &, const std::vector<QString> &);
    const QString getChosen(void);

private:
    Ui::ChoiceDialog *ui;
};

#endif // LANGUAGEDIALOG_HPP
