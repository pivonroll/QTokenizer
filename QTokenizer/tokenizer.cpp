#include "tokenizer.h"

#include "rule.h"
#include "rulematcher.h"

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

Tokenizer::MatchResult Tokenizer::match(int &tokenId)
{
    if (m_previousMatch == NO_MATCH)
        return NO_MATCH;

    QStringRef ref = m_sentence.rightRef(m_sentenceMatchOffset);

    if (ref.string()) {
        int matchCount;
        Rule *rule = m_ruleMatcher.findMatchingRule(m_sentence.rightRef(m_sentenceMatchOffset), matchCount);

        if (!rule)
            return NO_MATCH;

        tokenId = rule->tokenId();

        return MATCH;
        m_sentenceMatchOffset += matchCount;
    }
}

void Tokenizer::setDelimiters(const QStringList &delimiters)
{
    m_previousMatch.setDelimiters(delimiters);
}

} // namespace Internal
} // namespace QTokenizer
