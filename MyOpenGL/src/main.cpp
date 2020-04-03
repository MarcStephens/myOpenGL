#include <glew.h>	// Per glfw need to include this header BEFORE glfw
#include <glfw3.h>  /* This defines all the constants, types and function prototypes of the GLFW API.  It also includes the OpenGL header from your development environment
					   and defines all the constants and types necessary for it to work on your platform without including any platform-specific headers.  I.e:
						- Do NOT include the OpenGL header yourself, as GLFW does this for you in a platform - independent way
						- Do NOT include windows.h or other platform - specific headers unless you plan on using those APIs yourself
						- If you do need to include such headers, include them BEFORE the GLFW header and it will detect this*/
#include <iostream>
#include "MyWindow.h"
#include"Player.h"
#include <functional>
#include "EventManager.h"



EventManager eventManager;   




void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	{
		if (key == 'W') {
			eventManager.FireEvent(2);
		}
	}
}





int main(void)
{
	MyWindow window;   // Creates the window & activates it.
	Player player;
	eventManager.Subscribe(&player);

	glfwSetKeyCallback(window.m_window, key_callback);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window.m_window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(window.m_window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
