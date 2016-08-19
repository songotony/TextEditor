#ifndef LANGUAGEDIALOG_HPP
#define LANGUAGEDIALOG_HPP

#include <QDialog>

enum Language
{
    ENGLISH,
    FRENCH,
    RUSSIAN,
    JAPAN,
    NONE
};

typedef struct sLanguageTab
{
    QString text;
    Language language;
} LanguageTab;

namespace Ui {
class LanguageDialog;
}

class LanguageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LanguageDialog(QWidget *parent = 0);
    ~LanguageDialog();

private:
    Ui::LanguageDialog *ui;
};


#define LANGUAGE_NUMBER 4

static LanguageTab langTab[LANGUAGE_NUMBER] = {
    {"Francais", FRENCH},
    {"English", ENGLISH},
    {"???????", RUSSIAN},
    {"???", JAPAN}
};

#endif // LANGUAGEDIALOG_HPP
