#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} point;

point* read(int n, point* arr) {
    arr = malloc(n*sizeof(point));
    for (int i=0; i<n; i++) {
        scanf("%f %f", &arr[i].x, &arr[i].y);
    }
    return arr;
}

point average(int n, point* arr) {
    point average;
    average.x=0;average.y=0;
    for (int i=0; i<n; i++) {
        average.x=average.x+arr[i].x;
        average.y=average.y+arr[i].y;
    }
    average.x=average.x/n;
    average.y=average.y/n;
    return average;
}

float pythagor (point first, point second) {
    return sqrt(pow(first.x-second.x, 2)+pow(first.y-second.y, 2));
}

float distance(int n, point* arr, point centre) {
    float distance=pythagor(centre, arr[0]);
    for (int i=1; i<n; i++) {
        if (pythagor(centre, arr[i])>distance) distance=pythagor(centre, arr[i]);
    }
    return distance;
}

int main() {
    printf("number of points\n");
    int n;
    point* arr, centre;
    scanf("%d", &n);
    read(n, arr);
    centre=average(n, arr);
    float radius = distance(n, arr, centre);
    printf("centre in point: %f, %f\nradius: %f", centre.x, centre.y, radius);
    return 0;
}
