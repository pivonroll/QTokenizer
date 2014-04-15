#ifndef QTOKENIZER_INTERNAL_TOKENIZER_H
#define QTOKENIZER_INTERNAL_TOKENIZER_H

#include <QString>

namespace QTokenizer {
namespace Internal {

class RuleMatcher;

class Tokenizer
{
public:
    enum MatchResult
    {
        NO_MATCH,   // neither rules match
        MATCH       // found a matching rule
    };

    Tokenizer();

    void addRule(const QRegExp &regExp, int tokenId);
    QString getSentence() const;
    void setSentence(const QString &sentence);
    MatchResult match(int &tokenId);

    void setDelimiters(const QStringList &delimiters);

private:
    QString m_sentence;
    RuleMatcher m_ruleMatcher;

    int m_sentenceMatchOffset;
    MatchResult m_previousMatch;
};

} // namespace Internal
} // namespace QTokenizer

#endif // QTOKENIZER_INTERNAL_TOKENIZER_H
