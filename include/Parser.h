#include <memory>
#include "Lexer.h"

struct ASTNode {
    virtual ~ASTNode() = default;
};

struct NumberNode : ASTNode {
    int value;

    NumberNode(int value) : value(value) {}
};

struct BinOpNode : ASTNode {
    std::unique_ptr<ASTNode> left;
    TokenType op;
    std::unique_ptr<ASTNode> right;

    BinOpNode(std::unique_ptr<ASTNode> left, TokenType op, std::unique_ptr<ASTNode> right)
        : left(std::move(left)), op(op), right(std::move(right)) {}
};

class Parser {
public:
    Parser(const std::vector<Token>& tokens) : tokens(tokens), pos(0) {}

    std::unique_ptr<ASTNode> parse();

private:
    std::vector<Token> tokens;
    size_t pos;

    Token currentToken();

    void eat(TokenType type);

    std::unique_ptr<ASTNode> parseFactor();
    std::unique_ptr<ASTNode> parseTerm();
    std::unique_ptr<ASTNode> parseExpression();
};


