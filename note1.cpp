//可能要不到空間 → 需要 check availability  =>  *array == NULL → 代表分配失敗
//realloc 不一定會拿到一樣的起始位置，舊資料 不一定會被覆蓋
//有新分配 → 舊資料會被複製過去
//沒有新分配 → 繼續沿用原空間
//陣列需要 連續記憶體空間

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int n = 10;

    array = (int *) malloc(n * sizeof(int));


    //malloc() 會向作業系統請求一塊動態記憶體空間，但不保證一定成功
    //需透過array == NULL確認是否有要到空間
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for(int i = 0; i < n; i++) {
        array[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    n = n * 2;

    array = (int *) realloc(array, n * sizeof(int));

    //realloc 會向作業系統請求一塊動態記憶體空間，但不保證一定成功
    //需透過array == NULL確認是否有要到空間
    if (array == NULL) {
        printf("Reallocation failed\n");
        return 1;
    }


    //print出realloc後陣列頭尾的記憶體位址
    printf("\nAfter realloc memory address: %p\n", (void*)array);
    printf("After realloc end address   : %p\n", (void*)(array + n * sizeof(n) - 1));

    for (int i = n/2; i < n; i++) {
        array[i] = i + 1;   
    }

    // print all elements
    printf("Resized array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    //釋放記憶體空間
    free(array);
    return 0;
}



