#include <geek.c>
int getNumArr(int* arr, int row, int col){

    return *((arr + row) + col) ;
}
void PrintArray(int* arr, int row, int col){
    for(int i = 0; i < row; i++ ){
        for(int j = 0; j < col; ++j){
            printf("%d", getNumArr(arr,i * row,j));
        }
    }
}
void swap(int* one, int* two){
    int temp;
    temp = *one;
    *one = *two;
    *two = temp;
}
/*void BubbleSort(int** arr, int row, int col){ // хотел сделать красиво, но не понимаю как работать в функции с двухмерным массивом(P.S компилятор на эту функцию не ругается, но выдает ошибку)
    int united = row + col;
    for(int i = 0; i < united; ++i){
        for(int j = 0; j < united - 1; ++j){
            int PreviousRow = j / col;
            int PreviousCol = j % col;
            int NextRow = (j +1) / col;
            int NextCol = (j +1) % col;
            if(arr[PreviousRow][PreviousCol] > arr[NextRow][NextCol]){
            swap(&arr[PreviousRow][PreviousCol], &arr[NextRow][NextCol]);
            }
        }
    }
}
*/
void bubbleSort (int* arr,int col){
    int united = col + col;
    for(int ax = 0; ax < united; ++ax){
        for(int xa = 0; xa < united - 1; ++xa){
            for(int i =0 ; i < col; ++i){
                for(int j = 0; j < col; ++j){
                    if(arr[i * col + j] > arr[i * col + j + 1])
                        swap(&arr[i * col + j],&arr[i * col + j + 1]);
                }
            }
        }
    }
}
int main()
{
    const int SIZE = 3;
    int array[SIZE][SIZE]{
        {1,9,3},
        {2,5,7},
        {4,6,8},
    };

    PrintArray(*array,SIZE,SIZE);
    //BubbleSort((int**)array,SIZE,SIZE);
    bubbleSort(*array,SIZE);
    printf("\n");
    PrintArray(*array,SIZE,SIZE);

    return 0;
}
