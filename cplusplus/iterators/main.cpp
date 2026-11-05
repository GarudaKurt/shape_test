#include <iostream>
#include <vector>

using namespace std;
int main() { 
    int foo[] = {2, 4, 6, 8, 10};
    std::vector<int> bar;

    for(auto it = std::begin(foo); it != std::end(foo); it++) { 
        bar.push_back(*it);
    }
    printf("List of vectors: \n");
    for(auto it = std::begin(bar); it != std::end(bar); it++) { 
        printf("%d\n",*it);
    }
    printf("Testing");
    return 0;
}
