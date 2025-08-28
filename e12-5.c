#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define sqr(n)    ((n) * (n))

//点の座標を表す構造体
typedef struct
{
    double x;
    double y;
} Point;

//自動車を表す構造体
typedef struct
{
    Point pt;
    double fuel;
} Car;

//点p1と点p2の距離を返す
double distance_of(Point p1, Point p2){
    return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

//自動車の現在位置と残り燃料を表示
void put_info(Car c){
    printf("現在位置：（%.2f, %.2f）\n",c.pt.x, c.pt.y);
    printf("残り燃料：%.2fリットル\n",c.fuel);
}

//cの指す車を目的座標destに移動
int movePoint (Car *c, Point dest){
    double d = distance_of(c -> pt, dest);      //移動距離
    if(d > c->fuel){                            //移動距離が燃料を超過
        return 0;                               //移動不可
    }
    c->pt = dest;       //現在位置を更新（destに移動）
    c->fuel -= d;       //燃料を更新（移動距離dの分だけ減る）
    return 1;           //移動成功
}

//cの指す車を移動距離分だけ移動
int moveDistance (Car *c, double x, double y){
    Point dest;
    dest.x = c->pt.x + x;
    dest.y = c->pt.y + y;
    double d = distance_of(c -> pt, dest);      //移動距離
    if(d > c->fuel){                            //移動距離が燃料を超過
        return 0;                               //移動不可
    }
    c->pt = dest;       //現在位置を更新（destに移動）
    c->fuel -= d;       //燃料を更新（移動距離dの分だけ減る）
    return 1;           //移動成功
}

int main(int argc, char **argv)
{
    Car mycar = {{0.0, 0.0},90.0};

    while(1){
        int select;
        Point dest;         //目的地の座標
        put_info(mycar);    //現在位置と残り燃料を表示
        printf("移動しますか？【Yes・・・1／No・・・0】：");
        scanf("%d",&select);
        if(select != 1){
            break;
        }
        printf("入力方法はどうしますか？【座標入力・・・1／移動距離入力・・・0】：");
        scanf("%d",&select);
        if(select == 1){
            printf("目的地のx座標："); scanf("%lf",&dest.x);
            printf("目的地のy座標："); scanf("%lf",&dest.y);
            if(!movePoint(&mycar,dest)){
                puts("\a燃料不足で移動できません．");
            }
        }else{
            double x,y;
            printf("移動したいx座標："); scanf("%lf",&x);
            printf("移動したいy座標："); scanf("%lf",&y);
            if(!moveDistance(&mycar,x,y)){
                puts("\a燃料不足で移動できません．");
            }
        }
    }
    
    return 0;
}