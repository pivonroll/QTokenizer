#include "rules.h"

#include "rule.h"

namespace QTokenizer {
namespace Internal {

Rules::Rules()
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

bool Rules::addRule(Rule *rule)
{
    m_rules.append(rule);
}

void Rules::removeRule(Rule *rule)
{
    m_rules.removeAll(rule);
}

} // namespace Internal
} // namespace QTokenizer
