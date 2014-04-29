#include "rulematcher.h"

#include "rule.h"

namespace QTokenizer {
namespace Internal {

RuleMatcher::RuleMatcher()
{
}

void RuleMatcher::addRule(const QRegExp &regExp, int tokenId)
{
    Rule *rule = new Rule(Rule::TOKEN_RULE, regExp, tokenId);
    m_rules.addRule(rule);
}

Rule *RuleMatcher::findMatchingRule(const QString &sentence, int sentenceOffset, int &matchCount, QString &unmatchedCharacters)
{
    Rule *rule = findRule(sentence, sentenceOffset, matchCount);

    if (rule)
        return rule;

    // no rule was found to match, eliminate unknown characters and try to match again
    int i = 0;

    while (!rule && sentenceOffset + i <= sentence.length()) {
        ++i;
        rule = findRule(sentence, sentenceOffset + i, matchCount);
    }

    unmatchedCharacters = sentence.mid(sentenceOffset, i);
    matchCount += i;
    return rule;
}

void RuleMatcher::setStringDelimiters(const QStringList &delimiters)
{
    foreach (const QString &delimiter, delimiters) {
        Rule *rule = new Rule(Rule::DELIMITER_RULE, QRegExp(delimiter + QLatin1String("+")), -1);
        m_rules.addDelimiter(rule);
    }
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

} // namespace Internal
} // namespace QTokenizer
