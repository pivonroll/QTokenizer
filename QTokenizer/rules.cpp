#include "rules.h"

#include "rule.h"

namespace QTokenizer {
namespace Internal {

Rules::Rules()
    : m_delimiterStart(0)
{
}

int Rules::ruleCount() const
{
    return m_rules.size();
}

Rule *Rules::rule(int index) const
{
    if (0 <= index && index < m_rules.size())
        return m_rules[index];
    return 0;
}

void Rules::addRule(Rule *rule)
{
    m_rules.insert(m_delimiterStart, rule);
    ++m_delimiterStart;
}

void Rules::removeRule(Rule *rule)
{
    m_rules.removeAll(rule);
    --m_delimiterStart;
}

void Rules::addDelimiter(Rule *rule)
{
    m_rules.append(rule);
}

void Rules::removeDelimiter(Rule *rule)
{
    m_rules.removeAll(rule);
}

} // namespace Internal
} // namespace QTokenizer
