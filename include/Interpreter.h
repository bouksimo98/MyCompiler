#include <memory>
#include "Parser.h"

class Interpreter {
public:
    int visit(std::unique_ptr<ASTNode>& node);
};
