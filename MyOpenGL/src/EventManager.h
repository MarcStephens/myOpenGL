#pragma once
#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <vector>
#include"IEventHandler.h"
#include "MyWindow.h"


//aka InputSystem

class EventManager
{
public:
	
	void Subscribe(IEventHandler* handler);  // creates a pointer to an EH class which will be inherited by the non-virtual class
	void Unsubscribe(IEventHandler* handler);
	void FireEvent(int eventId);

	std::vector<IEventHandler*> m_Vect_Of_Handles_To_Subscribers; 
	
};

