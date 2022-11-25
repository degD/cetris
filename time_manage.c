
#include <time.h>

int ms_passed(struct timespec start, struct timespec stop)
{
    int seconds = stop.tv_sec - start.tv_sec;
    long nseconds = stop.tv_nsec - start.tv_nsec;
    
    int time_passed_ms = (seconds*1000) + (nseconds/1000000);
    return time_passed_ms;
}