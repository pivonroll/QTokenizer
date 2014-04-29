#ifndef QTOKENIZER_INTERNAL_RULE_H
#define QTOKENIZER_INTERNAL_RULE_H

#include <QRegExp>

namespace QTokenizer {
namespace Internal {

class Rule
{
public:
    enum RuleType {
        TOKEN_RULE,
        DELIMITER_RULE
    };

    Rule(RuleType ruleType, const QRegExp &regExpr, int tokenId);

    RuleType type() const;
    int tokenId() const;
    int match(const QString &sentence, int sentenceOffset, int &matchCount);
    QRegExp rule() const;
    QString matchedString() const;

private:
    QRegExp m_regExpresion;
    int m_tokenId;
    QString m_matchedString;
    RuleType m_ruleType;
};

} // namespace Internal
} // namespace QTokenizer

#endif // QTOKENIZER_INTERNAL_RULE_H
