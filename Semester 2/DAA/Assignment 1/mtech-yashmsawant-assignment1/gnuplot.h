#ifndef GNUPLOT_H
#define GNUPLOT_H

#include <string.h>
#ifdef _WIN32

char* command = "gnuplot -persistent";
FILE* gnuplotpipe = _popen(command, "w");

#elif
#endif

#endif // GNUPLOT_H
