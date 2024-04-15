#include "commons.h"
/*
// heapsort_iterative: Implements heapsort iteratively by building the heap and then repeatedly deleting the maximum element.
// maxheapify: Recursively restores the heap property starting from a given node in the heap.
// delete_max: Deletes the maximum element from the heap.
// heapsort: Recursively performs heapsort by repeatedly deleting the maximum element.
// buildheap: Builds a max heap from the given array.
// heapsort_recursive: Performs heapsort recursively by building the heap and then sorting it.
*/

void heapsort_iterative(int* numbers_p, int size, int* numbers_pa, struct timeval* time_start_p, struct timeval* time_end_p) {

    gettimeofday(time_start_p, NULL);

    int i;
    int p_i, insert_i;
    int heapsize = 0;
    for(i = 0 ; i < size ; i ++) {
        heapsize = heapsize + 1;
        insert_i = heapsize - 1;
        numbers_pa[insert_i] = numbers_p[i];
        while(TRUE) {
            if(insert_i == 0)
                break;
            else {
                p_i = (insert_i + 1) / 2 - 1;
                if(numbers_pa[p_i] < numbers_pa[insert_i]) {
                    //Swap numbers_pa[p] and numbers_pa[insert_i]
                    swap(&numbers_pa[p_i], &numbers_pa[insert_i]);
                    insert_i = p_i;
                } else {
                    break;
                }
            }
        }
    }



    int last, cl, cr, max_i, p;
    while(heapsize > 2) {

        last = heapsize - 1;

        swap(&numbers_pa[last], &numbers_pa[0]);
        heapsize = heapsize - 1;
        p = 0;
        while(heapsize > 1) {
            cl = 2 * p + 1;
            cr = 2 * p + 2;
            if(cr <= (heapsize - 1)) {
                if(numbers_pa[p] < numbers_pa[cl] || numbers_pa[p] < numbers_pa[cr]) {
                    if(numbers_pa[cl] > numbers_pa[cr]) {
                        max_i = cl;
                    }
                    else {
                        max_i = cr;
                    }
                    swap(&numbers_pa[max_i], &numbers_pa[p]);
                    p = max_i;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }
    for(i = 0 ; i < size ; i ++) {
        numbers_p[i] = numbers_pa[i];
    }

    gettimeofday(time_end_p, NULL);
}


void maxheapify(int* numbers_p, int i, int heapsize) {
    int lc = 2 * i + 1, rc = 2 * i + 2;
    int max_i;
    if(lc <= (heapsize - 1)) {
        if(rc <= (heapsize - 1)) {
            if(numbers_p[lc] < numbers_p[rc]) {
                max_i = rc;
            } else {
                max_i = lc;
            }
            if(numbers_p[i] < numbers_p[max_i]) {
                swap(&numbers_p[i], &numbers_p[max_i]);
                maxheapify(numbers_p, max_i, heapsize);
            }
        } else {
            if(numbers_p[i] < numbers_p[lc]) {
                swap(&numbers_p[i], &numbers_p[lc]);
                maxheapify(numbers_p, lc, heapsize);
            }
        }
    }
}

void delete_max(int* numbers_p, int* heapsize_p) {
    int last = *heapsize_p - 1;
    swap(&numbers_p[0], &numbers_p[last]);

    *heapsize_p = *heapsize_p - 1;
    maxheapify(numbers_p, 0, *heapsize_p);
}

void heapsort(int* numbers_p, int heapsize) {
    if(heapsize > 1) {
        delete_max(numbers_p, &heapsize);
        heapsort(numbers_p, heapsize);
    }
}
void buildheap(int* numbers_p, int size, int* numbers_pa) {
    int i;
    int p_i, insert_i;
    int heapsize = 0;
    for(i = 0 ; i < size ; i ++) {
        heapsize = heapsize + 1;
        insert_i = heapsize - 1;
        numbers_pa[insert_i] = numbers_p[i];
        while(TRUE) {
            if(insert_i == 0)
                break;
            else {
                p_i = (insert_i + 1) / 2 - 1;
                if(numbers_pa[p_i] < numbers_pa[insert_i]) {
                    //Swap numbers_pa[p] and numbers_pa[insert_i]

                    swap(&numbers_pa[p_i], &numbers_pa[insert_i]);
                    insert_i = p_i;
                } else {
                    break;
                }
            }
        }
    }
    for(i = 0 ; i < size ; i ++) {
        numbers_p[i] = numbers_pa[i];
    }
}

void heapsort_recursive(int* number, int size, int* numbers_pa, struct timeval *time_start_p, struct timeval *time_end_p) {
    gettimeofday(time_start_p, NULL);
    int heapsize = size;
    buildheap(number, heapsize, numbers_pa);
    heapsort(number, heapsize);

    gettimeofday(time_end_p, NULL);
}
