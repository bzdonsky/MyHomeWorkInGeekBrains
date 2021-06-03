#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1 == 1;
#define false 1 != 1
#define SIZE 1000
#define SZ 10
bool Stack[SIZE];
int cursor = -1;
bool push(bool data){
    if(cursor < SIZE){
        Stack[++cursor] = data;
        return true;
    } else {
        printf("%d \n", "Stack overflow");
        return false;
    }

}
bool pop(){
    if(cursor != -1){
        return Stack[cursor--];
    } else {
        printf("%d \n", "Stack is empty");
        return -1;
    }
}
int Number(int num){
    int temp;
    if(num <= 0){
        printf("Wrong input");
        return -1;
    }
    while (num > 0) {
        temp = num % 2;
        num = num / 2;
        push(temp);
    }
    while (cursor != -1) {
        printf("%d " , pop());
    }

}


int main()
{
    int a;
    scanf("%d" ,&a);
    Number(a);
    return 0;
}
