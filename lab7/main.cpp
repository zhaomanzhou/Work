#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

#include "base.h"

using namespace std;
double getResult(string exp);
bool legalExpression(string exp);
void lexical(string exp, vector<double >& numVector, vector<char>& opVector);
int main()
{
    string expression;
    cout<<"Please enter an expression: ";
    cin>>expression;
    if(!legalExpression(expression))
        cout<<"Wrong expression"<<endl;
    else
        cout<<getResult(expression)<<endl;
    return 0;
}

bool legalExpression(string exp)
{
    return true;
}

double getResult(string exp)
{
    vector<double > numVector;
    vector<char > opVector;
    Base* left = nullptr;
    Base* right = nullptr;
    Base* root;
    lexical(exp, numVector, opVector);
    int i = 0;
    left = new Op(numVector[i]);
    if(opVector.size() == 0)
        return left->evaluate();

    while (i < opVector.size())
    {
        if(opVector[i] == '*')
        {
            right = new Op(numVector[i + 1]);
            left = new Mult(left, right);
        }

        if(opVector[i] == '/')
        {
            right = new Op(numVector[i + 1]);
            left = new Div(left, right);
        }

        if(opVector[i] == '+')
        {
            right = new Op(numVector[i + 1]);
            while(opVector.size() > i+1 &&  (opVector[i+1] == '*' || opVector[i+1] == '/'))
            {
                ++i;
                if(opVector[i] == '*')
                {
                    Op* newOp = new Op(numVector[i+1]);
                    right = new Mult(right, newOp);
                }

                if(opVector[i] == '/')
                {
                    Op* newOp = new Op(numVector[i+1]);
                    right = new Div(right, newOp);
                }
            }

            left = new Add(left, right);
        }
        if(opVector[i] == '-')
        {
            right = new Op(numVector[i + 1]);
            while(opVector.size() > i+1 &&  (opVector[i+1] == '*' || opVector[i+1] == '/'))
            {
                ++i;
                if(opVector[i] == '*')
                {
                    Op* newOp = new Op(numVector[i+1]);
                    right = new Mult(right, newOp);
                }

                if(opVector[i] == '/')
                {
                    Op* newOp = new Op(numVector[i+1]);
                    right = new Div(right, newOp);
                }
            }

            left = new Sub(left, right);
        }



        ++i;
    }




    return left->evaluate();



}

void lexical(string exp, vector<double >& numVector, vector<char>& opVector)
{
    stringstream ss(exp);
    double x;
    ss>>x;
    numVector.push_back(x);
    char ch;
    while (!ss.eof())
    {
        ss>>ch;
        ss>>x;
        if( x == 0)
        {
            ss.clear();
            ss>>ch;
            ch='^';
            ss>>x;
            x = pow(numVector[numVector.size()-1], x);
            numVector[numVector.size()-1] = x;
            if(ss.eof())
                return;
            ss>>ch;
            ss>>x;
        }
        opVector.push_back(ch);
        numVector.push_back(x);
    }
}
