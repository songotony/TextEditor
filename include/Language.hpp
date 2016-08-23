#ifndef LANGUAGE_HPP
#define LANGUAGE_HPP

#define LANGUAGE_NUMBER 4

#include <QString>

enum Language
{
    ENGLISH,
    FRENCH,
    RUSSIAN,
    JAPANESE,
    NONE
};

typedef struct sLanguageTab
{
    QString text;
    Language language;
} LanguageTab;

static LanguageTab langTab[LANGUAGE_NUMBER] = {
    {"English", ENGLISH},
    {"Français", FRENCH},
    {"русский", RUSSIAN},
    {"日本の", JAPANESE}
};

#endif // LANGUAGE_HPP
