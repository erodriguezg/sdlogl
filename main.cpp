#include "Display.h"

int main() {
    Display display(800, 600, "Hello world");
    while (!display.isClosed()) {
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);
        display.update();
    }
    return 0;
}