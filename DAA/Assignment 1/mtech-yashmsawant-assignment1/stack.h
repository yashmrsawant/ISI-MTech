#ifndef STACK_H
#define STACK_H

#define STACKSIZE 1000

typedef struct interval {
    int p;
    int q;
} Interval;
Interval** stack = (Interval**)(malloc(sizeof(Interval) * STACKSIZE));
#endif // STACK_H
