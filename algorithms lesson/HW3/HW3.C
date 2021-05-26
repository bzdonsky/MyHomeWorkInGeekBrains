#include <stdio.h>
//


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
    int board (int x, int y);
    int King(int x, int y){
        if (x == 0 && y == 0){
            return 0;
        }
        if (board(x , y) == 1){
            return 0;
        }
        return (King(x , y - 1) + King(x - 1 ,y));


    }
int board (int x, int y){
        int desk[5][5]{0};
                desk[0][3] = 1;
                desk[2][4] = 1;
                desk[1][3] = 1;
                desk[0][4] = 1;

        return desk[x][y];
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


/*for (int i = 4 ; i >= 0 ; i--){
    for(int j = 4; j >= 0; j--){
    printf("%d ", King(j , i));
    }
}*/
  printf("%d ", King(4,4));
    return 0;
}

