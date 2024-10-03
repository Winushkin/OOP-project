#include "polynom.h"


Polynom::Polynom(number *coefficients, int degree) : coefficients(coefficients), degree(degree){}


void Polynom::printWithDegrees() {
    cout << "p(x) = ";
    if (*(coefficients) != 0){
        cout << " " << *(coefficients) << "x^" << degree;
    }
    for ( int i = 1; i < degree - 1; i++ ){
        cout << " + ";
        if (*(coefficients + i) != 0){
            cout << *(coefficients + i) << "x^" << degree - i;
        }
    }
    if ( *(coefficients + degree - 1) != 0 ){
        cout << " + " << *(coefficients + degree - 1) << "x";
    }
    if ( *(coefficients + degree) != 0 ){
        cout << " + " << *(coefficients + degree);
    }
}


void Polynom::printWithRoots() {
    cout << "p(x) = ";
    if(*(coefficients) != 0) {
        cout << *(coefficients);
    }else{
        cout << "0";
    }

    for(int i = 0; i <= degree; i++){
        if(*(roots + i) != 0){
            cout << "(x - " << *(roots + i) << ")";
        }else{
            cout << "x";
        }
    }


}


number Polynom::valueAtPoint(number point){
    number sum = 0;
    for(int i = 0; i < degree; i++){
        number a = *(coefficients + i);
        number b = pow(point, degree - i);
        sum += a * b;
    }
    sum += *(coefficients + degree);
    return sum;
}