#include <stdio.h>
#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#define array_length(arr) (sizeof(arr) / sizeof((arr)[0))
int main() { 
   int l1 = 10, w1 = 5;
   int l2 = 10, w2 = 8;

   Square shape(&l1, &w1);
   Rectangle rec(&l2, &w2);
   
   
   printf("OOP Shape\n");
   printf("Area of square %d\n", shape.GetArea());
   printf("Perimeter of square %d\n",shape.GetPerimeter());
   printf("==========================\n");
   printf("Area of rectangle %d\n ", rec.GetArea());
   printf("Perimeter of rectangle %d\n", rec.GetPerimeter());
   printf("==========================\n");
   
   return 0;
}
