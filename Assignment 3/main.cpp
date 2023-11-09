#include "ExpressionManager.h"
#include "Queue.h"
#include <iostream>

int main() {
    // Create instances of ExpressionManager and Queue
    ExpressionManager expManager;
    Queue<int> q; // You can change the itemType to string, char, and double
    string expression;

    // Main program loop
    while (true) {
        // Display menu options
        cout << "Menu:" << endl;
        cout << "1. Enter an infix expression and convert to postfix" << endl;
        cout << "2. Check for balanced parentheses in an expression" << endl;
        cout << "3. Enqueue an element in the queue" << endl;
        cout << "4. Dequeue an element from the queue" << endl;
        cout << "5. Get the front element of the queue" << endl;
        cout << "6. Get the size of the queue" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice (1-7): ";

        // User input for menu choice
        int choice;
        cin >> choice;

        // Switch statement to handle menu choices
        switch (choice) {
        case 1:
            // Option to convert infix expression to postfix
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
            // Option to check for balanced parentheses in an expression
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
            // Option to enqueue an element in the queue
            int element;
            cout << "Enter an element to enqueue: ";
            cin >> element;
            q.enqueue(element);
            break;
        case 4:
            // Option to dequeue an element from the queue
            if (!q.isEmpty()) {
                cout << "Dequeue: " << q.dequeue() << endl;
            }
            else {
                cout << "Queue is empty. Cannot dequeue." << endl;
            }
            break;
        case 5:
            // Option to get the front element of the queue
            if (!q.isEmpty()) {
                cout << "Front element: " << q.top() << endl;
            }
            else {
                cout << "Queue is empty. No front element." << endl;
            }
            break;
        case 6:
            // Option to get the size of the queue
            cout << "Queue size: " << q.size() << endl;
            break;
        case 7:
            // Exit the program
            cout << "Exiting the program." << endl;
            return 0;
        default:
            // Handle invalid input
            if (cin.fail()) {
                cout << "Invalid input. Please enter a number on the menu.\n" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the error state and ignore invalid characters
                break; // Exit this case
            }
        }
    }

    return 0;
}
