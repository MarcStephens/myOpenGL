#pragma once
// aka InputListener

class IEventHandler
{
public:
	IEventHandler() {}  //constructor & de-constructor
	~IEventHandler() {}

	//pure virutal callback functions

	virtual bool HandleEvent(int eventID) = 0;
};

