#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main( int argc, char **argv)
{
    int i,res,max;

    res = strcmp( argv[1], argv[2] );
    if( res >= 0 ){
	    max = 1;
    }else{
	    max = 2;
    }
    
    for( i = 3; i < argc; i++ ){
        res = strcmp( argv[i], argv[max]);

        if( res > 0 ){
            max = i;
        }
	
    }

    printf( "%s\n" , argv[max]);

    return 0;
}
