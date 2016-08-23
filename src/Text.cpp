#include "Text.hpp"

Text::Text(const QString &id) :
    m_id(id)
{
}

Text::~Text(void)
{
}

const QString &Text::getID(void) const
{
    return (this->m_id);
}

const QString &Text::getText(Language language) const
{
    return (this->m_texts.at(language));
}

const QString &Text::getNext(void) const
{
    return (this->m_next);
}

const std::vector<QString> &Text::getPrevs(void) const
{
    return (this->m_prevs);
}

const std::vector<QString> &Text::getParents(void) const
{
    return (this->m_parents);
}

const std::vector<QString> &Text::getChildren(void) const
{
    return (this->m_children);
}

void Text::setText(Language language, const QString &text)
{
    this->m_texts[language] = text;
}

void Text::setNext(const QString &next)
{
    this->m_next = next;
}

void Text::addPrev(const QString &prev)
{
    this->m_prevs.push_back(prev);
}

void Text::addParent(const QString &parent)
{
    this->m_parents.push_back(parent);
}

void Text::addChild(const QString &child)
{
    this->m_children.push_back(child);
}

void Text::setPrevs(const std::vector<QString> &prevs)
{
    this->m_prevs = prevs;
}

void Text::setParents(const std::vector<QString> &parents)
{
    this->m_parents = parents;
}

void Text::setChildren(const std::vector<QString> &children)
{
    this->m_children = children;
}
