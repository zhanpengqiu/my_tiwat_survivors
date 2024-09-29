#include "Enemy.h"

Enemy::Enemy() {
	position = { 0,0 };
	img_shadow = new IMAGE();
	anim_right = new Animation(_T("Resource/img/enemy_right_%d.png"), 6, 45);
	anim_left = new Animation(_T("Resource/img/enemy_left_%d.png"), 6, 45);
	loadimage(img_shadow, _T("Resource/img/shadow_enemy.png"));
	speed = 2;
	mHp = 8;
	maxHp = 8;
	mMp = 10;
	mAt = 10;
	mDf = 10;
	ENEMY_WIDTH = 80;
	ENEMY_HEIGHT = 80;
	facing_left = false;
	players = PlayerList::getinstance();
	//敌人生成边界
	enum class SpawnEdge {
		Up = 0,
		Down,
		Left,
		Right
	};
	SpawnEdge edge = (SpawnEdge)(rand() % 4);
	switch (edge)
	{
	case SpawnEdge::Up:
		position.x = rand() % WINDOW_WIDTH;
		position.y = -ENEMY_HEIGHT;
		break;
	case SpawnEdge::Down:
		position.x = rand() % WINDOW_WIDTH;
		position.y = WINDOW_HEIGHT;
		break;
	case SpawnEdge::Left:
		position.x = -ENEMY_HEIGHT;
		position.y = rand() % WINDOW_HEIGHT;
		break;
	case SpawnEdge::Right:
		position.x = WINDOW_WIDTH;
		position.y = rand() % WINDOW_HEIGHT;
		break;
	default:
		break;
	}
}
Enemy::~Enemy() {
	delete img_shadow;
	delete anim_left;
	delete anim_right;
}
void Enemy::Move() {
	int dir_x=0, dir_y=0;
	double len_dir= INT_MAX;
	POINT player_position = { 0,0 };
	//选择最近的玩家靠近
	for (auto& iter : players->playerList) {
		player_position = iter->GetPosition();
		dir_x = player_position.x - position.x;
		dir_y = player_position.y - position.y;
		len_dir = min(len_dir, sqrt(dir_x * dir_x + dir_y * dir_y));
		if (len_dir != 0)
		{
			double normalized_x = dir_x / len_dir;
			double normalized_y = dir_y / len_dir;
			position.x += (int)(speed * normalized_x);
			position.y += (int)(speed * normalized_y);
		}
	}


	if (dir_x < 0)
		facing_left = true;
	else if (dir_x > 0)
		facing_left = false;
}
void Enemy::Draw(int delta) {
	int pos_shadow_x = position.x + (FRAME_WIDTH / 2 - SHADOW_WIDTH / 2);
	int pos_shadow_y = position.y + FRAME_HEIGHT - 50;
	PutimageAlpha(pos_shadow_x, pos_shadow_y, img_shadow);

	ShowHealthBar();
	if (facing_left)
		anim_left->play(position.x, position.y, delta);
	else
		anim_right->play(position.x, position.y, delta);
}
void Enemy::Hurt(int damage) {
	this->mHp -= damage;
}