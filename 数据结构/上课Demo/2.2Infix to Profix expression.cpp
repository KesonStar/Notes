#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    char *arr;
    int topIndex;
    int capacity;

public:
    Stack() : Stack(10) {}
    Stack(int capacity)
    {
        this->capacity = capacity;
        arr = new char[capacity];
        topIndex = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return topIndex == -1;
    }

    bool isFull()
    {
        return topIndex == capacity - 1;
    }

    void push(char c)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
            return;
        }
        topIndex++;
        arr[topIndex] = c;
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        char c = arr[topIndex];
        topIndex--;
        return c;
    }

    char top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        return arr[topIndex];
    }
};

class ExpressionConverter
{
private:
    Stack operators;
    string postfix;

    int precedence(char op)
    {
        if (op == '+' || op == '-')
        {
            return 1;
        }
        if (op == '*' || op == '/')
        {
            return 2;
        }
        return 0;
    }

    void processOperator(char op)
    {
        while (!operators.isEmpty() && precedence(operators.top()) >= precedence(op))
        {
            postfix += operators.pop();
        }
        operators.push(op);
    }

    void processRightParenthesis()
    {
        while (operators.top() != '(')
        {
            postfix += operators.pop();
        }
        operators.pop();
    }

public:
    ExpressionConverter() = default;
    string convertToPostfix(string infix)
    {
        postfix = "";
        for (int i = 0; i < infix.length(); i++)
        {
            char ch = infix[i];
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                processOperator(ch);
            }
            else if (ch == '(')
            {
                operators.push(ch);
            }
            else if (ch == ')')
            {
                processRightParenthesis();
            }
            else
            {
                postfix += ch;
            }
        }
        while (!operators.isEmpty())
        {
            postfix += operators.pop();
        }
        return postfix;
    }
};

int main()
{
    ExpressionConverter converter{};
    string infix = "p*q+(r*s+t)*u";
    string postfix = converter.convertToPostfix(infix);
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    return 0;
}
