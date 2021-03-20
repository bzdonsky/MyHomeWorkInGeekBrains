#include <iostream>
#define FINE(num, max) (((num) >= 0) && ((num) < (max)))
#define ARRAY(array , x, y) (*(*(array + x) + y))
#define ARRAY_SIZE(array) ((sizeof(array)) / (sizeof(array[0])))
int main(){
    {
    int a = 25;
    std::cout << std::boolalpha << FINE(a, 30) << '\n';
    }

    {
    int** array = new int* [3];
    array[0] = new int[2];
    array[1] = new int[2];
    array[2] = new int[2];
    array[1][2] = 70;
    std::cout << array[1][2] << '\n' << ARRAY(array, 1 , 2) << '\n';
    delete[] array;
    }
    {
    int array_size[33];
    std::cout << ARRAY_SIZE(array_size) << '\n';
    }




    return 0;
}
