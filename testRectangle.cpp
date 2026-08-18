#include <cstdio>
#include <cassert>
#include "testRectangle.h"

TestRectangle::TestRectangle(int* area, int* perimeter) { 
   _area = area;
   _perimeter = perimeter;
}


void TestRectangle::PassFailArea() { 
    printf("\n====================\n");
    printf("Unit test for Rectangle is running\n");
    printf("Test for Area of Rectangle\n");
    assert(*_area > 50);
    printf("Test is passed\n");
}

void TestRectangle::PassFailPerimeter() {

    printf("\n====================\n");
    printf("Unit test for Rectangle is running\n");

    printf("Test for Area of Rectangle\n");
    assert(*_perimeter > 50);
    printf("Test is passed!\n");
}
