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

void Array::resize(int length) {

}

