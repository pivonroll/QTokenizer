#include <QCoreApplication>

#include <tokenizer.h>
#include <token.h>
#include <QStringList>
#include <QDebug>

enum TokenId
{
    LETTERS = 1,
    NUMBER,
    SPACE,
    TABS,
    DOLLAR
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTokenizer::Internal::Tokenizer tokenizer;
    tokenizer.addRule(QRegExp("\\$"), DOLLAR);
    tokenizer.addRule(QRegExp("\\d+"), NUMBER);
    tokenizer.addRule(QRegExp("[a-zA-Z]+"), LETTERS);

    QStringList sl;
    sl << "\\s";

    tokenizer.setDelimiters(sl);
    tokenizer.setSentence(" $ <<<!!>>>> 23232 RADE Buca\t<<<");

    QTokenizer::Internal::Token *token = 0;

    while (int match = tokenizer.match(token)) {
        if (match == QTokenizer::Internal::Tokenizer::MATCH) {
            if (token) {
                if (token->id() == LETTERS)
                    qDebug() << "Word found" << token->matchedText();
                else if (token->id() == NUMBER)
                    qDebug() << "Number found" << token->matchedText();
                else if (token->id() == SPACE)
                    qDebug() << "Space found" << token->matchedText();
                else if (token->id() == TABS)
                    qDebug() << "Tabs found" << token->matchedText();
                else if (token->id() == DOLLAR)
                    qDebug() << "DOLLAR found" << token->matchedText();
                delete token;
                token = 0;
            }
        }
        else if (match == QTokenizer::Internal::Tokenizer::DELIMITER) {
            if (token)
                qDebug() << "DELIMITER found " << token->matchedText();
            else
                qDebug() << "DELIMITER found";
        }
        else if (match == QTokenizer::Internal::Tokenizer::UNMATCHED_CHARS_FOUND){
            if (token)
                qDebug() << "unknown found " << token->matchedText();
            else
                qDebug() << "unknown found";
        }
    }

    qDebug() << "THE END!";

    a.exec();
}
