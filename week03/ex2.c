#include <stdio.h>
#include <math.h>

struct Point{
    float x, y;
};

float distance(struct Point *p1, struct Point *p2){
    float d = sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
    printf("%f\n", d);
}

float area(struct Point *a, struct Point *b, struct Point *c){
    float s = 0.5 * fabs(a->x * b->y - b->x * a->y + b->x * c->y - c->x * b->y + c->x * a->y - a->x * c->y);
    printf("%f\n", s);
}

int main() {
    struct Point a = {2.5, 6};
    struct Point b = {1, 2.2};
    struct Point c = {10, 6};

    distance(&a, &b);
    area(&a, &b, &c);
    return 0;
}
