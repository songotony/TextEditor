#ifndef ADDTEXTDIALOG_HPP
#define ADDTEXTDIALOG_HPP

#include <QDialog>
#include <QTextEdit>
#include <QLabel>

#include <utility>

#include "Language.hpp"
#include "Text.hpp"

namespace Ui {
class AddTextDialog;
}

class AddTextDialog : public QDialog
{
    Q_OBJECT

private:
    void checkData(void) const;

public:
    explicit AddTextDialog(QWidget *parent = 0);
    ~AddTextDialog();

public:
    void init(const std::vector<Language> &, const std::vector<QString> &);
    Text *getValue(void) const;

private slots:
    void on_lineID_textChanged(const QString &arg1);

private:
    Ui::AddTextDialog *ui;
    std::vector<std::pair<QLabel *, QTextEdit *>> m_texts;
    std::vector<QString> m_ids;
};

#endif // ADDTEXTDIALOG_HPP
