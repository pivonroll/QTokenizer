#ifndef QTOKENIZER_INTERNAL_TOKENIZER_H
#define QTOKENIZER_INTERNAL_TOKENIZER_H

#include "rulematcher.h"
#include "tokenizer_global.h"

#include <QString>

namespace QTokenizer {
namespace Internal {

class Token;

class QTOKENIZER_EXPORT Tokenizer
{
public:
    enum MatchResult
    {
        NO_MATCH = 0,   // neither rules match
        UNMATCHED_CHARS_FOUND,
        MATCH,       // found a matching rule
        DELIMITER
    };

    Tokenizer();

    void addRule(const QRegExp &regExp, int tokenId);
    QString getSentence() const;
    void setSentence(const QString &sentence);
    MatchResult match(Token *&token);

    void setDelimiters(const QStringList &delimiters);

private:
    QString m_sentence;
    RuleMatcher m_ruleMatcher;

    int m_sentenceMatchOffset;
    MatchResult m_previousMatch;

    Rule *m_savedRule;
};

} // namespace Internal
} // namespace QTokenizer

#endif // QTOKENIZER_INTERNAL_TOKENIZER_H
