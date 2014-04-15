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

Rule *RuleMatcher::findMatchingRule(const QString &sentence, int &matchCount)
{
    Rule *rule = findRule(sentence, matchCount);

    if (rule)
        return rule;

    // if no rule was matched, we trimm delimiters from left of the sentence and try to match again
    int trimmedCharCount = 0;
    QString trimmedSentence = trimmerDelimiters(sentence, trimmedCharCount);
    rule = findRule(trimmedSentence, matchCount);

    matchCount += trimmedCharCount;

    return rule;
}

void RuleMatcher::setStringDelimiters(const QStringList &delimiters)
{
    m_delimiters = delimiters;
}

Rule *RuleMatcher::findRule(const QString &sentence, int &matchCount)
{
    for (int i = 0; i < m_rules.ruleCount(); ++i) {
        Rule *rule = m_rules.rule(i);

        if (!rule)
            continue;

        int matchingPosition;
        int matchCount;

        rule->match(sentence, matchingPosition, matchCount);

        if (!matchingPosition)
            return rule;
    }

    return 0;
}

QString RuleMatcher::trimmerDelimiters(const QString &sentence, int trimmedCharCount) const
{
    QString trimmedSentence = sentence;

    int delimiterLength = startsWithAnyDelimiter(trimmedSentence);
    trimmedCharCount = delimiterLength;

    while (delimiterLength) {
        trimmedSentence = trimmedSentence.left(delimiterLength);
        trimmedCharCount += delimiterLength;

        delimiterLength = startsWithAnyDelimiter(trimmedSentence);
    }

    return trimmedSentence;
}

int RuleMatcher::startsWithAnyDelimiter(const QString &sentence)
{
    foreach (const QString &delimiter, m_delimiters) {
        if (sentence.startsWith(delimiter))
            return delimiter.size();
    }

    return 0;
}

} // namespace Internal
} // namespace QTokenizer
