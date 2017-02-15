#ifndef COMMONS_H
#define COMMONS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "heapsort.h"
#include "quicksort.h"
#include "mergesort.h"

#define TRUE 1
#define FALSE 0


inline void swap(int *a_p, int *b_p) {
    *a_p = *a_p + *b_p;
    *b_p = *a_p - *b_p;
    *a_p = *a_p - *b_p;
}

#define XDATASIZE 50000
#define INTEGERARRSIZE 50100
#define MEANSIZE 100
#define INT 1000
#define HI 100000
#define LOW -9999


#endif // COMMONS_H
