#include <glew.h>		// Per glfw need to include this header BEFORE glfw
#include <glfw3.h>		/* This defines all the constants, types and function prototypes of the GLFW API.  It also includes the OpenGL header from your development environment
							   and defines all the constants and types necessary for it to work on your platform without including any platform-specific headers.  I.e:
								- Do NOT include the OpenGL header yourself, as GLFW does this for you in a platform - independent way
								- Do NOT include windows.h or other platform - specific headers unless you plan on using those APIs yourself
								- If you do need to include such headers, include them BEFORE the GLFW header and it will detect this*/
#include <iostream>

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);	// This returns a handle to the created window object.  For example, this creates a 640 by 480 windowed mode window
																// If window creation fails, NULL will be returned, so it is necessary to check the return value.  The window handle
																	// is passed to all window related functions and is provided to along with all input events, so event handlers can 
																	// tell which window received the event.
																	// [in] width	The desired width, in screen coordinates, of the window.This must be greater than zero.
																	// [in]	height	The desired height, in screen coordinates, of the window.This must be greater than zero.
																	// [in]	title	The initial, UTF - 8 encoded window title.
																	// [in]	monitor	The monitor to use for full screen mode, or NULL for windowed mode.
																	// [in]	share	The window whose context to share resources with, or NULL to not share resources.
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	GLenum err = glewInit();										// Per documentation.  First you need to create a valid OpenGL rendering context.  In most cases this means an OpenGL window must 
																	// be present AND active before this call.
																	// On Windows, you also need to define the GLEW_STATIC in the preprocessor token when building a static library 
																	// or executable.
	if (GLEW_OK != err)
	{
		// failed to initialize GLEW!
	}
	std::cout << "Using GLEW Version: "	<< glewGetString(GLEW_VERSION)	<< std::endl;   // GLEW Version (2.6)
	std::cout << "Gl Connection is: "	<< glGetString(GL_VERSION)		<< std::endl;	//  Not a part of GLEW, just outputs the OpenGL version to the console (4.6.0)
																						// glGetString:  returns a pointer to a static string describing some aspect of the current GL connection.
	
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}