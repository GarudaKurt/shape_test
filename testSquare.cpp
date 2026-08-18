#include "testSquare.h"
#include <assert.h>
#include <cstdio>

TestSquare::TestSquare(int *area, int *perimeter){
   _area = area;
   _perimeter = perimeter;
}

void TestSquare::PassFailArea() { 
   printf("\n==================\n");
   printf("Unit test for Square is running...\n");
   printf("Test for area of square\n");
   assert(*_area  > 50);
   printf("Test is passed!\n");
}

void TestSquare::PassFailPerimeter() { 
  
   printf("\n==================\n");
   printf("Unit test for Square is running...\n");
   printf("Test for perimeter of square\n");
   assert(*_perimeter > 50);
   printf("Test is passed!\n");

}
