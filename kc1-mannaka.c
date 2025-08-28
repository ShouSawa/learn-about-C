#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int res1 = strcmp( argv[1], argv[2] );
    int res2,res3;

    if( res1 > 0 ){ // 1 > 2
	res2 = strcmp( argv[1], argv[3] );
	if( res2 < 0 ){ // 3 > 1 > 2
	    printf("中央の値は\"%s\"です。\n",argv[1]);
	}
	else { // 1 > 3
	    res3 = strcmp( argv[2], argv[3] );
	    if( res3 > 0 ){ // 1 > 2 > 3
		printf("中央の値は\"%s\"です。\n",argv[2]);
	    }
	    else { // 1 > 3 > 2
	        printf("中央の値は\"%s\"です。\n",argv[3]);
	    }
	}    
    }
    else { // 2 > 1
	res2 = strcmp( argv[2], argv[3] );
	if( res2 < 0 ){ // 3 > 2 > 1
	    printf("中央の値は\"%s\"です。\n",argv[2]);
	}
	else { // 2 > 3
	    res3 = strcmp( argv[1], argv[3] );
	    if( res3 > 0 ){ // 2 > 1 > 3
	        printf("中央の値は\"%s\"です。\n",argv[1]);
	    }
	    else { // 2 > 3 > 1
	        printf("中央の値は\"%s\"です。\n",argv[3]);
	    }
	}  
    }

    return 0;
}
