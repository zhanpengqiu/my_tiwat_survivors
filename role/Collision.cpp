#include "Collision.h"

Collision::Collision() {
	players = PlayerList::getinstance();
	enemylist = EnemyList::getinstance();
	mciSendString(_T("open Resource/mus/hit.wav alias hit"), NULL, 0, NULL);
}
Collision::~Collision() {
	delete instance;
}
void Collision::CheckPlayerCollision() {
	for (Enemy* enemy : enemylist->enemylist) {
		for (Player* player : players->playerList) {
			for (Weapon* weapon : player->weaponList) {
				bool is_overlap_x = (weapon->position.x >= enemy->position.x) && (weapon->position.x <= enemy->position.x + FRAME_WIDTH);
				bool is_overlap_y = (weapon->position.y >= enemy->position.y) && (weapon->position.y <= enemy->position.y + FRAME_HEIGHT);
				if (is_overlap_x && is_overlap_y) {
					//受击
					enemy->Hurt(weapon->GetDamageValue());
					mciSendString(_T("play hit from 0"), NULL, 0, NULL);
				}
			}
		}
	}
}

void Collision::CheckWeaponCollision() {
	for (Player* player : players->playerList) {
		for (Enemy* enemy : enemylist->enemylist) {
			//将敌人中心位置等效为点，判断玩家是否在矩形框内
			POINT check_position = { enemy->position.x + FRAME_WIDTH / 2, enemy->position.y + FRAME_HEIGHT / 2 };
			bool is_overlap_x = (enemy->position.x >= player->GetPosition().x) && (enemy->position.x <= player->GetPosition().x + 50);
			bool is_overlap_y = (enemy->position.y >= player->GetPosition().y) && (enemy->position.y <= player->GetPosition().y + 60);
			if (is_overlap_x && is_overlap_y) {
				player->Hurt(enemy->GetDamageValue());
			}
		}
	}

}