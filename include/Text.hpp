#ifndef TEXT_HPP
#define TEXT_HPP

#include <map>

#include <QString>

class Text
{
    std::map<QString, QString> m_texts;

public:
    Text(void);
    ~Text(void);
};

#endif // TEXT_HPP
