#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char str[1000]; 
    int img[1024][768];/*画像サイズにあわせて調節が必要*/
    int w, h;/*画像の大きさ*/
    int d;/*画像の階調*/
    int x, y;/*画素を配列imgに読み込むためのループカウンタ*/
    FILE *fp1, *fp2, *fp3;

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
    fscanf(fp1,"%d %d",&w,&h); /*画像の大きさの読込*/
    fscanf(fp1,"%d",&d);       /*画像の階調の読込*/

    /*画像部分を読み込む*/
    for(y = 0; y < h; y++){
        for(x = 0; x < w; x++){
            fscanf(fp1,"%d",&img[x][y]);
        }
    }

    //左右反転
    int img2[1024][768];
    for(y = 0; y < h; y++){
        for(x = 0; x < w; x++){
            img2[w - 1 - x][y] = img[x][y];
        }
    }

    //上下反転
    int img3[1024][768];
    for(y = 0; y < h; y++){
        for(x = 0; x < w; x++){
            img3[x][h - 1 - y] = img[x][y];
        }
    }

    //１８０度回転
    int img4[1024][768];
    for(y = 0; y < h; y++){
        for(x = 0; x < w; x++){
            img4[x][h - 1 - y] = img2[x][y];
        }
    }

    //4枚合成
    int img5[2048][1536];//縦横2倍の配列
    //左半分
    for(y = 0; y < 2 * h; y++){
        for(x = 0; x < w; x++){
            if(y < h){
                img5[x][y] = img[x][y];//上半分
            }else{
                img5[x][y] = img3[x][y - h];//下半分
            }
        }
    }
    //右半分
    for(y = 0; y < h * 2; y++){
        for(x = w; x < 2 * w; x++){
            if(y < h){
                img5[x][y] = img2[x - w][y];//上半分
            }else{
                img5[x][y] = img4[x - w][y - h];//下半分
            }
        }
    }

    /*出力*/
    fprintf(fp2, "%s\n%d %d\n%d\n",str,w*2,h*2,d);/*ヘッダ出力*/
    for(y = 0; y < 2 * h; y++){
        for(x = 0; x < 2 * w; x++){
            fprintf(fp2,"%d ",img5[x][y] );//書き込まれているファイルが正しいかどうか注意
        }
        fprintf(fp2,"\n");
    }

    fclose(fp1);
    fclose(fp2);
 
    return 0;
}
