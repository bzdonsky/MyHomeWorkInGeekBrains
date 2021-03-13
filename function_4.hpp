namespace foo {
void ShiftArray(int arr[],int quan, int shift){ // 4.0
    shift = shift % quan;
    if(shift >= 0){
        for(int j = 0; j < shift; j++){
            int x = arr[4];
            for(int i = (quan -1); i >= 0; i--){
                arr[i] = arr[i - 1];
            }
        arr[0] = x;
        }
    }
    else {
        for(int j = 0; j > shift ; j--){
            int x = arr[0];
            for(int i = 0; i < 5; i++){
                arr[i] = arr[i + 1];
            }
            arr[4] = x;
        }
    }
}
}
