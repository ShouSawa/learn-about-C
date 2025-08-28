#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void dec_nday(int *y, int *m, int *d, int n){
    int year = *y;
    int month = *m;
    int day = *d;
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
    *y = year;
    *m = month;
    *d = day;
    return;
}

//n日後に更新する関数
void inc_nday(int *y, int *m, int *d, int n)
{
    int year = *y;
    int month = *m;
    int day = *d;
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
    *y = year;
    *m = month;
    *d = day;
    return;
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
    int year, mon, day, n;
    
    year = atoi(argv[1]);
    mon = atoi(argv[2]);
    day = atoi(argv[3]);
    n = atoi(argv[4]);

    printf("%d年%d月%d日の%d日前は", year, mon, day, n);
    dec_nday(&year, &mon, &day, n);
    printf("%d年%d月%d日です。\n", year, mon, day);

    year = atoi(argv[1]);
    mon = atoi(argv[2]);
    day = atoi(argv[3]);

    printf("%d年%d月%d日の%d日後は", year, mon, day, n);
    inc_nday(&year, &mon, &day, n);
    printf("%d年%d月%d日です。\n", year, mon, day);
    
     year = atoi(argv[1]);
    mon = atoi(argv[2]);
    day = atoi(argv[3]);
    dec_inc_nday(&year, &mon, &day, n);
    
    return 0;
}
