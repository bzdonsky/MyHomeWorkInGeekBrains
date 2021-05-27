#include <stdio.h>
#include <stdlib.h>

/*void fillArray (int *array, int row, int column){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            array[i * column + j] = rand() % 15 ;

        }
    }

}
*/
void printArray (int *array, int row, int column){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            printf("%d " ,array[i * column + j]);
        }
    }
}
void SWAP (int* one, int *two){
    int three = *one;
    *one = *two;
    *two = three;
}
void bubbleSort (int* arr,int col){
    int num = col + col;
    for(int ax = 0; ax < num; ++ax){
        for(int xa = 0; xa < num - 1; ++xa){
            for(int i =0 ; i < col; ++i){
                for(int j = 0; j < col; ++j){
                    if(arr[i * col + j] > arr[i * col + j + 1])
                        SWAP(&arr[i * col + j],&arr[i * col + j + 1]);
                }
            }
        }
    }
}
int main()
{
    const int SIZE = 3;
    int array[SIZE][SIZE] = {
        {1,9,2},
        {5,7,6},
        {4,3,8},
    };
    //fillArray(*array, SIZE,SIZE);
    printArray(*array, SIZE,SIZE);
    printf("\n");
    bubbleSort(*array,SIZE);
    printArray(*array, SIZE,SIZE);


    return 0;
}
