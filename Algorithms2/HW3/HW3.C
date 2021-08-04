#include <stdio.h>
int Number(int a){
    if(a == 0){
        return 0;
    }
    else{

        Number(a / 2);
    }
    printf("%d", a % 2);

}


int Power(int a, int b){
    if(b <= 0){
        return 1;
    }
    else {
        return a * Power(a , b - 1);
    }
}

    int isPower(int a, int b){
        if(b <= 0){
            return 1;
        }
        if(b % 2 ==0){
            return isPower(a * a, b / 2);
        }
        else {
            return a * isPower(a , b - 1);
        }
    }


int main(int argc, char *argv[])
{
    int a;
    int b;
    scanf("%d" , &a);
    scanf("%d" , &b);
    Number(a);
    printf("\n");
    printf("%d" , Power(a , b));
    printf("\n");
    printf("%d" , isPower(a , b));



    return 0;
}

