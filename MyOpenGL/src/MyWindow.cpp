#include "MyWindow.h"
#include <iostream>


MyWindow::MyWindow()
{
	/* Initialize the library */
	if (!glfwInit())
		exit(EXIT_FAILURE);

	// Create a windowed mode window and its OpenGL context 
	// *** Note must happen after glfwInit

	m_window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL); // create context
	if (!m_window){
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(m_window);								// Active context

	GLenum err = glewInit();										// Per documentation.  First you need to create a valid OpenGL rendering context then call glewInit.
																	// In most cases this means the OpenGL window must be PRESENT and ACTIVE before this call.
																	// On Windows, you also need to define the GLEW_STATIC in the preprocessor token when building a static library 
																	// or executable.
	if (GLEW_OK != err){
		// failed to initialize GLEW!
		exit(EXIT_FAILURE);
	}

	std::cout << "Using GLEW Version: " << glewGetString(GLEW_VERSION) << std::endl;		// GLEW Version (2.6)
	std::cout << "Gl Connection is: " << glGetString(GL_VERSION) << std::endl;		//  Not a part of GLEW, just outputs the OpenGL version to the console (4.6.0)
}
