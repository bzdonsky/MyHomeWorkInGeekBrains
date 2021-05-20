#include <stdio.h>

void PrimeNumber(){
    int array[255] = {2,3};
    int a = 2;
    for(int i = 4; i < 255; ++i){
        int isPrime = 1;
        for(int j = 0; j < a; ++j){
            if(i % array[j] == 0){
                isPrime = 0;
                break;
            }
        }
        if(isPrime){
            array[a++] = i;
        }
    }
    for(int i = 0; i < a; i++){
        printf("%d ", array[i]);
    }

}

int main(int argc, char *argv[])
{
    PrimeNumber();

    return 0;
}
