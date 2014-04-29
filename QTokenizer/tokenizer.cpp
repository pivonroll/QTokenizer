#include "tokenizer.h"

#include "rule.h"
#include "rulematcher.h"
#include "token.h"

namespace QTokenizer {
namespace Internal {

Tokenizer::Tokenizer()
    : m_sentenceMatchOffset(0),
      m_previousMatch(MATCH),
      m_savedRule(0)
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

    if (m_sentenceMatchOffset >= m_sentence.length())
        return NO_MATCH;

    if (m_previousMatch == UNMATCHED_CHARS_FOUND) {
        if (m_savedRule) {
            token = new Token(m_savedRule->tokenId(), m_savedRule->matchedString());
            m_previousMatch = MATCH;

            if (m_savedRule->type() == Rule::DELIMITER_RULE)
                m_previousMatch = DELIMITER;

            m_savedRule = 0;
            return m_previousMatch;
        }
        return NO_MATCH;
    }

    int matchCount = 0;
    QString unmatchedPart;
    Rule *rule = m_ruleMatcher.findMatchingRule(m_sentence, m_sentenceMatchOffset, matchCount, unmatchedPart);

    MatchResult result = MATCH;

    if (!unmatchedPart.isEmpty()) {
        token = new Token(NO_MATCH, unmatchedPart);
        m_savedRule = rule;
        result = UNMATCHED_CHARS_FOUND;
    } else if (rule) {
        token = new Token(rule->tokenId(), rule->matchedString());

        if (rule->type() == Rule::DELIMITER_RULE)
            result = DELIMITER;
    }

    m_sentenceMatchOffset += matchCount;
    m_previousMatch = result;
    return result;
}

void Tokenizer::setDelimiters(const QStringList &delimiters)
{
    m_ruleMatcher.setStringDelimiters(delimiters);
}

} // namespace Internal
} // namespace QTokenizer
