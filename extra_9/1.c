#include <stdio.h>
#include <math.h>

struct Point{
    double x;
    double y;
};

typedef struct Point Point;

void printPoint(Point p){
    printf("(%.2f, %.2f)\n", p.x, p.y);
}

Point createPoint(double x, double y){
    Point p = {x, y};
    return p;
}

double getDistance(Point a, Point b){
    double x_part = (a.x - b.x) * (a.x - b.x);
    double y_part = (a.y - b.y) * (a.y - b.y);
    return sqrt((x_part + y_part));
}

int main(){
    printf("Distance: %.2f.\n", getDistance(createPoint(2.0, 3.0), createPoint(4.0, 5.0)));
    return 0;
}