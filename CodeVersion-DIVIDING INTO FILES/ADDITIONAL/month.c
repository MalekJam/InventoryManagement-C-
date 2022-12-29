#include <stdio.h>
#include <time.h>

int month(void)
{
    time_t s, val = 1;
    struct tm* current_time;
    
    s = time(NULL);
    
    current_time = localtime(&s);
    
    return current_time->tm_mon + 1;
}