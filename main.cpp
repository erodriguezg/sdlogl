#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"

#define WITDH 1024
#define HEIGHT 768

int main(int argc, char* args[]) {
    Display display(WITDH, HEIGHT, "Hello world");

    Vertex vertices[] = {
            Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
            Vertex(glm::vec3(0.0, 0.5, 0), glm::vec2(0.5, 1.0)),
            Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0))
    };

    unsigned int indices[] = { 0, 1, 2};

    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
    Mesh mesh2("./res/monkey3.obj");
    Shader shader("./res/basicShader");
    Texture texture("./res/bricks.jpg");
    Camera camera(glm::vec3(0,0,-4), 70.0f, (float)WITDH/(float)HEIGHT, 0.01f, 1000.0f);
    Transform transform;

    float counter = 0.0f;

    while (!display.isClosed()) {
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);

        float sinCounter = sinf(counter);
        float cosCounter = cosf(counter);

        transform.getPosition().x = sinCounter;
        transform.getPosition().z = cosCounter;
        transform.getRotation().x = -0.1;
        transform.getRotation().y = counter *-2;
        transform.getRotation().z = counter;
        //transform.setScale(glm::vec3(cosCounter, cosCounter, cosCounter));

        shader.bind();
        texture.bind(0);
        shader.update(transform, camera);
        mesh2.draw();
        display.update();

        counter += 0.03f;
    }
    return 0;
}