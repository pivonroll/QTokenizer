#include <QCoreApplication>

#include <tokenizer.h>
#include <token.h>
#include <QStringList>
#include <QDebug>

enum TokenId
{
    LETTERS,
    NUMBER,
    SPACE,
    TABS
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTokenizer::Internal::Tokenizer tokenizer;
    tokenizer.addRule(QRegExp("\\t+"), TABS);
    tokenizer.addRule(QRegExp("\\s+"), SPACE);
    tokenizer.addRule(QRegExp("\\d+"), NUMBER);
    tokenizer.addRule(QRegExp("[a-zA-Z]+"), LETTERS);

    QStringList sl;
    sl << "\t";

    tokenizer.setDelimiters(sl);
    tokenizer.setSentence("23232 RADE Buca\t");

    QTokenizer::Internal::Token *token = 0;

    while (int match = tokenizer.match(token)) {
        if (token) {
            if (token->id() == LETTERS)
                qDebug() << "Word found" << token->matchedText();
            else if (token->id() == NUMBER)
                qDebug() << "Number found" << token->matchedText();
            else if (token->id() == SPACE)
                qDebug() << "Space found" << token->matchedText();
            else if (token->id() == TABS)
                qDebug() << "Tabs found" << token->matchedText();
            delete token;
            token = 0;
        }
        else if (match == QTokenizer::Internal::Tokenizer::DELIMITER)
            qDebug() << "DELIMITER found";
        else
            qDebug() << "unknown found";
    }

    a.exec();
}
