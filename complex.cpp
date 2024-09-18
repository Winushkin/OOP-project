#include "complex.h"
#include "number.h"
#include <iostream>

using namespace std;


TComplex::TComplex() {

}


TComplex::TComplex(double a, double b){
    re = a; im = b;
}


double TComplex::getRe(){
    return this->re;
}


double TComplex::getIm(){
    return this->im;
}


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

bool TComplex::operator<(TComplex second){
    double a = pow(re,2);
    double b = pow(im, 2);
    double c = pow(second.re,2);
    double d = pow(second.im, 2);
    if(pow(a + b, 0.5) < pow(c + d, 0.5)) return true;
    return false;
}

bool TComplex::operator>(TComplex second){
    double a = pow(re,2);
    double b = pow(im, 2);
    double c = pow(second.re,2);
    double d = pow(second.im, 2);
    if(pow(a + b, 0.5) > pow(c + d, 0.5)) return true;
    return false;
}

TComplex TComplex::operator+=(double second) {
    re += second;
    return TComplex(re, im);
}

TComplex TComplex::operator/=(double second) {
    double a = (re * second)/(second * second);
    double b = (second * im)/(second * second);
    re = a;
    im = b;
    return TComplex(re, im);
}


double pow(TComplex a, double n){

}