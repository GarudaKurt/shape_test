#include <iostream>

#define N_ELEMENTS(arr) (sizeof(arr) / sizeof((arr)[0]))
#define SQUARE(x) (x * x)
#define PRINT(x) (x) == "ERROR" ? fprintf(stderr,"ERROR: %s\n",x) : fprintf(stdout,"INFO: %s\n",x);
//#define DEBUG

#ifdef DEBUG
    #define LOG(msg) std::cout<<"[DEBUG] "<<msg<<std::endl;
#else
   #define LOG(msg) std::cout<<"[INFO] "<<msg<<std::endl;
#endif

int main() {
    int array[16] = { 32701, 32702, 32703, 32704, 32705, 32706, 32707, 32708,
	              32709, 32710, 32711, 32712, 32713, 32714, 32715, 32716 };
    int base = array[0];
    std::cout<<"List of numbers"<<std::endl;

    for(int j = 0; j < N_ELEMENTS(array); j++) { 
        printf("%d\n",array[j]);
    }
    std::cout<<"Group by offset"<<std::endl;
    for(int i = 0; i < N_ELEMENTS(array); i++) { 
        
	int current = array[i];
	int offset = current - base;
	
	bool isPlus = (offset % 8 < 4);

	int partner = (isPlus) ? current + 4 : current - 4;
	
	printf("Pair [%d --> %d] \n",current, partner);
    }
    LOG("This is sample macro INFO message");
    LOG("Test Loggers");
   
    return 0;
}
