#include <stdio.h>
#include <stdlib.h>

int main() {
    int a;
    printf("Enter a number: ");
    scanf("%d", &a); 
    int *arr = malloc(a * sizeof(int)); 
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < a; i++) {
        arr[i] = i * 10;
    }
    for (int i = 0; i < a; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr); 
    return 0;
}