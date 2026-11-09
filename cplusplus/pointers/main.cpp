#include <iostream>
#include <memory>
#include <vector>
#include <stdlib.h>

class Entity {
    public:
	 Entity() { printf("Created Entitu\n"); }
         ~Entity() { printf("Destroyed Entity\n"); }
         void Print(){ printf("Test\n"); }	

};

int main() { 
    std::unique_ptr<Entity> entity = std::make_unique<Entity>();    
    std::unique_ptr<Entity> e0 = std::move(entity);
    entity->Print();
    return 0;
}
