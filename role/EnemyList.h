#pragma once
#include "config.h"
#include "Enemy.h"
//采用单例模式实现，因为所有的敌人都放在一个列表当中
//应当保证全局的敌人数量的一个唯一性
class EnemyList
{
public:
	static EnemyList* getinstance() {
		if (instance == nullptr) {
			instance = new EnemyList();
		}
		return instance;
	}
	void UpdateEnemyStatus();
	void TryGenerateEnemy(int num);
public:
	std::vector<Enemy*>enemylist;
private:
	static EnemyList* instance;
	EnemyList() = default;
	~EnemyList();

};

