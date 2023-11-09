#include "ExpressionManager.h"
#include "Queue.h"
#include <iostream>

int main() {
    ExpressionManager expManager;
    Queue q;
    string expression;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Enter an infix expression and convert to postfix" << endl;
        cout << "2. Check for balanced parentheses in an expression" << endl;
        cout << "3. Enqueue an element in the queue" << endl;
        cout << "4. Dequeue an element from the queue" << endl;
        cout << "5. Get the front element of the queue" << endl;
        cout << "6. Get the size of the queue" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice (1-7): ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter an infix expression: ";
            cin >> expression;
            if (!expManager.isBalanced(expression)) {
                cout << "Invalid expression. Unbalanced parentheses!" << endl;
            }
            else {
                string postfixExpression = expManager.infixToPostfix(expression);
                cout << "Postfix expression: " << postfixExpression << endl;
            }
            break;
        case 2:
            cout << "Enter an expression to check for balanced parentheses: ";
            cin >> expression;
            if (expManager.isBalanced(expression)) {
                cout << "The expression has balanced parentheses." << endl;
            }
            else {
                cout << "Invalid expression. Unbalanced parentheses!" << endl;
            }
            break;
        case 3:
            int element;
            cout << "Enter an element to enqueue: ";
            cin >> element;
            q.enqueue(element);
            break;
        case 4:
            if (!q.isEmpty()) {
                cout << "Dequeue: " << q.dequeue() << endl;
            }
            else {
                cout << "Queue is empty. Cannot dequeue." << endl;
            }
            break;
        case 5:
            if (!q.isEmpty()) {
                cout << "Front element: " << q.frontElement() << endl;
            }
            else {
                cout << "Queue is empty. No front element." << endl;
            }
            break;
        case 6:
            cout << "Queue size: " << q.size() << endl;
            break;
        case 7:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please select a valid option (1-7)." << endl;
            break;
        }
    }

    return 0;
}

