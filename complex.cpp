#include "complex.h"
#include "number.h"
#include <iostream>

using namespace std;


TComplex::TComplex() {

}


TComplex::TComplex(double a, double b) {
    re = a; im = b;
}


double TComplex::getIm(){
    return this->im;
}


TComplex TComplex::operator+(TComplex second) {
    return TComplex(re + second.re, im + second.im);
}


TComplex TComplex::operator-(TComplex second) {
    return TComplex(re - second.re, im - second.im);
}


TComplex TComplex::operator/(TComplex second) {
    double a = (re * second.re + im * second.im)/(second.re * second.re + second.im * second.im);
    double b = (second.re * im - re * second.im)/(second.re * second.re + second.im * second.im);
    return TComplex(a, b);
}


TComplex TComplex::operator*(TComplex second) {
    double a;
    double b;
    a = re * second.re - im * second.im;
    b = re * second.im + im * second.re;
    return TComplex(a, b);
}


TComplex TComplex::operator +=(TComplex second) {
    re += second.re;
    im += second.im;
    return TComplex(re, im);
}


TComplex TComplex::operator -=(TComplex second) {
    re -= second.re;
    im -= second.im;
    return TComplex(re, im);
}


TComplex TComplex::operator /=(TComplex second) {
    double a = (re * second.re + im * second.im)/(second.re * second.re + second.im * second.im);
    double b = (second.re * im - re * second.im)/(second.re * second.re + second.im * second.im);
    re = a;
    im = b;
    return TComplex(re, im);
}


std::ostream &operator<<(std::ostream &os, const TComplex &complex){
    if ( complex.im < 0 ){
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



