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
            it = enemylist.erase(it); // 删除元素并更新迭代器  
        }
        else {
            ++it; // 否则移动到下一个元素  
        }
    }
}
EnemyList::~EnemyList() {
	delete instance;
}