/*

 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Node {
    char data;
    struct Node* next;
};

struct Node* tos = nullptr;

bool isEmpty() {
    return (tos == nullptr);
}

void push(char value) {
    struct Node* p = new struct Node;
    p->data = value;
    p->next = tos;
    tos = p;
}

char pop() {
    if (isEmpty()) {
        cout << "Stack is Empty\n";
        return '\0';
    }
    char value = tos->data;
    struct Node* temp = tos;
    tos = tos->next;
    delete temp;
    return value;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

bool isAlphanumeric(char ch) {
    // Check if the character is a letter (uppercase or lowercase) or a digit
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

bool isbalanced(const string& expression) {
    stack<char> stack;
    for (int i = 0; i < expression.length(); ++i) {
        char ch = expression[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.empty()) {
                return false;
            }
            char top = stack.top();

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
            stack.pop(); // Remove the matching opening bracket
        }
    }

    return stack.empty();
}

void infixToPostfix(const string& infix, string& postfix) {
    for (int i = 0; i < infix.length(); ++i) {
        char ch = infix[i];

        if (isAlphanumeric(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (!isEmpty() && tos->data != '(') {
                postfix += pop();
            }
            if (!isEmpty()) {
                pop(); // Remove the '(' from the stack
            } else {
                cout << "Mismatched parentheses\n";
                return;
            }
        }
        else if (isOperator(ch)) {
            while (!isEmpty() && precedence(ch) <= precedence(tos->data)) {
                postfix += pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators from the stack
    while (!isEmpty()) {
        char top = pop();
        if (top == '(') {
            cout << "Mismatched parentheses\n";
            return;
        }
        postfix += top;
    }
}

int evaluate(const string& postfix) {
    stack<int> operandStack;

    for (int i = 0; i < postfix.length(); ++i) {
        char ch = postfix[i];
        if (isAlphanumeric(ch)) {
            operandStack.push(ch - '0'); // Convert char to int and push to stack
        } else if (isOperator(ch)) {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            // Perform arithmetic operation based on the operator
            switch (ch) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0)
                        operandStack.push(operand1 / operand2);
                    else {
                        cout << "Error: Division by zero\n";
                        return 0;
                    }
                    break;
            }
        }
    }

    if (!operandStack.empty()) {
        return operandStack.top();
    } else {
        cout << "Error: Invalid postfix expression\n";
        return 0;
    }
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (!isbalanced(expression)) {
        cout << "Expression is not balanced\n";
        return 0;
    }

    string postfixExpression;
    infixToPostfix(expression, postfixExpression);

    cout << "Postfix expression: " << postfixExpression << endl;

    int result = evaluate(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}














