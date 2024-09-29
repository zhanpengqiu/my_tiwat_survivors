#pragma once
#pragma once
#include "config.h"
#include "Player.h"
//采用单例模式实现，因为所有的敌人都放在一个列表当中
//应当保证全局的敌人数量的一个唯一性
class PlayerList
{
public:
	static PlayerList* getinstance() {
		if (instance == nullptr) {
			instance = new PlayerList();
		}
		return instance;
	}
	void UpdatePlayerStatus();
public:
	std::vector<Player*>playerList;
private:
	static PlayerList* instance;
	PlayerList() = default;
	~PlayerList();
};

