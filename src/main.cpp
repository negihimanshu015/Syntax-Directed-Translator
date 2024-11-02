#include "Lexer.h"
#include "Parser.h"
#include "Translator.h"
#include <iostream>

int main() {
    std::string input;
    std::cout << "Enter an arithmetic expression: ";
    std::getline(std::cin, input);

    Lexer lexer(input);
    Parser parser(lexer);
    Translator translator(parser);

    try {
        std::cout << "Postfix notation: " << translator.toPostfix() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
