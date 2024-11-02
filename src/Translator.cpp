#include "Translator.h"

Translator::Translator(Parser &parser) : parser(parser) {}

std::string Translator::toPostfix() {
    std::ostringstream output;
    double result = parser.parseExpression();  // Parse the expression
    generatePostfix(result, output);           // Generate postfix from parsed result
    return output.str();
}

// Recursive helper function to generate postfix from parsed result
void Translator::generatePostfix(double result, std::ostringstream &output) {
    output << result << " ";
}
