#include "EnemyList.h"

void EnemyList::TryGenerateEnemy(int num) {
	for (int i = 0; i < num; i++) {
		this->enemylist.push_back(new Enemy());
	}
}	
void EnemyList::UpdateEnemyStatus() {
    auto it = enemylist.begin();
    while (it != enemylist.end()) {
        if (!(*it)->CheckAlive()) {
            delete* it;
            it = enemylist.erase(it); // ɾ��Ԫ�ز����µ�����  
        }
        else {
            ++it; // �����ƶ�����һ��Ԫ��  
        }
    }
}
EnemyList::~EnemyList() {
	delete instance;
}