#include "philosophers.h"

unsigned long long get_time(void)
{
    struct timeval time;

    if(gettimeofday(&time, NULL) == -1)
        return (0);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
