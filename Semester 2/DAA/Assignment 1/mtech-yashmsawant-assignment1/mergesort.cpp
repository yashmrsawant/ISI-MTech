#include "commons.h"

void merge(int* numbers_p, int* aux_p, int p, int a, int q) {
    int j = p;
    int l = p;
    int r = a + 1;
    while(l <= a && r <= q) {
        if(numbers_p[l] <= numbers_p[r]) {
            aux_p[j ++] = numbers_p[l];
            l ++;
        } else {
            aux_p[j ++] = numbers_p[r];
            r ++;
        }
    }
    if(l <= a) {
        while(l <= a) {
            aux_p[j ++] = numbers_p[l];
            l ++;
        }
    } else if(r <= q) {
        while(r <= q) {
            aux_p[j ++] = numbers_p[r];
            r ++;
        }
    }
    for(j = p; j <= q ; j ++) {
        numbers_p[j] = aux_p[j];
    }
}

void mergesort_iterative(int* numbers_p, int size, int* aux_p, struct timeval* time_start_p, struct timeval* time_end_p) {
    gettimeofday(time_start_p, NULL);

    int k = size;
    int exp = 2;
    int i, l, r, range1, range2;
    while(k > 0) {
        for(i = 0; i < size ; i += exp) {
            l = i;
            r = l + exp / 2;
            range1 = r;
            if((r + exp / 2) < size) {
                range2 = r + exp / 2;
            } else {
                range2 = size;
            }
            merge(numbers_p, aux_p, l, range1 - 1, range2 - 1);
        }
        exp = exp * 2;
        k = k / 2;
    }
    gettimeofday(time_end_p, NULL);
}





void mergesort(int* numbers_p, int* aux_p, int p, int q) {
    if(p < q) {
        int a = p + (q - p) / 2;

        mergesort(numbers_p, aux_p, p, a);
        mergesort(numbers_p, aux_p, a + 1, q);
        merge(numbers_p, aux_p, p, a, q);
    }
}

void mergesort_recursive(int* numbers_p, int size, int* aux_p, struct timeval* time_start_p, struct timeval* time_end_p) {
    gettimeofday(time_start_p, NULL);
    mergesort(numbers_p, aux_p, 0, size - 1);
    gettimeofday(time_end_p, NULL);
}
