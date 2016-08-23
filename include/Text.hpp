#ifndef TEXT_HPP
#define TEXT_HPP

#include <map>
#include <vector>

#include <QString>

#include "Language.hpp"

class Text
{
    std::map<Language, QString> m_texts;
    QString m_next;
    std::vector<QString> m_prevs;
    std::vector<QString> m_parents;
    std::vector<QString> m_children;
    const QString m_id;

public:
    Text(const QString &);
    ~Text(void);

public: //GETTERS
    const QString &getID(void) const;
    const QString &getText(Language) const;
    const QString &getNext(void) const;
    const std::vector<QString> &getPrevs(void) const;
    const std::vector<QString> &getParents(void) const;
    const std::vector<QString> &getChildren(void) const;

public: //SETTERS
    void setText(Language, const QString &);
    void setNext(const QString &);
    void addPrev(const QString &);
    void addParent(const QString &);
    void addChild(const QString &);
    void setPrevs(const std::vector<QString> &);
    void setParents(const std::vector<QString> &);
    void setChildren(const std::vector<QString> &);
};

#endif // TEXT_HPP
