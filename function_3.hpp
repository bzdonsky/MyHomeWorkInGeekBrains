namespace foo {
bool checkBalanse(int a[],int b){ // 3.0

     int x = 0;
     for(int i = 0; i < b ; i++){
         x += a[i];
     }
     return (x % 2 == 0) ? true : false;
}
}
