#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H
using namespace std;
#include <string>
#include <stack>

class ExpressionManager {
public:
    ExpressionManager();
    bool isBalanced(const string& expression);
    string infixToPostfix(const string& expression);

private:
    bool isOperator(char ch);
    int getPrecedence(char op);
};

#endif
