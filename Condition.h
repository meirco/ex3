//
// Created by gil on 18/12/18.
//

#include "Expression.h"

#ifndef EX3_CONDITION_H
#define EX3_CONDITION_H

#endif //EX3_CONDITION_H

class Condition {
public:
    virtual bool evaluate() =0;
};

class CompareCondition : public Condition {
protected:
    Expression *left;
    Expression *right;
public:
    CompareCondition(Expression *left1, Expression *right1) : left(left1), right(right1) {}
    CompareCondition() {}

    virtual bool evaluate() =0;
};

class OperatorSmall : public CompareCondition{
public:
    bool evaluate(){
        return this->left > this->right;
    }
};

class OperatorBig : public CompareCondition{
public:
    bool evaluate(){
        return this->left < this->right;
    }
};

class OperatorSmallEqual : public CompareCondition{
public:
    bool evaluate(){
        return this->left <= this->right;
    }
};

class OperatorBigEqual : public CompareCondition{
public:
    bool evaluate(){
        return this->left >= this->right;
    }
};

class OperatorNotEqual : public CompareCondition{
public:
    bool evaluate(){
        return this->left != this->right;
    }
};

class OperatorEqual : public CompareCondition{
public:
    bool evaluate(){
        return this->left == this->right;
    }
};

// ()
//|
//&