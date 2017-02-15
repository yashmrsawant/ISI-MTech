#ifndef HEAPSORT_H
#define HEAPSORT_H

void heapsort_iterative(int* numbers_p, int size, int* aux, struct timeval* time_start_p, struct timeval* time_end_p);
void heapsort_recursive(int* numbers_p, int size, int* aux, struct timeval* time_start_p, struct timeval* time_end_p);

#endif // HEAPSORT_H
