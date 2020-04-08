#include <stdio.h>
#include <float.h>
#include "root.h"

int main()
{
    printf("insert a,b,c\n");


    float a, b ,c;

    if(scanf("%f%f%f", &a,&b,&c) != 1){
        return 0;
    }
    root(a, b, c);
    return 0;
}
