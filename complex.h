#include <iostream>
using namespace std;


#ifndef OOP_PRACTICE_2_COMPLEX_H
#define OOP_PRACTICE_2_COMPLEX_H


class TComplex{
    double re;
    double im;

public:

    TComplex();

    TComplex(double a, double b);

    double getRe();

    double getIm();

    TComplex operator+(TComplex second);

    TComplex operator-(TComplex second);

    TComplex operator/(TComplex second);

    TComplex operator*(TComplex second);

    TComplex operator+=(TComplex second);

    TComplex operator-=(TComplex second);

    TComplex operator/=(TComplex second);

    TComplex operator*=(TComplex second);

    TComplex operator+=(double second);

    TComplex operator/=(double second);

    bool operator==(TComplex second);

    bool operator!=(TComplex second);

    bool operator<(TComplex second);

    bool operator>(TComplex second);



    friend istream& operator >> (istream & in, TComplex & c);
    friend ostream& operator << (ostream & os, const TComplex & c);
};


#endif //OOP_PRACTICE_2_COMPLEX_H
