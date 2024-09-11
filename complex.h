#include <iostream>
using namespace std;


#ifndef OOP_PRACTICE_2_COMPLEX_H
#define OOP_PRACTICE_2_COMPLEX_H


class TComplex{
    double re;
    TComplex im;

public:
    TComplex();

    double getRe();

    double getIm();

    void operator +(TComplex second);

    void operator -(TComplex second);

    void operator /(TComplex second);

    void operator *(TComplex second);

    friend istream& operator >> (istream & in, const TComplex & c);
    friend ostream& operator << (ostream & os, const TComplex & c);
};


#endif //OOP_PRACTICE_2_COMPLEX_H
