#include "day.h"
#include "month.h"
#include "year.h"
#include "date.h"
#include <stdio.h>



struct date get_date() {
    struct date dt;
    sprintf(dt.d,"%d",jour());
    switch (month())
    {
    case 1:
        sprintf(dt.m,"%s","January");
    case 2:
        sprintf(dt.m,"%s","Februrary");
    case 3:
        sprintf(dt.m,"%s","March");
    case 4:
        sprintf(dt.m,"%s","April");
    case 5:
        sprintf(dt.m,"%s","May");
    case 6:
        sprintf(dt.m,"%s","June");
    case 7:
        sprintf(dt.m,"%s","July");
    case 8:
        sprintf(dt.m,"%s","August");
    case 9:
        sprintf(dt.m,"%s","September");
    case 10:
        sprintf(dt.m,"%s","October");
    case 11:
        sprintf(dt.m,"%s","November");
    case 12:
        sprintf(dt.m,"%s","December");
    }
  dt.y = year();
  return dt;
}












