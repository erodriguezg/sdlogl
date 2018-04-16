#include "Display.h"
#include "Shader.h"
#include "Mesh.h"


int main() {
    Display display(800, 600, "Hello world");

    Vertex vertices[] = {
            Vertex(glm::vec3(-0.5, -0.5, 0)),
            Vertex(glm::vec3(0.0, 0.5, 0)),
            Vertex(glm::vec3(0.5, -0.5, 0))
    };

    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

    Shader shader("./res/basicShader");
    while (!display.isClosed()) {
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);
        shader.bind();

        mesh.draw();

        display.update();
    }
    return 0;
}