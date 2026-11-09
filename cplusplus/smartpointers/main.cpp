#include <iostream>

#include <memory>

using namespace std;
int main() {
   std::unique_ptr<int> foo;
   std::unique_ptr<int> bar;
   int * p = nullptr;

   foo = std::unique_ptr<int>(new int (10));
   p = foo.get();
   
   if(p)
       printf("Value of pointer %d\n",*p);
   foo.reset(new int);
   *foo = 15;
   std::cout<<"Value of foo ptr: "<<*foo<<std::endl;
   printf("Test test"); 
   return 0;
}
