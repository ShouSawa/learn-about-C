#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct nengappi
{
    int year; /* 年 */
    int mon;  /* 月 */
    int day;  /* 日 */
} NGP;

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

// n日前に更新する関数(中のnをいじる)
NGP dec_nday(NGP x)
{
    int year = x.year;
    int month = x.mon;
    int day = x.day;
    int n = 1;
    if (n < 0)
    {
        n *= -1;
    }
    for (int i = 0; i < n; i++)
    {
        (day)--;
        if (day == 0)
        {
            (month)--;
            if (month == 0)
            {
                month = 12;
                (year)--;
            }
            day = days[uruu(year)][month];
        }
    }
    x.year = year;
    x.mon = month;
    x.day = day;
    return x;
}

// n日後に更新する関数(中のnをいじる)
NGP inc_nday(NGP x)
{
    int year = x.year;
    int month = x.mon;
    int day = x.day;
    int n = 1;
    if (n < 0)
    {
        n *= -1;
    }
    for (int i = 0; i < n; i++)
    {
        (day)++;
        if (day > days[uruu(year)][month])
        {
            day = 1;
            (month)++;
            if (month > 12)
            {
                month = 1;
                (year)++;
            }
        }
    }
    x.year = year;
    x.mon = month;
    x.day = day;
    return x;
}

//nが+ならn日後，nが-ならn日前を表示
void dec_inc_nday(int *y, int *m, int *d, int n)
{
    int year = *y;
    int month = *m;
    int day = *d;
    if (n < 0)
    {
        n *= -1;
        printf("%d年%d月%d日の%d日前は", year, month, day, n);

        for (int i = 0; i < n; i++)
        {
            (day)--;
            if (day == 0)
            {
                (month)--;
                if (month == 0)
                {
                    month = 12;
                    (year)--;
                }
                day = days[uruu(year)][month];
            }
        }

        
        
    }
    else if (n > 0)
    {
        printf("%d年%d月%d日の%d日後は", year, month, day, n);
        for (int i = 0; i < n; i++)
        {
            (day)++;
            if (day > days[uruu(year)][month])
            {
                day = 1;
                (month)++;
                if (month > 12)
                {
                    month = 1;
                    (year)++;
                }
            }
        }

    }
    printf("%d年%d月%d日です。\n", year, month, day);
    *y = year;
    *m = month;
    *d = day;
}

//4日前の年月日を返す
NGP dec4_date(NGP x)
{
    int year = x.year;
    int month = x.mon;
    int day = x.day;
    int n = 4;
    if (n < 0)
    {
        n *= -1;
    }
    for (int i = 0; i < n; i++)
    {
        (day)--;
        if (day == 0)
        {
            (month)--;
            if (month == 0)
            {
                month = 12;
                (year)--;
            }
            day = days[uruu(year)][month];
        }
    }
    x.year = year;
    x.mon = month;
    x.day = day;
    return x;
}

//2日後の年月日を返す
NGP inc2_date(NGP x)
{
    int year = x.year;
    int month = x.mon;
    int day = x.day;
    int n = 2;
    if (n < 0)
    {
        n *= -1;
    }
    for (int i = 0; i < n; i++)
    {
        (day)++;
        if (day > days[uruu(year)][month])
        {
            day = 1;
            (month)++;
            if (month > 12)
            {
                month = 1;
                (year)++;
            }
        }
    }
    x.year = year;
    x.mon = month;
    x.day = day;
    return x;
}

int main(int argc, char **argv)
{
    NGP x, ans;

    int year, mon, day;
    x.year = atoi(argv[1]);
    x.mon = atoi(argv[2]);
    x.day = atoi(argv[3]);

    int n;
    n = atoi(argv[4]);

    printf("%d年%d月%d日の%d日前は", x.year, x.mon, x.day, n);
    ans = dec_nday(x);
    printf("%d年%d月%d日です。\n", ans.year, ans.mon, ans.day);

    printf("%d年%d月%d日の%d日後は", x.year, x.mon, x.day, n);
    ans = inc_nday(x);
    printf("%d年%d月%d日です。\n", ans.year, ans.mon, ans.day);

    year = atoi(argv[1]);
    mon = atoi(argv[2]);
    day = atoi(argv[3]);
    dec_inc_nday(&year, &mon, &day, n);
    puts("");

    printf("%d年%d月%d日の4日前は", x.year, x.mon, x.day);
    ans = dec4_date(x);
    printf("%d年%d月%d日です。\n", ans.year, ans.mon, ans.day);

    printf("%d年%d月%d日の2日後は", x.year, x.mon, x.day);
    ans = inc2_date(x);
    printf("%d年%d月%d日です。\n", ans.year, ans.mon, ans.day);


    return 0;
}
