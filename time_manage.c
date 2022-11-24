
#include <time.h>

int ms_passed(struct timespec start, struct timespec stop)
{
    int seconds = start.tv_sec - stop.tv_sec;
    long nseconds = start.tv_nsec - stop.tv_nsec;
    
    int time_passed_ms = (seconds*1000) + (nseconds/1000000);
    return time_passed_ms;
}