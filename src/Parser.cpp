#include "Parser.h"

std::unique_ptr<ASTNode> Parser::parse() {
    return parseExpression();
}


Token Parser::currentToken() {
    return tokens[pos];
}

void Parser::eat(TokenType type) {
    if (currentToken().type == type) {
        pos++;
    } else {
        throw std::runtime_error("Unexpected token: " + currentToken().value);
    }
}

std::unique_ptr<ASTNode> Parser::parseFactor() {
    Token token = currentToken();

    if (token.type == TokenType::NUMBER) {
        eat(TokenType::NUMBER);
        return std::make_unique<NumberNode>(std::stoi(token.value));
    } else if (token.type == TokenType::LPAREN) {
        eat(TokenType::LPAREN);
        std::unique_ptr<ASTNode> node = parseExpression();
        eat(TokenType::RPAREN);
        return node;
    }

    throw std::runtime_error("Invalid factor");
}

std::unique_ptr<ASTNode> Parser::parseTerm() {
    std::unique_ptr<ASTNode> node = parseFactor();

    while (currentToken().type == TokenType::MUL || currentToken().type == TokenType::DIV) {
        Token token = currentToken();
        if (token.type == TokenType::MUL) {
            eat(TokenType::MUL);
        } else {
            eat(TokenType::DIV);
        }

        node = std::make_unique<BinOpNode>(std::move(node), token.type, parseFactor());
    }

    return std::move(node);
}

std::unique_ptr<ASTNode> Parser::parseExpression() {
    std::unique_ptr<ASTNode> node = parseTerm();

    while (currentToken().type == TokenType::PLUS || currentToken().type == TokenType::MINUS) {
        Token token = currentToken();
        if (token.type == TokenType::PLUS) {
            eat(TokenType::PLUS);
        } else {
            eat(TokenType::MINUS);
        }

        node = std::make_unique<BinOpNode>(std::move(node), token.type, parseTerm());
    }

    return std::move(node);
}


/* Part 1 
Expression  → Term   | Expression + Term | Expression - Term
Term        → Factor | Term * Factor | Term / Factor
Factor      → Number | ( Expression )
Number      → [0-9]+
*/

/* Part 2
StringLiteral → " [^"]* "   // String literal inside double quotes

*/


