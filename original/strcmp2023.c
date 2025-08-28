#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main( int argc, char **argv)
{
    int res = strcmp( argv[1], argv[2] );

    if( res == 0 ) {
	printf( "\"%s\" = \"%s\"\n", argv[1],argv[2] );
    }
    else if( res > 0 ) {
	printf( "\"%s\" > \"%s\"\n", argv[1],argv[2] );
    }
    else{
	printf( "\"%s\" < \"%s\"\n", argv[1],argv[2] );
    }
    

    return 0;
}
