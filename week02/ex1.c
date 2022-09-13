#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int i = INT_MAX;
    unsigned short s = USHRT_MAX;
    long l = LONG_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;
    
    printf("int has a size = %lu bytes\n", sizeof(i));
    printf("unsinged short has a size = %lu bytes\n", sizeof(s));
    printf("long has a size = %lu bytes\n", sizeof(l));
    printf("float has a size = %lu bytes\n", sizeof(f));
    printf("double has a size = %lu bytes\n", sizeof(d));

    printf("\n");

    printf("int has a value = %d\n", i);
    printf("unsinged short has a value = %d\n", s);
    printf("long has a value = %lu\n", l);
    printf("float has a value = %f\n", f);
    printf("double has a value = %f\n", d);

    
    return 0;
}
