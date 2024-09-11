#include "complex.h"
#include "number.h"
#include <iostream>

using namespace std;


TComplex::TComplex() {

}


double TComplex::getRe() {
    return this->re;
}


double TComplex::getIm(){
    return this->im;
}


void TComplex::operator+(TComplex second) {
    re += second.re;
    im += second.im;
}


void TComplex::operator-(TComplex second) {
    re -= second.re;
    im -= second.im;
}


void TComplex::operator/(TComplex second) {
    double a = (re * second.re + im * second.im)/(second.re * second.re + second.im * second.im);
    double b = (second.re * im - re * second.im)/(second.re * second.re + second.im * second.im);
    re = a;
    im = b;
}


void TComplex::operator*(TComplex second) {
    double a;
    double b;
    a = re * second.re - im * second.im;
    b = re * second.im + im * second.re;
    re = a;
    im = b;
}


std::ostream &operator<<(std::ostream &os, const TComplex &complex){
    if ( complex.im < 0 ){
        os << complex.re << complex.im << "i";
    }else{
        os << complex.re << " + " << complex.im << "i";
    }
    return os;
}

std::ostream &operator>>(std::ostream & in, const TComplex &complex){
    in >> complex.re >> complex.im;
}


