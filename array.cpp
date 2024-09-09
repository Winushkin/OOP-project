#include "array.h"
#include "iostream"

// using namespace std;

Array::Array(int length){
    if (length < 0){
        this->length = 0;
        std::cout << "Неверно введена длина\n"
                     "длина = 0";
    }
    this->length = length;
    arr = new number[length];
}


Array::~Array() {
    delete []arr;
}


int Array::getLength() {
    return this->length;
}


void Array::fill() {
    for (int i = 0; i < length; i++) {
        std::cin >> *(arr + i);
    }
}


bool Array::resize(int newLength) {
    if (newLength < 0){
        return false;
    }
    number* resizeArr = new number[newLength];
    for(int i = 0; i < newLength; i++){
        *(resizeArr + i) = *(arr + i);
    }
    length = newLength;
    delete []arr;
    arr = resizeArr;
    return true;
}


bool Array::changeElement(int index, number value) {
    if(index >= length && index <= 0){
        return false;
    }
    *(arr + index) = value;
    return true;
}


void Array::printArray() {
    std::cout << "Массив: ";
    for(int i = 0; i < length; i++){
        std::cout<< *(arr + i) << " ";
    }
    std::cout << "\n";
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
    skoValue /= ((number)length - 1);
    skoValue = pow(skoValue, 0.5);
    return skoValue;
}

// разобраться с сортировкой
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
