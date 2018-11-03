#include "eventhandler.hpp"

EventHandler::EventHandler(Display* d, Camera* c){
	display = d;
    camera = c;
	GLFWwindow* window = d->getWindow();

	glfwSetWindowUserPointer(window, this);
	glfwSetWindowSizeCallback(window, windowResize);
	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
}

Display* EventHandler::getDisplay(){
	return display;
}

Camera* EventHandler::getCamera(){
	return camera;
}

void windowResize(GLFWwindow* window, int width, int height){
	EventHandler* eventHandler = reinterpret_cast<EventHandler *>(glfwGetWindowUserPointer(window));
  	eventHandler->getDisplay()->setDimensions(width, height);
	eventHandler->getCamera()->fitViewToWindow((float)width/(float)height);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
	EventHandler* eventHandler = reinterpret_cast<EventHandler *>(glfwGetWindowUserPointer(window));
	if(action == GLFW_PRESS){
		switch(key){
			case GLFW_KEY_W:
                eventHandler->getCamera()->moveZ(0.01);
                break;
            case GLFW_KEY_A:
                eventHandler->getCamera()->moveX(0.01);
                break;
            case GLFW_KEY_S:
                eventHandler->getCamera()->moveZ(-0.01);
                break;
            case GLFW_KEY_D:
                eventHandler->getCamera()->moveX(-0.01);
                break;
            case GLFW_KEY_SPACE:
                eventHandler->getCamera()->moveY(0.01);
                break;
            case GLFW_KEY_LEFT_SHIFT:
                eventHandler->getCamera()->moveY(-0.01);
                break;
            default: break;
		}
	}else if(action == GLFW_RELEASE){
		switch(key){
			case GLFW_KEY_W:
                eventHandler->getCamera()->moveZ(0);
                break;
            case GLFW_KEY_A:
                eventHandler->getCamera()->moveX(0);
                break;
            case GLFW_KEY_S:
                eventHandler->getCamera()->moveZ(0);
                break;
            case GLFW_KEY_D:
                eventHandler->getCamera()->moveX(0);
                break;
            case GLFW_KEY_SPACE:
                eventHandler->getCamera()->moveY(0);
                break;
            case GLFW_KEY_LEFT_SHIFT:
                eventHandler->getCamera()->moveY(0);
                break;
            default: break;
		}
	}
}