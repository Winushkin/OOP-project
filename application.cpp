#include "application.h"

#include "iostream"

using namespace std;

void Application::showMenu() {
    cout << "1. Создать массив\n";
    cout << "2. Заполнить массив\n";
    cout << "3. Удалить массив\n";
    cout << "4. Изменить размерность массива\n";
    cout << "5. Вывести элементы массива\n";
    cout << "6. Посчитать среднее\n";
    cout << "7. Посчитать СКО\n";
    cout << "8. Отсортировать\n";
    cout << "9. Изменить элемент\n";
    cout << "0. Выйти\n";
}

int Application::exec(){
    unsigned char choice, sortReverse;
    int len, newLen, index;
    number value;
    Array *array = new Array(0);
    while(true){
        showMenu();
        cout << "Выберите: "; cin >> choice;

        switch (choice){

            case 1:
                cout << "Введите длину массива: "; cin >> len;
                array = new Array(len);
                break;

            case 2:
                cout << "Введите " << array->getLength() << " элементов массива через пробел\n";
                array->fill();
                cout << "Массив заполнен\n";
                break;

            case 3:
                delete array;
                array = new Array(0);
                cout << "Массив удален\n";
                break;

            case 4:
                cout << "Введите новую длину массива: "; cin >> newLen;
                array->resize(newLen);
                break;

            case 5:
                array->printArray();
                break;

            case 6:
                cout << array->averageValue();
                break;

            case 7:
                cout << array->SKO();
                break;

            case 8:
                cout << "Сортировка:\n";
                cout << "1. По возрастанию\n";
                cout << "2. По убыванию\n";
                cin >> sortReverse;
                switch (sortReverse) {
                    case 1:
                        array->shakerSort();
                        break;

                    case 2:
                        array->shakerSort(true);
                        break;
                }
                cout << "Сортировка завершена\n";
                break;

            case 9:
                cout << "Введите\n";
                cout << "Индекс элемента: "; cin >> index; cout << "\n";
                cout << "Новое значение: "; cin >> value; cout << "\n";

                array->changeElement(index, value);
                cout << "Значение элемента заменено";

            case 0:
                return 0;
        }
    }
}



