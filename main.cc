#include "scene.h"
#include "buildSnowman.cpp"


int main() {
    Scene* wonderland = new Scene();
    wonderland->build();
    return 1;
}