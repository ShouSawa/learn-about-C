#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char str[1000];
    int img[640][480]; /*画像サイズにあわせて調節が必要*/
    int w, h;          /*画像の大きさ*/
    int d;             /*画像の階調*/
    int x, y;          /*画素を配列imgに読み込むためのループカウンタ*/
    FILE *fp1, *fp2, *fp3;

    // 入力用のファイルの準備
    if ((fp1 = fopen(argv[1], "r")) == NULL)
    {
        perror(argv[1]);
        exit(1);
    }

    // 出力用のファイルの準備
    if ((fp2 = fopen(argv[2], "w")) == NULL)
    {
        perror(argv[2]);
        exit(1);
    }

    /*ヘッダの読込み*/
    fscanf(fp1, "%s", str);       /*マジックナンバーの読込  */
    fscanf(fp1, "%d %d", &w, &h); /*画像の大きさの読込*/
    fscanf(fp1, "%d", &d);        /*画像の階調の読込*/

    /*画像部分を読み込む*/
    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            fscanf(fp1, "%d", &img[x][y]);
        }
    }

    int img2[160][120]; // 出力用配列

    /*画像縮小*/
        int w2 = w/2;   //ヘッダー(幅)を1/2に
        int h2 = h/2;   //ヘッダー(高さ)を1/2に
        for(y = 0; y < h2; y++){
            for(x = 0; x < w2; x++){
                img2[x][y] = img[2*x][2*y];
            }
        }
    

    /*2値化
        for(y = 0; y < h; y++){
            for(x = 0; x < w; x++){
                if(img[x][y] > 50){
                    img2[x][y] = 255;
                }else{
                    img2[x][y] = 0;
                }
            }
        }
    */

    /*白黒反転
    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            img2[x][y] = 255 - img[x][y];
        }
    }
    */

    /*左右反転
        for(y = 0; y < h; y++){
            for(x = 0; x < w; x++){
                img2[w2 - 1 - x][y] = img[x][y];
            }
        }
    */

    /*上下反転
        for(y = 0; y < h; y++){
            for(x = 0; x < w; x++){
                img2[x][h2 - 1 - y] = img[x][y];
            }
        }
    */

    /*右に90度回転
        int img2[240][320];
        for(y = 0; y < h; y++){
            for(x = 0; x < w; x++){
                img2[h - 1 - y][x] = img[x][y];
            }
        }
    */

    /*左に90度回転
        int img2[240][320];
        for(y = 0; y < h; y++){
            for(x = 0; x < w; x++){
                img2[y][w - 1 - x] = img[x][y];
            }
        }
    */

    /*合成する画像の準備
        char str2[1000];
        int w2, h2;//画像の大きさ
        int d2;//画像の階調

        //入力用2のファイルの準備
        if((fp3 = fopen( argv[3],"r")) == NULL){
            perror( argv[3]);
            exit(1);
        }

        //ヘッダの読込み
        fscanf(fp3,"%s",str2);      //マジックナンバーの読込
        fscanf(fp3,"%d %d",&w2,&h2); //画像の大きさの読込
        fscanf(fp3,"%d",&d2);       //画像の階調の読込

        int img3[320][240];
        //画像部分を読み込む
        for(y = 0; y < h2; y++){
            for(x = 0; x < w2; x++){
                fscanf(fp3,"%d",&img3[x][y]);
            }
        }
    */

    /*縦に合体
        for(y = 0; y < h+h2; y++){
            for(x = 0; x < w; x++){
                if(y < h){
                    img2[x][y] = img[x][y];//上半分
                }else{
                    img2[x][y] = img3[x][y - h];//下半分
                }
            }
        }
    //*/

    /*横に合体
        for(y = 0; y < h; y++){
            for(x = 0; x < w+w2; x++){
                if(x < w){
                    img2[x][y] = img[x][y];//左半分
                }else{
                    img2[x][y] = img3[x - w][y];//右半分
                }
            }
        }
    //*/

    /*出力*/
    fprintf(fp2, "%s\n%d %d\n%d\n", str, w/2, h/2, d); /*ヘッダ出力*/
    for (y = 0; y < h/2; y++)
    {
        for (x = 0; x < w/2; x++)
        {
            fprintf(fp2, "%d ", img2[x][y]); // 書き込まれているファイルが正しいかどうか注意
        }
        fprintf(fp2, "\n");
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
