#include <stdio.h>
#include <math.h>

int primeNum(int a){
    if(a <= 0){
        return 0;
    }
    if(a == 1){
        return 1;
    }
    int front = (int) sqrt(a);
    for(int i = 2; i <= front; ++i){
        if(a % i == 0){
            return 0;
        }
        return 1;
    }
}


int main(int argc, char *argv[])
{
    int num = 8;
    primeNum(num);
    printf("Number %d is %s prime\n", num, (primeNum(num)) ? "" : "not");

    return 0;
}
