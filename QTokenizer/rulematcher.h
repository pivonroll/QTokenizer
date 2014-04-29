#ifndef QTOKENIZER_INTERNAL_RULEMATCHER_H
#define QTOKENIZER_INTERNAL_RULEMATCHER_H

#include "rules.h"

#include <QtGlobal>
#include <QStringList>

QT_FORWARD_DECLARE_CLASS(QString)
QT_FORWARD_DECLARE_CLASS(QRegExp)

namespace QTokenizer {
namespace Internal {

class Rule;

class RuleMatcher
{
public:
    RuleMatcher();
    void addRule(const QRegExp &regExp, int tokenId);

    Rule *findMatchingRule(const QString &sentence, int sentenceOffset, int &matchCount, QString &unmatchedCharacters);
    void setStringDelimiters(const QStringList &delimiters);

private:
    Rule *findRule(const QString &sentence, int sentenceOffset, int &matchCount);

    Rules m_rules;
    QStringList m_delimiters;
};

} // namespace Internal
} // namespace QTokenizer

#endif // QTOKENIZER_INTERNAL_RULEMATCHER_H
