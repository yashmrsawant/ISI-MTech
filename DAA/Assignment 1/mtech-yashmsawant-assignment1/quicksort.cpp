#include "commons.h"
#include "stack.h"

int partition(int* numbers_p, int p, int q) {

    int pivot_i = rand() % (q - p + 1) + p;
    swap(&numbers_p[pivot_i], &numbers_p[p]);
    int i = p + 1, j = p;
    int pivot = numbers_p[p];

    for(; i <= q ; i ++) {
        if(numbers_p[i] <= pivot) {
            if(i == (j + 1)) {
                swap(&numbers_p[i], &numbers_p[j]);

                j = j + 1;
            } else {
                swap(&numbers_p[i], &numbers_p[j]);
                swap(&numbers_p[i], &numbers_p[j + 1]);
                j = j + 1;
            }
        }
    }

    return j;
}

void quicksort_iterative(int* numbers_p, int size, int* aux_p, struct timeval *time_start_p, struct timeval *time_end_p) {
    gettimeofday(time_start_p, NULL);
    int i = -1;
    aux_p[++ i] = 0;
    aux_p[++ i] = size - 1;
    int min = HI, max = LOW;
    while(i > 0) {

        int p = aux_p[i - 1];
        int q = aux_p[i];

        if(p == q) {
            if(min > p) {
                min = p;
            }
            if(max < q) {
                max = q;
            }
            i = i - 2;
        } else if(p == (q - 1)) {
            if(numbers_p[p] > numbers_p[q]) {
                swap(&numbers_p[p], &numbers_p[q]);
            }
            if(min > p) {
                min = p;
            }
            if(max < q) {
                max = q;
            }
            i = i - 2;
        } else if(p >= min && q <= max) {
            i = i - 2;
        }

        else {

            int pivot_i = partition(numbers_p, p, q);
            if(pivot_i == p) {
                aux_p[++ i] = pivot_i;
                aux_p[++ i] = pivot_i;
                aux_p[++ i] = pivot_i + 1;
                aux_p[++ i] = q;
            }
            else if(pivot_i == q) {
                aux_p[++ i] = p;
                aux_p[++ i] = pivot_i - 1;
                aux_p[++ i] = pivot_i;
                aux_p[++ i] = pivot_i;
            } else {
                aux_p[++ i] = p;
                aux_p[++ i] = pivot_i - 1;
                aux_p[++ i] = pivot_i + 1;
                aux_p[++ i] = q;
            }
        }
    }

    gettimeofday(time_end_p, NULL);
}

void quicksort(int* numbers_p, int p, int q) {
    if(p < q) {
        int pivot_i = partition(numbers_p, p, q);
        quicksort(numbers_p, p, pivot_i - 1);
        quicksort(numbers_p, pivot_i + 1, q);
    }
}

void quicksort_recursive(int* numbers_p, int size, struct timeval *time_start_p, struct timeval *time_end_p) {
    gettimeofday(time_start_p, NULL);
    quicksort(numbers_p, 0, size - 1);
    gettimeofday(time_end_p, NULL);
}
