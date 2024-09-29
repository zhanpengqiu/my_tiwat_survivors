#include "PlayerList.h"
PlayerList::~PlayerList() {
	delete instance;
}
void PlayerList::UpdatePlayerStatus() {
	for (size_t i = 0; i < playerList.size(); i++)
	{
		Player* player = playerList[i];
		if (!player->CheckAlive())	//À¿¡À
		{
			std::swap(playerList[i], playerList.back());
			playerList.pop_back();
			delete player;
		}
	}
}