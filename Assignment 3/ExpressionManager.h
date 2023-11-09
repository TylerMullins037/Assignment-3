#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H
using namespace std;
#include <string>
#include <stack>

// Declaration of the ExpressionManager class
class ExpressionManager {
public:
    // Constructor for the ExpressionManager class
    ExpressionManager();

    // Check if the parentheses in the expression are balanced
    bool isBalanced(const string& expression);

    // Convert infix expression to postfix
    string infixToPostfix(const string& expression);

private:
    // Private utility function to check if a character is an operator
    bool isOperator(char ch);

    // Private utility function to get the precedence of an operator
    int getPrecedence(char op);
};


#endif
