#include "Interpreter.h"


int main() {
    std::string input = "3 + 5 * (10 - 4)";

    // Lexical Analysis
    Lexer lexer(input);
    std::vector<Token> tokens = lexer.tokenize();

    // Syntax Analysis (Parsing)
    Parser parser(tokens);
    std::unique_ptr<ASTNode> ast = parser.parse();

    // AST Evaluation (Interpreting)
    Interpreter interpreter;
    int result = interpreter.visit(ast);

    std::cout << "Result: " << result << std::endl;

    return 0;
}

/* 
Expression → Term | Expression + Term | Expression - Term
Term → Factor | Term * Factor | Term / Factor
Factor → Number | ( Expression )
Number → [0-9]+
*/