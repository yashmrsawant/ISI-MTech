#include "commons.h"
#include "gnuplot.h"

void solution(int* numbers_p, int size, int* aux_p);
struct timeval time_start;
struct timeval time_end;

void getsample(int* numbers_p, int size) {
    gettimeofday(&time_start, NULL);

    srand(time_start.tv_usec);
    int i = 0;
    for(; i < size ; i ++) {
        numbers_p[i] = rand() % (HI - LOW) + LOW;
    }
}
inline void copy(int* n_p_dest, int* n_p_src, int size) {
    int i = 0;
    while(i < size) {
        n_p_dest[i] = n_p_src[i];
        i ++;
    }
}

int main(int argc, char *argv[])
{
    int numbers_p[INTEGERARRSIZE];
    int aux_p[INTEGERARRSIZE];
    int numbers_pa[INTEGERARRSIZE];
    float timeinus_iter_heapsort;
    float timeinus_rec_heapsort;
    float timeinus_iter_mergesort;
    float timeinus_rec_mergesort;
    float timeinus_iter_quicksort;
    float timeinus_rec_quicksort;

    FILE* data = fopen("data_quick.dat", "w");
    for(int i = 100 ; i < XDATASIZE ; i += INT) {
        timeinus_iter_heapsort = 0.0;
        timeinus_rec_heapsort = 0.0;
        timeinus_iter_mergesort = 0.0;
        timeinus_rec_mergesort = 0.0;
        timeinus_iter_quicksort = 0.0;
        timeinus_rec_quicksort = 0.0;
        for(int j = 0 ; j < MEANSIZE ; j ++) {
            getsample(numbers_p, i);

            copy(numbers_pa, numbers_p, i);

            //heapsort_recursive(numbers_p, i, aux_p, &time_start, &time_end);
            //timeinus_rec_heapsort = timeinus_rec_heapsort + (time_end.tv_sec - time_start.tv_sec) * 1000000 + (time_end.tv_usec - time_start.tv_usec);

            //copy(numbers_p, numbers_pa, i);

            //heapsort_iterative(numbers_p, i, aux_p, &time_start, &time_end);
            //timeinus_iter_heapsort = timeinus_iter_heapsort + (time_end.tv_sec - time_start.tv_sec) * 1000000 + (time_end.tv_usec - time_start.tv_usec);

            //copy(numbers_p, numbers_pa, i);

            //mergesort_iterative(numbers_p, i, aux_p, &time_start, &time_end);
            //timeinus_iter_mergesort = timeinus_iter_mergesort + (time_end.tv_sec - time_start.tv_sec) * 1000000 + (time_end.tv_usec - time_start.tv_usec);

            //copy(numbers_p, numbers_pa, i);

            //mergesort_recursive(numbers_p, i, aux_p, &time_start, &time_end);
            //timeinus_rec_mergesort = timeinus_rec_mergesort + (time_end.tv_sec - time_start.tv_sec) * 1000000 + (time_end.tv_usec - time_start.tv_usec);

            //copy(numbers_p, numbers_pa, i);

            quicksort_iterative(numbers_p, i, aux_p, &time_start, &time_end);
            timeinus_iter_quicksort = timeinus_iter_quicksort + (time_end.tv_sec - time_start.tv_sec) * 1000000 + (time_end.tv_usec - time_start.tv_usec);

            copy(numbers_p, numbers_pa, i);

            quicksort_recursive(numbers_p, i, &time_start, &time_end);
            timeinus_rec_quicksort = timeinus_rec_quicksort + (time_end.tv_sec - time_start.tv_sec) * 1000000 + (time_end.tv_usec - time_start.tv_usec);
        }
        fprintf(data, "%ld %lf %lf %lf\n", i,timeinus_iter_quicksort / MEANSIZE, timeinus_rec_quicksort / MEANSIZE);
    }


    fclose(data);
    //solution();
    return 0;
}
