#include "Parser.h"
#include <stdexcept>

Parser::Parser(Lexer &lexer) : lexer(lexer) {
    currentToken = lexer.getNextToken();
}

void Parser::eat(TokenType type) {
    if (currentToken.type == type) {
        currentToken = lexer.getNextToken();
    } else {
        throw std::runtime_error("Unexpected token");
    }
}

double Parser::factor() {
    Token token = currentToken;
    if (token.type == TokenType::NUMBER) {
        eat(TokenType::NUMBER);
        return std::stod(token.value);
    } else if (token.type == TokenType::LPAREN) {
        eat(TokenType::LPAREN);
        double result = expression();
        eat(TokenType::RPAREN);
        return result;
    }
    throw std::runtime_error("Invalid factor");
}

double Parser::term() {
    double result = factor();
    while (currentToken.type == TokenType::MULTIPLY || currentToken.type == TokenType::DIVIDE) {
        if (currentToken.type == TokenType::MULTIPLY) {
            eat(TokenType::MULTIPLY);
            result *= factor();
        } else if (currentToken.type == TokenType::DIVIDE) {
            eat(TokenType::DIVIDE);
            result /= factor();
        }
    }
    return result;
}

double Parser::expression() {
    double result = term();
    while (currentToken.type == TokenType::PLUS || currentToken.type == TokenType::MINUS) {
        if (currentToken.type == TokenType::PLUS) {
            eat(TokenType::PLUS);
            result += term();
        } else if (currentToken.type == TokenType::MINUS) {
            eat(TokenType::MINUS);
            result -= term();
        }
    }
    return result;
}

double Parser::parseExpression() {
    return expression();
}
