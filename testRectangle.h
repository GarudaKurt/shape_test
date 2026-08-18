#ifndef __TESTRECTANGLE__H
#define __TESTRECTANGLE__H

class TestRectangle {
   public:
	   TestRectangle(int *area, int *perimeter);
	   void PassFailArea();
	   void PassFailPerimeter();
   private:
	   int* _area;
	   int* _perimeter;

};
#endif
