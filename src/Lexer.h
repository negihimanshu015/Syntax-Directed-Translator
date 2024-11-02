#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include <cstddef>

enum class TokenType { NUMBER, PLUS, MINUS, MULTIPLY, DIVIDE, LPAREN, RPAREN, END, INVALID };

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    explicit Lexer(const std::string &expression);
    Token getNextToken();

private:
    std::string expression;
    std::size_t pos;
    char currentChar;
    void advance();
    Token number();
};

#endif // LEXER_H
