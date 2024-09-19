#include "complex.h"
#include "number.h"
#include <iostream>

using namespace std;

//Constructors
TComplex::TComplex() {
    re = im = 0;
}


TComplex::TComplex(double re) {
    this->re = re;
    im = 0;
}


TComplex::TComplex(double re, double im){
    this->re = re; this->im = im;
}

//Methods
double TComplex::getRe(){
    return this->re;
}


double TComplex::getIm(){
    return this->im;
}


double TComplex::module(TComplex &complex) {
    double a = std::pow(complex.getRe(),2);
    double b = std::pow(complex.getIm(), 2);
    return std::pow(a + b, 0.5);
}


TComplex TComplex::pow(TComplex complex, double n){
    return std::pow(module(complex), n) *
            (cos(atan(complex.im / complex.re) * n) + sin(atan(complex.im / complex.re) * n));
}


//Overloads
TComplex TComplex::operator+(TComplex second){
    return TComplex(re + second.re, im + second.im);
}


TComplex TComplex::operator-(TComplex second){
    return TComplex(re - second.re, im - second.im);
}


TComplex TComplex::operator/(TComplex second){
    double a = (re * second.re + im * second.im)/(second.re * second.re + second.im * second.im);
    double b = (second.re * im - re * second.im)/(second.re * second.re + second.im * second.im);
    return TComplex(a, b);
}


TComplex TComplex::operator*(TComplex second){
    double a;
    double b;
    a = re * second.re - im * second.im;
    b = re * second.im + im * second.re;
    return TComplex(a, b);
}


TComplex TComplex::operator+=(TComplex second){
    re += second.re;
    im += second.im;
    return TComplex(re, im);
}


TComplex TComplex::operator-=(TComplex second){
    re -= second.re;
    im -= second.im;
    return TComplex(re, im);
}


TComplex TComplex::operator/=(TComplex second){
    double a = (re * second.re + im * second.im)/(second.re * second.re + second.im * second.im);
    double b = (second.re * im - re * second.im)/(second.re * second.re + second.im * second.im);
    re = a;
    im = b;
    return TComplex(re, im);
}


TComplex TComplex::operator*=(TComplex second){
    double a;
    double b;
    a = re * second.re - im * second.im;
    b = re * second.im + im * second.re;
    re = a;
    im = b;
    return TComplex(re, im);
}


bool TComplex::operator==(TComplex second){
    if(re == second.re && im == second.im) return true;
    return false;
}


bool TComplex::operator!=(TComplex second){
    if(re != second.re || im != second.im) return true;
    return false;
}


std::ostream &operator<<(std::ostream &os, const TComplex &complex){
    if (complex.im < 0){
        os << complex.re << complex.im << "i";
    }else{
        os << complex.re << " + " << complex.im << "i";
    }
    return os;
}


std::istream &operator>>(std::istream & in, TComplex &complex){
    in >> complex.re >> complex.im;
    return in;
}


bool TComplex::operator<(TComplex second){
    if(module(this) < module(&second)) return true;
    return false;
}


bool TComplex::operator>(TComplex second){
    if(module(this) > module(&second)) return true;
    return false;
}


TComplex TComplex::operator+=(double second){
    re += second;
    return TComplex(re, im);
}


TComplex TComplex::operator/=(double second){
    double a = (re * second)/(second * second);
    double b = (second * im)/(second * second);
    re = a;
    im = b;
    return TComplex(re, im);
}


TComplex TComplex::operator=(double second){
    return TComplex(second, 0);
}

