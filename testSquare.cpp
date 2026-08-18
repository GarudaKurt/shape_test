#include "Square.h"
#include <cstdio>
#include <cassert>

void TestArea() { 
    int length = 10, width = 10;
    Square square(&length, &width);
    printf("Testing Square area\n");
    assert(square.GetArea() == 100);
}

void TestPerimeter() { 
   int length = 40, width = 10;
   Square square(&length, &width);
   printf("Testing Square Perimeter\n");
   assert(square.GetPerimeter() == 100);
}


int main() { 
    TestArea();
    TestPerimeter();
    
    printf("All test is passed!\n");
    return 0;

}
