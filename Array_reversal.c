#include<stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr,*arr2,i;
    printf("enter the aize of an array\n");
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    printf("Enter the array elements\n");
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    arr2 = (int*) malloc(num * sizeof(int));
    for(i=1;i<=num;i++) {
        arr2[i-1] = arr[num-i];
    }
    printf("Array elements in Reverse order is \n");
    for(i = 0; i < num; i++)
        printf("%d ", *(arr2 + i));
    return 0;
}
