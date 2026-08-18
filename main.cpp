#include <stdio.h>
#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "testSquare.h"
#include "testRectangle.h"

#define array_length(arr) (sizeof(arr) / sizeof((arr)[0))
int main() { 
   int l1 = 10, w1 = 5;
   int l2 = 10, w2 = 8;
   int Ashape, Pshape, ARshape, PRshape;

   Square shape(&l1, &l2);
   Rectangle rec(&l2, &w2);
   
   Ashape = shape.GetArea();
   Pshape = shape.GetPerimeter();
   ARshape = rec.GetArea();
   PRshape = rec.GetPerimeter();

   TestSquare t1(&Ashape, &Pshape);
   TestRectangle t2(&ARshape, &PRshape);
   
   printf("OOP Shape\n");
   printf("Area of square %d\n", shape.GetArea());
   printf("Perimeter of square %d\n",shape.GetPerimeter());
   printf("==========================\n");
   printf("Area of rectangle %d\n ", rec.GetArea());
   printf("Perimeter of rectangle %d\n", rec.GetPerimeter());
   printf("==========================\n");
   t1.PassFailArea();
   t1.PassFailPerimeter();   
   t2.PassFailArea();
   t2.PassFailPerimeter();
   
   return 0;
}
