#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "root.h"

ans root(float a, float b, float c){


    ans cur;

    if(a == b && b == c && c == 0){
        cur.count = 3;
        printf("any solution\n");
        return cur;
    }

    double x = 0;
    double y = 0;

    if(a == 0){
        if(b != 0){
            cur.x = -c;
            cur.count = 1;
        } else {
            printf("no roots\n");
            cur.count = 0;
        }

        return cur;
    }


    double d;
    d = b*b - 4*a*c;
    if(d < 0){
        cur.count = 0;
        printf("no roots\n");
    } else {
        if(d != 0){
            cur.count = 2;
            cur.x = (-b + sqrt(d)) / (2 * a);
            cur.y = (-b - sqrt(d)) / (2 * a);
            if(x < y){
                double ptr = cur.x;
                cur.x = cur.y;
                cur.y = ptr;
            }
            printf("x = %.3f, y = %.3f\n", cur.x, cur.y);
        } else {
            cur.count = 1;
            cur.x = -b / (2*a);
            printf("x = %.3f\n", cur.x);
        }
    }

    return cur;
}
