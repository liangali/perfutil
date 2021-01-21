#include "perf.h"

void test_perfutil_1()
{
    PFU_ENTER;

    double sum = 0;
    for (size_t i = 0; i < 100000; i++)
    {
        sum += i;
    }

    PFU_LEAVE;
}

void test_perfutil_2()
{
    PFU_START("first-block");
    double sum = 0;
    for (size_t i = 0; i < 100000; i++)
    {
        sum += i;
    }
    PFU_STOP("first-block");

    PFU_START("sencond-block");
    sum = 0;
    for (size_t i = 0; i < 100000; i++)
    {
        sum += i;
    }
    PFU_STOP("sencond-block");
}

int main() 
{
    for (size_t i = 0; i < 10; i++)
    {
        test_perfutil_1();
        test_perfutil_2();
    }
    return 0;
}