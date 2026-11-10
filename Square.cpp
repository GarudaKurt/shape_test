#include "Square.h"


Square::Square(int *length, int *width) : Shape (length, width) {}

int Square::GetArea() { 
    printf("Testing code");
    return GetLength() * GetWidth();
}
int Square::GetPerimeter() {
    return 2 * (GetLength() * GetWidth()); 
}

