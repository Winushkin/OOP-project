#include "polynom.h"


Polynom::Polynom(number *coefficients, int degree) : coefficients(coefficients), degree(degree){}

void Polynom::printWithDegrees() {
    for ( int i = 0; i <= degree; i++ ){
        cout << "p(x) = ";
        if (*(coefficients + i) == 0){

        }
    }
}