#include "EventManager.h"


void EventManager::Subscribe(IEventHandler* handler)
{
	m_Vect_Of_Handles_To_Subscribers.push_back(handler);
}


void EventManager::Unsubscribe(IEventHandler * handler)
{
	std::vector<IEventHandler*>::iterator it = m_Vect_Of_Handles_To_Subscribers.begin();
	while (it != m_Vect_Of_Handles_To_Subscribers.end())
	{
		if (*it == handler)
		{
			m_Vect_Of_Handles_To_Subscribers.erase(it);
			m_Vect_Of_Handles_To_Subscribers.shrink_to_fit();
			break;
		}
		it++;
	}
}


void EventManager::FireEvent(int eventId)
{
	for (IEventHandler* handler : m_Vect_Of_Handles_To_Subscribers)
	{
		if (handler->HandleEvent(eventId))
		{
			break;
		}
	}
}

