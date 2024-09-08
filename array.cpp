#include "array.h"


Array::Array(int length){
    if (length < 0){
        length = 0;
        std::cout << "Invalid length\n"
                     "length = 0";
    }
    this->length = length;
    arr = new number[length];
}

Array::~Array() {
    delete []arr;
}

void Array::fill() {
    if ( length > 0 ){
        for ( int i = 0; i < length; i++ ){
            std::cin >> *(arr + i);
        }
    }else{
        std::cout << "length = 0";
    }
}

void Array::resize(int newLength) {
    if (newLength < 0){
        std::cout << "Invalid length";
        return;
    }
    number* resizeArr = new number[newLength];
    for(int i = 0; i < newLength; i++){
        *(resizeArr + i) = *(arr + i);
    }
    arr = resizeArr;
    length = newLength;
    delete []arr;
}

void Array::changeElement(int num, number value) {
    if(num >= length){
        std::cout << "Invalid number";
        return;
    }
    *(arr + num) = value;
}

void Array::printArray() {
    for(int i = 0; i < length; i++){
        std::cout << "Array: " << *(arr + i) << " ";
    }
}

void Array::averageValue() {
    number sum = 0;
    if (length == 0){
        std::cout << "Array is empty";
        return;
    }
    for(int i = 0; i < length; i++){
        sum += *(arr + i);
    }
    sum /= length;
    std::cout << "Average = " << sum;
}

void Array::SKO() {
    number skoValue = 0;
    if (length == 0){
        std::cout << "Array is empty";
        return;
    }
    for(int i = 0; i < length; i++){
        skoValue += *(arr + i);
    }
}

