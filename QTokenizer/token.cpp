#include "token.h"

namespace QTokenizer {
namespace Internal {

Token::Token(int tokenId, const QString &matchedText)
    : m_id(tokenId),
      m_matchedText(matchedText)
{

}

int Token::id() const
{
    return m_id;
}

QString Token::matchedText() const
{
    return m_matchedText;
}

} // namespace Internal
} // namespace QTokenizer
