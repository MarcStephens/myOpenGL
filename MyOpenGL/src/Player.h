#pragma once
#include <iostream>
#include "IEventHandler.h"

class Player : public IEventHandler
{
public: 
	Player() {}
	~Player() {}

	//From IEventHandler
	virtual bool HandleEvent(int eventID) override;
};

