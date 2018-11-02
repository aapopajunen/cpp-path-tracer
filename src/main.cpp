#include <glm/glm.hpp>

#include "shader.hpp"
#include "display.hpp"
#include "texture.hpp"
#include "mesh.hpp"
#include "transform.hpp"
#include "camera.hpp"

int main(int argc, char *argv[]){
	int width = 600, height = 480;
	Display display(width, height);
	Shader shader("../shaders/basicShader");
	Texture texture("../textures/testTexture.jpg");
	Mesh mesh("../models/susanne.obj");
	Transform transform;
    Camera camera(glm::vec3(0.0f, 0.0f, 0.0f), 70.0f, (float)width/(float)height, 0.01f, 1000.0f);
	shader.bind();
	while(display.isOpen()){
		display.clear();
		camera.move();
		texture.bind(0);
		transform.update(glm::vec3(-0.7f, 0.0f, 5.7f), glm::vec3(0.0f, 3.0f, 0.0f));
		shader.update(transform, camera);
		mesh.draw();
		display.update();
	}
	return 0;
}
