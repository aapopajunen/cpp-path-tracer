#ifndef DISPLAY_H
#define DISPLAY_H

#include <GLFW/glfw3.h>

class Display{
	public:
		Display(int w, int h);
		~Display();
		void update();
		bool isOpen();
		void clear();
		GLFWwindow* getWindow();
		void setDimensions(int w, int h);
	private:
		GLFWwindow* window;
		int width;
		int height;
};

#endif