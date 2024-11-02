CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRC = src
BUILD = build

all: $(BUILD)/main

$(BUILD)/main: $(SRC)/main.cpp $(SRC)/Lexer.cpp $(SRC)/Parser.cpp $(SRC)/Translator.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(BUILD)/*
