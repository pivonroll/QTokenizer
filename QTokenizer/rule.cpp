#include "rule.h"

namespace QTokenizer {
namespace Internal {

Rule::Rule(RuleType ruleType, const QRegExp &regExpr, int tokenId)
    : m_regExpresion(regExpr),
      m_tokenId(tokenId),
      m_ruleType(ruleType)
{
}

Rule::RuleType Rule::type() const
{
    return m_ruleType;
}

int Rule::tokenId() const
{
    return m_tokenId;
}

int Rule::match(const QString &sentence, int sentenceOffset, int &matchCount)
{
    int matchPosition = sentence.indexOf(m_regExpresion, sentenceOffset);
    matchCount = m_regExpresion.matchedLength();
    m_matchedString = sentence.mid(sentenceOffset, matchCount);

    return matchPosition;
}

QRegExp Rule::rule() const
{
    return m_regExpresion;
}

QString Rule::matchedString() const
{
    return m_matchedString;
}


} // namespace Internal
} // namespace QTokenizer
