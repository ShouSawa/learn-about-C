#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
void increment_date(int *y,int *m,int *d){
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // うるう年なら2月の日数を修正
    if (isLeapYear(*y)) {
        daysInMonth[2] = 29;
    }
    // 日付を更新
    (*d)++;
    // 月が変わる場合
    if (*d > daysInMonth[*m]) {
        *d = 1;
        (*m)++;
        // 年が変わる場合
        if (*m > 12) {
            *m = 1;
            (*y)++;
        }
    }
    return;
}
void decrement_date(int *y,int *m,int *d){
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // うるう年なら2月の日数を修正
    if (isLeapYear(*y)) {
        daysInMonth[2] = 29;
    }
    // 日付を更新
    (*d)--;
    // 月が変わる場合
    if (*d < 1) {
        (*m)--;
        // 年が変わる場合
        if (*m < 1) {
            *m = 12;
            (*y)--;
        }
        // 前月の日数を考慮
        *d = daysInMonth[*m];
    }
    return;
}
int main( int argc, char** argv )
{
    int year,mon,day;
    year = atoi(argv[1]);
    mon = atoi(argv[2]);
    day = atoi(argv[3]);
    printf("西暦%d年%d月%d日の次の日は",year,mon,day);
    increment_date(&year,&mon,&day);
    printf("西暦%d年%d月%d日\n",year,mon,day);
    year = atoi(argv[1]);
    mon = atoi(argv[2]);
    day = atoi(argv[3]);
    printf("西暦%d年%d月%d日の前の日は",year,mon,day);
    decrement_date(&year,&mon,&day);
    printf("西暦%d年%d月%d日\n",year,mon,day);
    return 0;
}