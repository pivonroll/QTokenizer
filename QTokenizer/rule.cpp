#include "rule.h"

namespace QTokenizer {
namespace Internal {

Rule::Rule(const QRegExp &regExpr, int tokenId)
    : m_regExpresion(regExpr),
      m_tokenId(tokenId)
{

}

int Rule::tokenId() const
{
    return m_tokenId;
}

void Rule::match(const QString &sentence, int &matchPosition, int &matchCount)
{

}

QRegExp Rule::rule() const
{
    return m_regExpresion;
}


} // namespace Internal
} // namespace QTokenizer
