#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <GLFW/glfw3.h>

#include "display.hpp"
#include "camera.hpp"

class EventHandler{
    public:
        EventHandler(Display* d, Camera* c);
		Display* getDisplay();
		Camera* getCamera();
    private:
		Display* display;
        Camera* camera;
};

void windowResize(GLFWwindow* window, int width, int height);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif