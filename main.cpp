#include <iostream>
#include <functional>
#include "function_1.hpp"  // функция для задания 1.0
#include "function_2.hpp"  // функция для задания 2.0
#include "function_3.hpp"  // функция для задания 3.0
#include "function_4.hpp"  // функция для задания 4.0


int main()
{
    { // 1.0
    int array[5]{0};
    for(int i = 0 ; i < 5 ; i++){  // заполнить массив 0 и 1
        int a;
        a = (i % 2 == 0) ? 1 : 0;
        array[i] = a;
        std::cout << array[i];
    }

    std::cout << '\n';

    std::function<bool(int)> TO_ptr = foo::TornOver; // указатель на функцию заменяющая 0 на 1 из function_1.hpp

    for(int i = 0; i < 5; i++){
        array[i] = TO_ptr(array[i]);
        std::cout << array[i];
    }
    }

    std::cout << '\n'; // конец первого задания

    { // 2.0
        std::function<void(int*,int)> AS_ptr = foo::ArraySpace; // указатель на функцию заполняющая массив 1/7/10/13/16/19/22 из function_2.hpp
    int array[8]{};
    AS_ptr(&array[0], 8);
    for(int i = 0 ; i < 8; i++){
        std::cout <<  array[i];
    }
    }

    std::cout << '\n';  // конец второго задания

    { // 3.0
        std::function<bool(int*,int)> CH_ptr = foo::checkBalanse;  // Указатель на Функцию проверяющая является  ли левая и правая часть массива равной из function_3.hpp
        int array[5]{1,1,1,2,1};
        std::cout << CH_ptr(&array[0], 5);
    }

    std::cout << '\n'; // конец третьего задания

    { // 4.0
    std::function<void(int*,int,int)> SA_ptr = foo::ShiftArray;  // указатель на функцию, которая циклически сдвигает элементы на N позиций из function_4.hpp
    int array[5]{};
    for(int i = 0; i < 5; i++){ // заполнить массив числами от 0 до 4
        array[i] = i;
    }
    int input;
    std::cin >> input;  // считать число на сдвиг
    SA_ptr(&array[0], 5, input);


    for(int i = 0; i < 5; i ++){
        std::cout << array[i];
    }
    }
    // конец четвертого задания

return 0;
}
