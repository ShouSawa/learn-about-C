#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct {
    int year;
    int mon;
    int day;
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

//n日前に更新する関数
NGP dec_nday(NGP x){
    int year = x.year;
    int month = x.mon;
    int day = x.day;
    int n = 1;
    if(n < 0){
	n *= -1;
    }
    for(int i = 0; i < n; i++){
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
    x.mon  = month;
    x.day = day;
    return x;
}

//n日後に更新する関数
NGP inc_nday(NGP x)
{
    int year = x.year;
    int month = x.mon;
    int day = x.day;
    int n = 1;
        if(n < 0){
	n *= -1;
    }
    for(int i = 0; i < n; i++){
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
    x.mon  = month;
    x.day = day;
    return x;
}

void dec_inc_nday(int *y, int *m, int *d, int n){

    int year = *y;
    int month = *m;
    int day = *d;
    if(n < 0){
	n *= -1;

	for(int i = 0; i < n; i++){
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

	printf("%d年%d月%d日の%d日前は", year, month, day, n);
	printf("%d年%d月%d日です。\n", year, month, day);
    }else if(n > 0){
	for(int i = 0; i < n; i++){
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

	printf("%d年%d月%d日の%d日後は", year, month, day, n);
	printf("%d年%d月%d日です。\n", year, month, day);
    }
    *y = year;
    *m = month;
    *d = day;
    }

int main(int argc, char **argv)
{
    NGP x;
    
    int year, mon, day, n;
    
    x.year = atoi(argv[1]);
    x.mon = atoi(argv[2]);
    x.day = atoi(argv[3]);
    n = atoi(argv[4]);

    printf("%d年%d月%d日の%d日前は", x.year, x.mon, x.day, n);
    x = dec_nday(x);
    printf("%d年%d月%d日です。\n", x.year, x.mon, x.day);

    x.year = atoi(argv[1]);
    x.mon = atoi(argv[2]);
    x.day = atoi(argv[3]);

    printf("%d年%d月%d日の%d日後は", x.year, x.mon, x.day, n);
    x = inc_nday(x);
    printf("%d年%d月%d日です。\n", x.year, x.mon, x.day);
    
     year = atoi(argv[1]);
    mon = atoi(argv[2]);
    day = atoi(argv[3]);
    dec_inc_nday(&year, &mon, &day, n);
    
    return 0;
}
