#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define NUMBER 5

int main(void)
{
    FILE *fp1;
    if ( (fp1 = fopen("test.dat", "r") ) == NULL ){
        perror("test.dat");
        exit(1);
    }

    fprintf(fp1, "%d\n", 1);

    /*
    time_t current = time(NULL);
    struct tm *timer = localtime(&current);

    printf("現在の日付・時刻を書き出しました．\n");
    fprintf(fp1, "%d %d %d %d %d %d\n", 
        timer->tm_year + 1900, timer->tm_mon + 1, timer->tm_mday,
        timer->tm_hour,        timer->tm_min,     timer->tm_sec);
    */
    return 0;
}
