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

void decrement_date(int *y, int *m, int *d)
{
    (*d)--;
    if (*d == 0)
    {
        (*m)--;
        if (*m == 0)
        {
            *m = 12;
            (*y)--;
        }
        *d = days[uruu(*y)][*m];
    }
    return;
}

void increment_date(int *y, int *m, int *d)
{
    (*d)++;
    if (*d > days[uruu(*y)][*m])
    {
        *d = 1;
        (*m)++;
        if (*m > 12)
        {
            *m = 1;
            (*y)++;
        }
    }
    return;
}

void week_later(int *y, int *m, int *d)
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
    return;
}

void week_ago(int *y, int *m, int *d)
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
    return;
}

int main(int argc, char **argv)
{
    int year, mon, day;

    year = atoi(argv[1]);
    mon = atoi(argv[2]);
    day = atoi(argv[3]);

    printf("西暦%d年%d月%d日の次の日は、", year, mon, day);
    increment_date(&year, &mon, &day);
    printf("%d年%d月%d日です。\n", year, mon, day);

    year = atoi(argv[1]);
    mon = atoi(argv[2]);
    day = atoi(argv[3]);

    printf("西暦%d年%d月%d日の前の日は、", year, mon, day);
    decrement_date(&year, &mon, &day);
    printf("%d年%d月%d日です。\n", year, mon, day);

    year = atoi(argv[1]);
    mon = atoi(argv[2]);
    day = atoi(argv[3]);

    printf("西暦%d年%d月%d日の1週間後は、", year, mon, day);
    week_later(&year, &mon, &day);
    printf("%d年%d月%d日です。\n", year, mon, day);

    year = atoi(argv[1]);
    mon = atoi(argv[2]);
    day = atoi(argv[3]);

    printf("西暦%d年%d月%d日の1週間前は、", year, mon, day);
    week_ago(&year, &mon, &day);
    printf("%d年%d月%d日です。\n", year, mon, day);

    return 0;
}
