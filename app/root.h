#ifndef ROOT_H
#define ROOT_H

typedef struct _ans{
    double x;
    double y;
    int count;
    // 0 - no, 3 - any, 4 - wrong format
} ans;

ans root(float a, float b, float c);

#endif
