#ifndef QTOKENIZER_INTERNAL_RULE_H
#define QTOKENIZER_INTERNAL_RULE_H

#include <QRegExp>

namespace QTokenizer {
namespace Internal {

class Rule
{
public:
    Rule(const QRegExp &regExpr, int tokenId);

    int tokenId() const;
    void match(const QString &sentence, int &matchPosition, int &matchCount);
    QRegExp rule() const;

private:
    QRegExp m_regExpresion;
    int m_tokenId;
};

} // namespace Internal
} // namespace QTokenizer

#endif // QTOKENIZER_INTERNAL_RULE_H