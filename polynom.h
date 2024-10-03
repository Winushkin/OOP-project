#ifndef OOPPRACTICE_POLYNOM_H
#define OOPPRACTICE_POLYNOM_H

#include "number.h"

class Polynom {
    number* solutions;
    number* coefficients;
public:
    Polynom();
    Polynom(number a, int N);
};


#endif
