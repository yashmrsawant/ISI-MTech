#ifndef QUICKSORT_H
#define QUICKSORT_H


void quicksort_iterative(int* numbers_p, int size, int* aux_p, struct timeval* time_start_p, struct timeval* time_end_p);
void quicksort_recursive(int* numbers_p, int size, struct timeval* time_start_p, struct timeval* time_end_p);

#endif // QUICKSORT_H
