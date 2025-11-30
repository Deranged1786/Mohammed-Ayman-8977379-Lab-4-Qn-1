#include <stdio.h>

void rearrange_iterative(int arr[], int size);
void rearrange_rec_main(int arr[], int size);
void rearrange_worker(int arr[], int size, int i, int temp[], int *left, int *right);

int main() {
    int arr[] = {5, 2, 7, 4, 9, 6, 3, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Original: \n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    rearrange_iterative(arr, size);

    printf("Iterative Result: \n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    int arr2[] = {5, 2, 7, 4, 9, 6, 3, 8};
    
    rearrange_rec_main(arr2, size);

    printf("Recursive Result: \n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}

void rearrange_iterative(int arr[], int size) {
    int temp[size];
    int left = 0;
    int right = size - 1;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            temp[left] = arr[i];
            left++;
        } else {
            temp[right] = arr[i];
            right--;
        }
    }

    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

void rearrange_rec_main(int arr[], int size) {
    int temp[size];
    int left = 0;
    int right = size - 1;

    rearrange_worker(arr, size, 0, temp, &left, &right);

    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

void rearrange_worker(int arr[], int size, int i, int temp[], int *left, int *right) {
    if (i == size) {
        return;
    }

    if (arr[i] % 2 != 0) {
        temp[*left] = arr[i];
        (*left)++;
    } 
    else {
        temp[*right] = arr[i];
        (*right)--;
    }

    rearrange_worker(arr, size, i + 1, temp, left, right);
}
