#ifndef QTOKENIZER_INTERNAL_TOKEN_H
#define QTOKENIZER_INTERNAL_TOKEN_H

#include <QString>
#include "tokenizer_global.h"

namespace QTokenizer {
namespace Internal {

class QTOKENIZER_EXPORT Token
{
    friend class Tokenizer;
public:
    Token(int tokenId, const QString &matchedText);

    int id() const;
    QString matchedText() const;

private:
    int m_id;
    QString m_matchedText;
};

} // namespace Internal
} // namespace QTokenizer

#endif // QTOKENIZER_INTERNAL_TOKEN_H
