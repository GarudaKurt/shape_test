#ifndef __TESTSQUARE__H
#define __TESTSQUARE__H

class TestSquare {
   public:
	TestSquare(int* area, int* perimeter);
        void PassFailArea();
	void PassFailPerimeter();
   private:
	int* _area;
	int* _perimeter;
};
#endif
