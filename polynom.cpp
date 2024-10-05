#include "polynom.h"


Polynom::Polynom(): coefficients(nullptr), roots(nullptr), degree(0) {}


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

    for(int i = 0; i < degree; i++){
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

Polynom *Polynom::fill(number leadingCoefficient, number* roots, int rootsCount) {
    this->roots = roots;
    coefficients = new number [rootsCount];
    coefficients[0] = leadingCoefficient;
    degree = rootsCount - 1;
    for (int i = 1; i <= degree; ++i) {
        coefficients[i] = 0;
    }
    for (int i = 0; i < degree; ++i) {
        number root = roots[i];
        // Обновляем коэффициенты справа налево, чтобы избежать перезаписи
        for (int j = i; j >= 0; --j) {
            // Коэффициент a_{j+1} обновляется с учетом a_j
            coefficients[j + 1] += coefficients[j];
            // Коэффициент a_j умножается на -root
            coefficients[j] *= -root;
        }
    }

    for(int i = 0; i < rootsCount / 2; i++){
        swap(coefficients[i], coefficients[rootsCount - i - 1]);
    }

    cout << "\n";
    for(int i = 0; i < rootsCount; i++){
        cout << coefficients[i] << " ";
    }
    return nullptr;
}
