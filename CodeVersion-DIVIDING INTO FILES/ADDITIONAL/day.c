#include <stdio.h>
#include <time.h>

int jour()
{   int res;
    time_t s, val = 1;
    struct tm* current_time;
    
    s = time(NULL);
    
    current_time = localtime(&s);
    res = current_time->tm_mday;
    return res;
}