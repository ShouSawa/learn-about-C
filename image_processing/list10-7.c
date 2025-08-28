#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//#define NUMBER 5

void decrement_date(int *y, int *m, int *d){
    
    if(*d == 1){
	if(*m == 1){
	    (*y)--;
	    *m = 12;
	    *d = 31;
	}else{
	    (*m)--;
	    *d = 31;
	}
	*d = 31;
    }
}

void increment_date(int *y, int *m, int *d){
    
    if(*d == 31){
	if(*m == 12){
	    (*y)++;
	    *m = 1;
	    *d = 1;
	}else{
	    (*m)++;
	    *d = 1;
	}
	*d = 1;
    }
}




int main(int argc, char **argv)
{
    int year,mon,day;

    year = atoi( argv[1] );
    mon  = atoi( argv[2] );
    day  = atoi( argv[3] );

    printf( "西暦%d年%d月%d日の次の日は、",year,mon,day );
    increment_date( &year, &mon, &day );
    printf( "%d年%d月%d日です。\n",year,mon,day );

    year = atoi( argv[1] );
    mon  = atoi( argv[2] );
    day  = atoi( argv[3] );

    printf( "西暦%d年%d月%d日の前の日は、",year,mon,day );
    increment_date( &year, &mon, &day );
    printf( "%d年%d月%d日です。\n",year,mon,day );
    
    
    return 0;
}
