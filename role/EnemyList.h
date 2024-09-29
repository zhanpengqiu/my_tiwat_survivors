#pragma once
#include "config.h"
#include "Enemy.h"
//���õ���ģʽʵ�֣���Ϊ���еĵ��˶�����һ���б���
//Ӧ����֤ȫ�ֵĵ���������һ��Ψһ��
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

