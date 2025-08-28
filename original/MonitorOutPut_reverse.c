#include <stdio.h>
#include <stdlib.h>

//白黒反転プログラム
int main(int argc, char **argv)
{
    char str[1000]; 
    int img[1024][768];/*画像サイズにあわせて調節が必要*/
    int w, h;/*画像の大きさ*/
    int d;/*画像の階調*/
    int x, y;/*画素を配列imgに読み込むためのループカウンタ*/
    FILE *fp1, *fp2;

    //入力用のファイルの準備
    if((fp1 = fopen( argv[1],"r")) == NULL){
	perror( argv[1]);
	exit(1);
    }

    //出力用のファイルの準備
    if((fp2 = fopen( argv[2],"w")) == NULL){
        perror( argv[2]);
	exit(1);
    }

    /*ヘッダの読込み*/
    fscanf(fp1,"%s",str);      /*マジックナンバーの読込  */
    fscanf(fp1,"%d %d",&w,&h);/*画像の大きさの読込*/
    fscanf(fp1,"%d",&d);       /*画像の階調の読込*/

    /*画像部分を読み込む*/
    for(y = 0; y < h; y++){
	for(x = 0; x < w; x++){
	    fscanf(fp1,"%d",&img[x][y]);
	}
    }

    int img2[1024][768]; //反転後の配列

    
    /*左右反転*/
    
    for(y = 0; y < h; y++){
	for(x = 0; x < w; x++){
	    img2[w - 1 - x][y] = img[x][y];
	}
    }
    

    /*上下反転*/
    for(y = 0; y < h; y++){
	for(x = 0; x < w; x++){
	    img[x][h - 1 - y] = img2[x][y];
	}
    }

    /*出力*/
    fprintf(fp2, "%s\n%d %d\n%d\n",str,w,h,d);/*ヘッダ出力*/
    for(y = 0; y < h; y++){
	for(x = 0; x < w; x++){
	    fprintf(fp2,"%d ",img[x][y]);
	}
	fprintf(fp2,"\n");
    }

    fclose(fp1);
    fclose(fp2);
 
    return 0;
}
