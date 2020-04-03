#include "Player.h"

bool Player::HandleEvent(int eventId)
{
	if (eventId == 2) {
		std::cout << "'W' Event 2 fired by Player" << std::endl;
	}

		return true;
}
