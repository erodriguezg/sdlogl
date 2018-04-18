#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"

int main() {
    Display display(800, 600, "Hello world");

    Vertex vertices[] = {
            Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
            Vertex(glm::vec3(0.0, 0.5, 0), glm::vec2(0.5, 1.0)),
            Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0))
    };

    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
    Shader shader("./res/basicShader");
    Texture texture("./res/bricks.jpg");
    Transform transform;

    float counter = 0.0f;

    while (!display.isClosed()) {
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);

        float sinCounter = sinf(counter);
        float cosCounter = cosf(counter);

        transform.getPosition().x = sinf(counter);
        transform.getRotation().z = counter;
        transform.setScale(glm::vec3(cosCounter, cosCounter, cosCounter));

        shader.bind();
        texture.bind(0);
        shader.update(transform);
        mesh.draw();
        display.update();

        counter += 0.03f;
    }
    return 0;
}