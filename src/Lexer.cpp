#include "Lexer.h"
#include <cctype>
#include <stdexcept>

Lexer::Lexer(const std::string &expression) : expression(expression), pos(0) {
    currentChar = expression[pos];
}

void Lexer::advance() {
    pos++;
    currentChar = (pos < expression.length()) ? expression[pos] : '\0';
}

Token Lexer::getNextToken() {
    while (currentChar != '\0') {
        if (isspace(currentChar)) {
            advance();
            continue;
        }
        
        if (isdigit(currentChar)) {
            return number();
        }

        if (currentChar == '+') {
            advance();
            return { TokenType::PLUS, "+" };
        }

        if (currentChar == '-') {
            advance();
            return { TokenType::MINUS, "-" };
        }

        if (currentChar == '*') {
            advance();
            return { TokenType::MULTIPLY, "*" };
        }

        if (currentChar == '/') {
            advance();
            return { TokenType::DIVIDE, "/" };
        }

        if (currentChar == '(') {
            advance();
            return { TokenType::LPAREN, "(" };
        }

        if (currentChar == ')') {
            advance();
            return { TokenType::RPAREN, ")" };
        }

        throw std::runtime_error("Invalid character in expression");
    }

    return { TokenType::END, "" };
}

Token Lexer::number() {
    std::string value;
    while (currentChar != '\0' && isdigit(currentChar)) {
        value += currentChar;
        advance();
    }
    return { TokenType::NUMBER, value };
}
