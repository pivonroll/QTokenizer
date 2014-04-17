#include "rulematcher.h"

#include "rule.h"

namespace QTokenizer {
namespace Internal {

RuleMatcher::RuleMatcher()
{
}

void RuleMatcher::addRule(const QRegExp &regExp, int tokenId)
{
    Rule *rule = new Rule(regExp, tokenId);
    m_rules.addRule(rule);
}

Rule *RuleMatcher::findMatchingRule(const QString &sentence, int sentenceOffset, int &matchCount)
{
    Rule *rule = findRule(sentence, sentenceOffset, matchCount);

    if (rule)
        return rule;

    // if no rule was matched, we eliminate delimiters from left of the sentence and try to match again
    int trimmedCharCount = delimiterLengthCount(sentence, sentenceOffset);
    rule = findRule(sentence, sentenceOffset + trimmedCharCount, matchCount);

    matchCount += trimmedCharCount;

    return rule;
}

void RuleMatcher::setStringDelimiters(const QStringList &delimiters)
{
    m_delimiters = delimiters;
}

Rule *RuleMatcher::findRule(const QString &sentence, int sentenceOffset, int &matchCount)
{
    for (int i = 0; i < m_rules.ruleCount(); ++i) {
        Rule *rule = m_rules.rule(i);

        if (!rule)
            continue;

        int matchingPosition = rule->match(sentence, sentenceOffset, matchCount);

        if (matchingPosition == sentenceOffset)
            return rule;
    }

    return 0;
}

int RuleMatcher::delimiterLengthCount(const QString &sentence, int offset) const
{
    QString trimmedSentence = sentence.mid(offset);

    int delimiterLength = startsWithAnyDelimiter(trimmedSentence);
    int trimmedCharCount = 0;

    while (delimiterLength) {
        trimmedSentence = trimmedSentence.mid(delimiterLength);
        trimmedCharCount += delimiterLength;

        delimiterLength = startsWithAnyDelimiter(trimmedSentence);
    }

    return trimmedCharCount;
}

int RuleMatcher::startsWithAnyDelimiter(const QString &sentence) const
{
    foreach (const QString &delimiter, m_delimiters) {
        if (sentence.startsWith(delimiter))
            return delimiter.size();
    }

    return 0;
}

} // namespace Internal
} // namespace QTokenizer
