#include <stdio.h>

typedef struct {
    int s1;
    int s2;
} Sensor;

void getData(Sensor* sensor) { 
    sensor->s1 = 10;
    sensor->s2 = 5;
}
int main() {
    printf("Hello World!\n");
    Sensor sensor = {0};
    getData(&sensor);
    printf("Sensor s1: %d\n",sensor.s1);
    printf("Sensor s2: %d\n",sensor.s2);
    return 0;
}
