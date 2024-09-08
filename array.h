#include "number.h"
#include "iostream"


#ifndef OOPPRACTICE_ARRAY_H
#define OOPPRACTICE_ARRAY_H


class Array{
private:
    int length;
    number *arr;
public:
    Array(int length = 0);
    ~Array();
    void fill();
    void resize(int length);






};

#endif //OOPPRACTICE_ARRAY_H
