#include <iostream>
#include <vector>
#include <string>
#include <regex>

// Token Types
enum class TokenType { NUMBER, PLUS, MINUS, MUL, DIV, LPAREN, RPAREN, END };

// Token Class
struct Token {
    TokenType type;
    std::string value;

    Token(TokenType type, const std::string& value) : type(type), value(value) {}
};

// Lexer Class
class Lexer {
public:
    Lexer(const std::string& text) : text(text), pos(0) {}

    std::vector<Token> tokenize();
private:
    std::string text;
    size_t pos;

    std::string readNumber();
};
