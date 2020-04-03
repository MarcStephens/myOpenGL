#pragma once

#include <glew.h>
#include <glfw3.h>

class MyWindow
{
public:

	MyWindow();
	~MyWindow() {}

	GLFWwindow* m_window;  // this is a singleton class so could make static
};

