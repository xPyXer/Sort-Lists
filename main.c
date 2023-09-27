#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10000

void randomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble(int arr[], int n, int* changes) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                (*changes)++;
            }
        }
    }
}

void insertion(int arr[], int n, int* changes) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*changes)++;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high, int* changes) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            (*changes)++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick(int arr[], int low, int high, int* changes) {
    if (low < high) {
        int pi = partition(arr, low, high, changes);
        quick(arr, low, pi - 1, changes);
        quick(arr, pi + 1, high, changes);
    }
}

int main() {
    int arr[TAM];
    int changeBubble = 0;
    int changeInsertion = 0;
    int changeQuick = 0;


    // Bubble Sort
    randomArray(arr, TAM);
    clock_t start, end;
    double time1, time2, time3;
    start = clock();
    bubble(arr, TAM, &changeBubble);
    end = clock();
    time1 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n BUBBLE SORT \n");
    printf("%f Tempo de execucao do Bubble Sort: \n", time1);
    printf("Total de trocas: %d\n\n", changeBubble);

    
    // Insertion Sort
    randomArray(arr, TAM);
    start = clock();
    insertion(arr, TAM, &changeInsertion);
    end = clock();
    time2 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n INSERTION SORT \n");
    printf("%f Tempo de execucao do Insertion Sort: \n", time2);
    printf("Total de trocas: %d\n\n", changeInsertion);


    // Quick Sort
    randomArray(arr, TAM);
    start = clock();
    quick(arr, 0, TAM - 1, &changeQuick);
    end = clock();
    time3 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n QUICK SORT \n");
    printf("%f Tempo de execucao do Quick Sort: \n", time3);
    printf("Total de trocas: %d\n\n", changeQuick);
    printf("\n");
    return 0;
}