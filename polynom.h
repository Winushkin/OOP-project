#ifndef OOPPRACTICE_POLYNOM_H
#define OOPPRACTICE_POLYNOM_H

#include "number.h"

class Polynom {
    number* roots = nullptr;
    number* coefficients = nullptr;
    int degree = 0;

public:
    Polynom(number *coefficients = nullptr, int degree = 0);

    void printWithDegrees();

    void printWithRoots();

    number valueAtPoint(number point);


};


#endif