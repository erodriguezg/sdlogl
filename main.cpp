#include "Display.h"
#include "Shader.h"

int main() {
    Display display(800, 600, "Hello world");
    Shader shader("./res/basicShader");
    while (!display.isClosed()) {
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);
        shader.bind();
        display.update();
    }
    return 0;
}