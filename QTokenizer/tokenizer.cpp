#include "tokenizer.h"

#include "rule.h"
#include "rulematcher.h"
#include "token.h"

namespace QTokenizer {
namespace Internal {

Tokenizer::Tokenizer()
    : m_sentenceMatchOffset(0),
      m_previousMatch(MATCH)
{
}

void Tokenizer::addRule(const QRegExp &regExp, int tokenId)
{
    m_ruleMatcher.addRule(regExp, tokenId);
}

QString Tokenizer::getSentence() const
{
    return m_sentence;
}

void Tokenizer::setSentence(const QString &sentence)
{
    m_sentence = sentence;
}

Tokenizer::MatchResult Tokenizer::match(Token *&token)
{
    Q_UNUSED(token)

    if (m_previousMatch == NO_MATCH)
        return NO_MATCH;

    int matchCount = 0;
    Rule *rule = m_ruleMatcher.findMatchingRule(m_sentence, m_sentenceMatchOffset, matchCount);

    if (!rule)
        return NO_MATCH;

    token = new Token(rule->tokenId(), rule->matchedString());
    m_sentenceMatchOffset += matchCount;

    return MATCH;
}

void Tokenizer::setDelimiters(const QStringList &delimiters)
{
    m_ruleMatcher.setStringDelimiters(delimiters);
}

} // namespace Internal
} // namespace QTokenizer
