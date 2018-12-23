//
// Created by gil on 18/12/18.
//

#include <iostream>
#include "ShuntingYardAlgo.h"
// CPP program to evaluate a given
// expression where tokens are
// separated by space.

//TODO ( )  >= <= == != > <


ShuntingYard::ShuntingYard() {
    initializeMap();
}

void ShuntingYard::initializeMap() {
    this->precedences.insert(pair<char,int>('/',2));
    this->precedences.insert(pair<char, int>('*',2));
    this->precedences.insert(pair<char,int >('+',1));
    this->precedences.insert(pair<char,int >('-',1));
    this->precedences.insert(pair<char,int >('(',0));
    this->precedences.insert(pair<char,int >(')',0));
}

// Function to find precedence of
// operators.
double precedence(char op) {
    if (op == '(' || op == ')')
        return 1.;
    if (op == '+' || op == '-')
        return 2.;
    if (op == '*' || op == '/')
        return 3;
    return 0;
}

int ShuntingYard::precedence(char operation) {
    if (this->precedences.count(operation)) {
        return this->precedences.at(operation);
    }
    throw "invalid operation!";
}

// Function to perform arithmetic operations.
Expression* ShuntingYard::applyOp(Expression *left, Expression *right, char operation) {
//    BinaryExpression *binaryExpression;
//    binaryExpression = new BinaryExpression(left, right);

    switch (operation) {
        case '+':
            Plus *plus = new  Plus;
//            Expression *plus = new Plus(left,right);
            //Plus plus1 = new Plus(left,right);
            plus->calculate();
            return plus;
        case '-':
            Minus *minus1 = new  Minus;
            minus1->calculate();
            return minus1;
        case '*':
            Multiplication *multiplication = new  Multiplication;
            multiplication->calculate();
            return multiplication;
        case '/':
            Division *division = new  Division;
            division->calculate();
            return  division;
    }

}

// Function that returns value of
// expression after evaluation.
Expression* evaluate(string tokens) {
    double i;

    // stack to store integer values.
    stack <int> values;
//        queue<Expression> queue1;

    // stack to store operators.
    stack<char> ops;

    for (i = 0; i < tokens.length(); i++) {

        // Current token is a whitespace, skip it.
        if (tokens[i] == ' ')
            continue;

            // Current token is an opening brace, push it to 'ops'
        else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }

            // Current token is a number, push it to stack for numbers.
        else if (isdigit(tokens[i])) {
            int val = 0;

            // There may be more than one
            // digits in number.
            while (i < tokens.length() &&
                   isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }

            values.push(val);
        }

            // Closing brace encountered, solve
            // entire brace.
        else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // pop opening brace.
            ops.pop();
        }

            // Current token is an operator.
        else {
            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
            while (!ops.empty() && precedence(ops.top())
                                   >= precedence(tokens[i])) {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // Push current token to 'ops'.
            ops.push(tokens[i]);
        }
    }

    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while (!ops.empty()) {
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    // Top of 'values' contains result, return it.
    return values.top();
}

int main() {
    cout << evaluate("10 + 2 * 6") << "\n";
    cout << evaluate("100 * 2 + 12") << "\n";
    cout << evaluate("100 * ( 2 + 12 )") << "\n";
    cout << evaluate("100 * ( 2 + 12 ) / 14");
    return 0;
}

