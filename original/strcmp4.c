#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main( int argc, char **argv)
{
    int i,res,min;

    res = strcmp( argv[1], argv[2] );
    if( res <= 0 ){
	    min = 1;
    }else{
	    min = 2;
    }
    
    for( i = 3; i < argc; i++ ){
        res = strcmp( argv[i], argv[min]);
        if( res < 0 ){
            min = i;
        }
    }

    int ans = atoi(argv[min]);

    printf( "%d\n" , ans);

    return 0;
}
