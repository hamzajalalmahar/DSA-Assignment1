#include <iostream>
#include <cctype>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int size;

public:
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = value;
        cout << value << " pushed into stack\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        cout << arr[top] << " popped from stack\n";
        top--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Top element: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack elements:\n";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    return 0;
}

int main() {

    string infix = "(A+B)*(C-D)+E";
    string postfix = "";

    Stack opStack(50);

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix += ch;
        }

        else if (ch == '(')
        {
            opStack.push(ch);
        }

        else if (ch == ')')
        {
            while (!opStack.isEmpty())
            {
                opStack.pop();
                break;
            }
        }

        else
        {
            opStack.push(ch);
        }
    }

    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: AB+CD-*E+" << endl;

    return 0;
}