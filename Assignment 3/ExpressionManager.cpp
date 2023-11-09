#include "ExpressionManager.h"
#include <stack>
#include <iostream>

// Default constructor
ExpressionManager::ExpressionManager() {}

// Check if the parentheses in the expression are balanced
bool ExpressionManager::isBalanced(const string& expression) {
    stack<char> stack;

    for (char ch : expression) {
        // If the character is an opening parenthesis, push it onto the stack
        if (ch == '{' || ch == '[' || ch == '(') {
            stack.push(ch);
        }
        // If the character is a closing parenthesis
        else if (ch == '}' || ch == ']' || ch == ')') {
            // If the stack is empty, or the top of the stack doesn't match the corresponding opening parenthesis
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

    // If the stack is empty, the parentheses are balanced
    return stack.empty();
}

// Check if a character is an operator
bool ExpressionManager::isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%';
}

// Get the precedence of an operator
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

// Convert infix expression to postfix
string ExpressionManager::infixToPostfix(const string& expression) {
    stack<char> operators;
    string postfix = "";

    for (char ch : expression) {
        // Ignore spaces and tabs
        if (ch == ' ' || ch == '\t') {
            continue;
        }
        // If the character is an opening parenthesis, push it onto the operator stack
        else if (ch == '{' || ch == '[' || ch == '(') {
            operators.push(ch);
        }
        // If the character is a closing parenthesis
        else if (ch == '}' || ch == ']' || ch == ')') {
            // Pop and append operators from the stack until an opening parenthesis is encountered
            while (!operators.empty() && operators.top() != '{' && operators.top() != '[' && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();  // Remove the opening parenthesis
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            // Pop and append operators from the stack with higher or equal precedence
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            // Push the current operator onto the stack
            operators.push(ch);
        }
        else {
            postfix += ch;  // Add operands to the postfix expression
        }
    }

    // Pop and append any remaining operators from the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    // Return the final postfix expression
    return postfix;
}
