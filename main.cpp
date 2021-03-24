#include "scene.h"
#include <iostream>
#include <string>


int main(int argc, char** argv) {
    Scene wonderland = Scene();
    wonderland.build();
    wonderland.render_scene();
    wonderland.save_bmp("output.bmp");

    return 0;
}