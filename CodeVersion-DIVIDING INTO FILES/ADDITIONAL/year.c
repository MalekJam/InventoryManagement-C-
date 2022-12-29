#include <stdio.h>
#include <time.h>

int year(void)
{
    int res;
    time_t s, val = 1;
    struct tm* current_time;
    
    s = time(NULL);
    
    current_time = localtime(&s);
    res=current_time->tm_year + 1900;
    return res;
}