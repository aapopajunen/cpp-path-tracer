#include <stdlib.h>
#include <GL/glew.h>

#include "display.hpp"

Display::Display(int w, int h){
	if(!glfwInit()){
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_SAMPLES, 4);
	width = w;
	height = h;
	window = glfwCreateWindow(width, height, "Testing", NULL, NULL);
	if(!window){
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glewExperimental = true;
	if(glewInit() != GLEW_OK){
		exit(EXIT_FAILURE);
	}
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BACK);
}

Display::~Display(){
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Display::clear(){
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1, 0.1, 0.1, 1.0);
}

void Display::update(){
	glfwSwapBuffers(window);
	glfwPollEvents();
}

bool Display::isOpen(){
	return !glfwWindowShouldClose(window);
}