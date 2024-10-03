#include "Lexer.h"

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (pos < text.length()) {
        char current_char = text[pos];

        if (isdigit(current_char)) {
            tokens.push_back(Token(TokenType::NUMBER, readNumber()));
        } 
        else if (current_char == '+') {
            tokens.push_back(Token(TokenType::PLUS, "+"));
            pos++;
        } 
        else if (current_char == '-') {
            tokens.push_back(Token(TokenType::MINUS, "-"));
            pos++;
        } 
        else if (current_char == '*') {
            tokens.push_back(Token(TokenType::MUL, "*"));
            pos++;
        } 
        else if (current_char == '/') {
            tokens.push_back(Token(TokenType::DIV, "/"));
            pos++;
        } 
        else if (current_char == '(') {
            tokens.push_back(Token(TokenType::LPAREN, "("));
            pos++;
        } 
        else if (current_char == ')') {
            tokens.push_back(Token(TokenType::RPAREN, ")"));
            pos++;
        } 
        else if (isspace(current_char)) {
            pos++;
        } 
        else {
            throw std::runtime_error("Unknown character: " + std::string(1, current_char));
        }
    }
    tokens.push_back(Token(TokenType::END, ""));
    return tokens;
}

std::string Lexer::readNumber() {
    std::string result;
    while (pos < text.length() && isdigit(text[pos])) {
        result += text[pos];
        pos++;
    }
    return result;
}
