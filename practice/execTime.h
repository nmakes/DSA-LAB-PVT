#include <time.h>

clock_t cinitial;
clock_t cfinal;
double time_taken;


#define RECORD_TIME cinitial = clock();
#define STOP_TIME cfinal = clock();
#define CALC_TIME time_taken = ( (double)(cfinal - cinitial) / CLOCKS_PER_SEC * 1000);