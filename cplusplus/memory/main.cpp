#include <stdlib.h>
#include <stdio.h>
#include <cstring>

enum class Department { 
    IT,
    DEV,
    HR,
    ACCOUNTING
};
typedef struct {
    int id;
    char name[20];
    float salary;
    int departmentId;
} Employee;


int main() { 
    Employee emp1;

    memset(&emp1, 0, sizeof(emp1));
    printf("Emp1 ID after memset: %d\n", emp1.id);

    Employee emp2;
    emp2.id = 101;
    strcpy(emp2.name, "Alice");
    emp2.salary = 1500.50;
    emp2.departmentId = static_cast<int>(Department::ACCOUNTING);

    memcpy(&emp1, &emp2, sizeof(Employee));
    printf("Emp1 Name after memcpy: %s\n",emp1.name);
    printf("Employee department %d\n",emp1.departmentId);
    return 0;
}
