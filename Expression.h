//
// Created by gil on 18/12/18.
//

#include <cmath>

#ifndef EX3_EXPRESSION_H
#define EX3_EXPRESSION_H

class Expression {
public:
    virtual double calculate() = 0;
};


class UnaryExpression : public  Expression{
private:
    double number;
public:
    UnaryExpression(double number) : number(number) {}
    virtual double calculate(){
        return this->number;
    }
};

class BinaryExpression : public Expression{
protected:
    Expression* left;
    Expression* right;
public:
    virtual double calculate() = 0;
    BinaryExpression(Expression *left, Expression *right) : left(left), right(right) {}

    BinaryExpression() {}
};

class Plus : public BinaryExpression{

public:
    Plus(Expression *left, Expression *right) {
        this->left = left;
        this->right = right;
    }

public:
    virtual double calculate() {

        return this->left->calculate() + this->right->calculate();
    }
};

class Minus : public BinaryExpression{
public:
    Minus(Expression *left, Expression *right) : BinaryExpression(left, right) {
        this->left = left;
        this->right = right;
    }

public:
    virtual double calculate(){
        return this->left->calculate() - this->right->calculate();
    }
};

class Multiplication : public BinaryExpression{
public:
    Multiplication(Expression *left, Expression *right) : BinaryExpression(left, right) {
        this->left = left;
        this->right = right;
    }

    virtual double calculate(){
        return this->left->calculate() * this->right->calculate();
    }
};

class Division : public BinaryExpression{
public:
    Division(Expression *left, Expression *right) : BinaryExpression(left, right) {
        this->left = left;
        this->right = right;

    }

    virtual double calculate(){
        if(this->right==0){
            exit(0);
        }
        return this->left->calculate() / this->right->calculate();
    }
};

#endif //EX3_EXPRESSION_H