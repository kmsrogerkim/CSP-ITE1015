#include <iostream>
using namespace std;

typedef struct
{
    int xpos;
    int ypos;
} Point;

void getShortest(const Point* points, int n, Point* minP)
{
    int min_d = -1;
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            int d = (points[i].xpos - points[j].xpos)*(points[i].xpos - points[j].xpos) + (points[i].ypos - points[j].ypos)*(points[i].ypos - points[j].ypos);
            if (min_d == -1)
            {
                min_d = d;
                minP[0] = points[i];
                minP[1] = points[j];
            }
            if (d < min_d)
            {
                min_d = d;
                minP[0] = points[i];
                minP[1] = points[j];
            }
        }
    }
}

void getLongest(const Point* points, int n, Point* maxP)
{
    int max_d = -1;
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            int d = (points[i].xpos - points[j].xpos)*(points[i].xpos - points[j].xpos) + (points[i].ypos - points[j].ypos)*(points[i].ypos - points[j].ypos);
            if (max_d == -1)
            {
                max_d = d;
                maxP[0] = points[i];
                maxP[1] = points[j];
            }
            if (d > max_d)
            {
                max_d = d;
                maxP[0] = points[i];
                maxP[1] = points[j];
            }
        }
    }
}

int main()
{
    int a;
    cin >> a;

    Point* pt_arr = new Point[a];
    for (int i=0; i<a; i++)
    {
        cin >> pt_arr[i].xpos;
        cin >> pt_arr[i].ypos;
    }

    Point minP[2];
    Point maxP[2];

    getShortest(pt_arr, a, minP);
    getLongest(pt_arr, a, maxP);

    printf("longest:(%d,%d)(%d,%d)\n", maxP[0].xpos, maxP[0].ypos, maxP[1].xpos, maxP[1].ypos);
    printf("shortest:(%d,%d)(%d,%d)\n", minP[0].xpos, minP[0].ypos, minP[1].xpos, minP[1].ypos);
}
