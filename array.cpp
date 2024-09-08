#include "array.h"
#include "iostream"


Array::Array(int length){
    if (length < 0){
        this->length = 0;
        std::cout << "Invalid length\n"
                     "length = 0";
    }
    this->length = length;
    arr = new number[length];
}


Array::~Array() {
    delete []arr;
}


bool Array::fill() {
    if ( length > 0 ) {
        for (int i = 0; i < length; i++) {
            std::cin >> *(arr + i);
        }
        return true;
    }
    return false;
}


bool Array::resize(int newLength) {
    if (newLength < 0){
        return false;
    }
    number* resizeArr = new number[newLength];
    for(int i = 0; i < newLength; i++){
        *(resizeArr + i) = *(arr + i);
    }
    arr = resizeArr;
    length = newLength;
    delete []arr;
    return true;
}


bool Array::changeElement(int num, number value) {
    if(num >= length && num <= 0){
        return false;
    }
    *(arr + num) = value;
    return true;
}


void Array::printArray() {
    for(int i = 0; i < length; i++){
        std::cout << "Array: " << *(arr + i) << " ";
    }
}


number Array::averageValue() {
    number sum = 0;
    if (length == 0){
        return 0;
    }
    for(int i = 0; i < length; i++){
        sum += *(arr + i);
    }
    sum /= (number)length;
    return sum;
}


number Array::SKO() {
    number avg = averageValue();
    number skoValue = 0;
    if (length == 0){
        return 0;
    }
    for(int i = 0; i < length; i++){
        skoValue += pow( *(arr + i) - avg, 2);
    }
    skoValue /= (number)length;
    skoValue = pow(skoValue, 0.5);
    return skoValue;
}


void Array::shakerSort(bool reverse) {
    for ( int i = 0; i < length/2; i++){
        for ( int j = i; i < length - 1; i++){
            if ( !reverse ){
                if ( *(arr + j) > *(arr + j + 1) ){
                    std::swap(*(arr + j), *(arr + j + 1));
                }

            }else{
                if ( *(arr + j) < *(arr + j + 1) ){
                    std::swap(*(arr + j), *(arr + j + 1));
                }
            }
        }

        for ( int j = length - 1 - i; i > 0; i--){
            if ( !reverse ){
                if ( *(arr + j) < *(arr + j - 1) ){
                    std::swap(*(arr + j), *(arr + j + 1));
                }

            }else{
                if ( *(arr + j) > *(arr + j + 1) ){
                    std::swap(*(arr + j), *(arr + j + 1));
                }
            }
        }
    }
}
