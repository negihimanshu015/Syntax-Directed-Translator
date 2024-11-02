#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "Parser.h"
#include <string>
#include <sstream>

class Translator {
public:
    explicit Translator(Parser &parser);
    std::string toPostfix();

private:
    Parser &parser;
    
    void generatePostfix(double result, std::ostringstream &output);
};

#endif 
