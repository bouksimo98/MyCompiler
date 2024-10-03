#include "Interpreter.h"

int Interpreter::visit(std::unique_ptr<ASTNode>& node) {
    if (auto numberNode = dynamic_cast<NumberNode*>(node.get())) {
        return numberNode->value;
    }

    if (auto binOpNode = dynamic_cast<BinOpNode*>(node.get())) {
        int leftValue = visit(binOpNode->left);
        int rightValue = visit(binOpNode->right);

        switch (binOpNode->op) {
            case TokenType::PLUS:
                return leftValue + rightValue;
            case TokenType::MINUS:
                return leftValue - rightValue;
            case TokenType::MUL:
                return leftValue * rightValue;
            case TokenType::DIV:
                return leftValue / rightValue;
            default:
                throw std::runtime_error("Unknown binary operator");
        }
    }

    throw std::runtime_error("Unknown node type");
}