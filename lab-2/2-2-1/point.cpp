#include <iostream>
#include <string>
using namespace std;

typedef struct{
    int xpos;
    int ypos;
} Point;

Point getScalePoint(Point* p, int s){
    Point q;
    q.xpos = p->xpos * s;
    q.ypos = p->ypos * s;
    return q;
}

void swapPoints(Point* p1, Point* p2){
    Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(){
    Point p1;
    Point p2;

    int a, b, c1, c2;
    cin >> a >> b >> c1;
    p1.xpos = a;
    p1.ypos = b;

    cin >> a >> b >> c2;
    p2.xpos = a;
    p2.ypos = b;

    printf("Calling getScalePoint() for (%d, %d)\n", p1.xpos, p1.ypos);
    p1 = getScalePoint(&p1, c1);

    printf("Calling getScalePoint() for (%d, %d)\n", p2.xpos, p2.ypos);
    p2 = getScalePoint(&p2, c2);

    swapPoints(&p1, &p2);
    printf("Calling swapPoints()\nP1 : %d %d\nP2 : %d %d\n", p1.xpos, p1.ypos, p2.xpos, p2.ypos);

    return 0;
}