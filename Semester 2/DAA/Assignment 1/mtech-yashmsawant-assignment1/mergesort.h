#ifndef MERGESORT_H
#define MERGESORT_H

void mergesort_iterative(int* numbers_p, int size, int* aux_p, struct timeval *time_start_p, struct timeval *time_end_p);
void mergesort_recursive(int* numbers_p, int size, int* aux_p, struct timeval *time_start_p, struct timeval *time_end_p);

#endif // MERGESORT_H
