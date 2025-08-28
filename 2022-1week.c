#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
// #define NUMBER 5

int days[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                   {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int uruu(int y)
{
    if ((y % 400 == 0) || (y % 4 == 0) && (y % 100 != 0))
    { // うるう年の判定
        return 1;
    }
    else
    {
        return 0;
    }
}

void inc1w(int *y, int *m, int *d)
{
    (*d) += 7;
    if (*d > days[uruu(*y)][*m])
    {
        *d = abs(*d - days[uruu(*y)][*m]);
        (*m)++;
        if (*m > 12)
        {
            *m = 1;
            (*y)++;
        }
    }
        printf("西暦%d年%d月%d日の7日前は、", *y, *m, *d);
    printf("%d年%d月%d日です。\n", *y, *m, *d);
    return;
}

void dec1w(int *y, int *m, int *d)
{
    (*d) -= 7;
    if (*d < 0)
    {
        (*m)--;
        if (*m == 0)
        {
            *m = 12;
            (*y)--;
        }
        *d = abs(days[uruu(*y)][*m] + *d);
    }

    printf("西暦%d年%d月%d日の7日前は、", *y, *m, *d);
    printf("%d年%d月%d日です。\n", *y, *m, *d);
    return;
}

int main(int argc, char **argv)
{
    int year, mon, day;
    
    year = atoi(argv[1]);
    mon = atoi(argv[2]);
    day = atoi(argv[3]);

    dec1w(&year, &mon, &day);


    year = atoi(argv[1]);
    mon = atoi(argv[2]);
    day = atoi(argv[3]);

    inc1w(&year, &mon, &day);

    return 0;
}
