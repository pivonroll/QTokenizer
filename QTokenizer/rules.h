#ifndef QTOKENIZER_INTERNAL_RULES_H
#define QTOKENIZER_INTERNAL_RULES_H

#include <QList>

namespace QTokenizer {
namespace Internal {

class Rule;

class Rules
{
public:
    Rules();
    int ruleCount() const;
    Rule *rule(int index) const;
    void addRule(Rule *rule);
    void removeRule(Rule *rule);

private:
    QList<Rule *> m_rules;
};

} // namespace Internal
} // namespace QTokenizer

#endif // QTOKENIZER_INTERNAL_RULES_H
