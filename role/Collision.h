#pragma once
#include "config.h"
#include "EnemyList.h"
class Collision
{
public:
	static Collision* getinstance() {
		if (instance == nullptr) {
			instance = new Collision();
		}
		return instance;
	}
	void CheckWeaponCollision();
	void CheckPlayerCollision();
private:
	static Collision* instance;
	Collision();
	~Collision();
private:
	PlayerList* players;
	EnemyList* enemylist;
};

