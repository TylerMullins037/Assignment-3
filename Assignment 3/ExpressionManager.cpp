#include "ExpressionManager.h"
#include <stack>
#include <iostream>

ExpressionManager::ExpressionManager() {}

bool ExpressionManager::isBalanced(const string& expression) {
    stack<char> stack;

    for (char ch : expression) {
        if (ch == '{' || ch == '[' || ch == '(') {
            stack.push(ch);
        }
        else if (ch == '}' || ch == ']' || ch == ')') {
            if (stack.empty()) {
                return false;
            }
            char top = stack.top();
            stack.pop();
            if ((ch == '}' && top != '{') || (ch == ']' && top != '[') || (ch == ')' && top != '(')) {
                return false;
            }
        }
    }

    return stack.empty();
}

bool ExpressionManager::isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%';
}

int ExpressionManager::getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;  // Lower precedence for addition and subtraction
    }
    else if (op == '*' || op == '/' || op == '%') {
        return 2;  // Higher precedence for multiplication, division, and modulus
    }
    else {
        return 0;  // Default precedence for other characters
    }
}

string ExpressionManager::infixToPostfix(const string& expression) {
    stack<char> operators;
    string postfix = "";

    for (char ch : expression) {
        if (ch == ' ' || ch == '\t') {
            continue;  // Ignore spaces and tabs
        }
        else if (ch == '{' || ch == '[' || ch == '(') {
            operators.push(ch);
        }
        else if (ch == '}' || ch == ']' || ch == ')') {
            while (!operators.empty() && operators.top() != '{' && operators.top() != '[' && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();  // Remove the opening parenthesis
        }
        else if (isOperator(ch)) {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
        else {
            postfix += ch;  // Add operands to the postfix expression
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}
