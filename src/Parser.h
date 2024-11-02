#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"
#include <memory>

class Parser {
public:
    explicit Parser(Lexer &lexer);
    double parseExpression();

private:
    Lexer &lexer;
    Token currentToken;
    void eat(TokenType type);
    double factor();
    double term();
    double expression();
};

#endif // PARSER_H
