#include <cstdio>
#include <cstring>
#include "EnginedDebugSingleton.h"

int main() {
    printf("Hello World\n");

    auto& logger = Logger::Instance();
    logger.Warning("This warning errors");
    logger.Info("This test info\n");
    logger.Error("This is error\n");
    return 0;
}
