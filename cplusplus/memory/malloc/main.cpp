#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void copydata(const char* buffer, unsigned int buffer_size) { 
    
    while(buffer_size > 0) { 
        printf("%c ", *buffer);
	buffer++;
	buffer_size = buffer_size - 1;
    }
    printf("\n");
}

int main() {
    const char data[] = {'H', 'E', 'L', 'L', 'O', 'W', 'O', 'R', 'L', 'D','\0'};
    std::vector<const char*> newdata;
    char * temp = NULL;
    printf("Before \n");
    copydata(data, sizeof(data));

    printf("After using memory\n");
    temp = (char*)malloc(sizeof(data));
    memcpy(temp, data, sizeof(data));
    copydata(temp, sizeof(data));
    
    printf("List of data\n");
    for(auto it = std::begin(data); it != std::end(data); it++) {
       newdata.push_back(it);
    }

    for(auto it = std::begin(newdata); it != std::end(newdata); it++) { 
        printf("%s \n",*it);
    }

    free(temp);
    return 0;
}
