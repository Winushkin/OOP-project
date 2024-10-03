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


std::vector<int> multiplyPolynomials(const std::vector<int>& poly1, const std::vector<int>& poly2) {
    std::vector<int> result(poly1.size() + poly2.size() - 1, 0);

    for (size_t i = 0; i < poly1.size(); ++i) {
        for (size_t j = 0; j < poly2.size(); ++j) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }

    return result;
}



std::vector<int> polynomialFromRoots(const std::vector<int>& roots, int an) {
    // Начнем с полинома (x - r1)
    std::vector<int> result = {an, -an * roots[0]};

    // Поочередно умножаем на (x - ri)
    for (size_t i = 1; i < roots.size(); ++i) {
        std::vector<int> nextPoly = {1, -roots[i]};
        result = multiplyPolynomials(result, nextPoly);
    }

    return result;
}
