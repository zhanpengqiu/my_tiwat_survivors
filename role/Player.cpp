#include "Player.h"

Player::Player() {
	//设置人物属性
	maxHp = 10;
	mHp=10;
	mMp=10;
	mAt=10;
	mDf=10;
	speed=5;
	position = { 600,300 };
	PLAYER_WIDTH = 80;
	PLAYER_HEIGHT = 80;
	weaponNum = 3;
	weaponType = WeaponType::BULLET;
	//设置按键模式
	is_move_up = false;
	is_move_down = false;
	is_move_left = false;
	is_move_right = false;

	img_shadow = new IMAGE();
	//加载玩家模型图片
	loadimage(img_shadow, _T("Resource/img/shadow_player.png"));

	anim_right = new Animation(_T("Resource/img/player_right_%d.png"), 6, 180);
	anim_left = new Animation(_T("Resource/img/player_left_%d.png"), 6, 180);
	UpdateWeapon(weaponType,weaponNum);
}
Player::~Player() {
	delete img_shadow;
	delete anim_left;
	delete anim_right;
}
void Player::ProcessEvent(const ExMessage& msg)
{
	switch (msg.message)
	{
	case WM_KEYDOWN:
		switch (msg.vkcode)
		{
		case VK_UP:
			is_move_up = true;
			break;
		case VK_DOWN:
			is_move_down = true;
			break;
		case VK_LEFT:
			is_move_left = true;
			break;
		case VK_RIGHT:
			is_move_right = true;
			break;
		}
		break;

		//按键状态判断
	case WM_KEYUP:
		switch (msg.vkcode)
		{
		case VK_UP:
			is_move_up = false;
			break;
		case VK_DOWN:
			is_move_down = false;
			break;
		case VK_LEFT:
			is_move_left = false;
			break;
		case VK_RIGHT:
			is_move_right = false;
			break;
		}
		break;
	}
}

void Player::UpdateWeapon(WeaponType type, int weaponnum){
	for (auto& iter : this->weaponList) {
		delete(iter);
	}
	this->weaponType = type;
	this->weaponNum = weaponnum;
	switch (type)
	{
	case BULLET:
		for (int i = 0; i < weaponnum; i++) {;
			this->weaponList.push_back(new Bullet());
		}
		break;
	case SWARD:
		break;
	default:
		break;
	}

}

void Player::DrawWeapon() {
	//设置武器的属性
	const double RADIAL_SPEED = 0.0045;	// 径向波动速度
	const double TANGENT_SPEED = 0.0055;	// 切向波动速度
	double radian_interval = 2 * 3.14159 / this->weaponList.size();	//子弹间的角度，转化为弧度

	POINT player_position = this->GetPosition();
	double radius = 100 + 25 * sin(GetTickCount() * RADIAL_SPEED);	//半径的长度变化，变化的范围为 （100 -25，100 + 25）
	size_t i = 0;
	for (Weapon* iter : this->weaponList) {
		//GetTickCount() * TANGENT_SPEED 为当前子弹弧度变化的快慢，即旋转的速度
		//radian当前子弹所在的弧度值,以x轴正方向为0度开始的角度，转换为弧度
		double radian = GetTickCount() * TANGENT_SPEED + radian_interval * (i++);
		iter->position.x = player_position.x + FRAME_WIDTH / 2 + (int)(radius * sin(radian));
		iter->position.y = player_position.y + FRAME_HEIGHT / 2 + (int)(radius * cos(radian));
		iter->position.y = iter->position.y;
	}
}

void Player::Draw(int delta) {
	int pos_shadow_x = position.x + (PLAYER_WIDTH / 2 - SHADOW_WIDTH / 2);
	int pos_shadow_y = position.y + PLAYER_HEIGHT - 8;
	this->PutimageAlpha(pos_shadow_x, pos_shadow_y, img_shadow);
	static bool facing_left = false;
	int dir_x = is_move_right - is_move_left;
	if (dir_x < 0)
		facing_left = true;
	else if (dir_x > 0)
		facing_left = false;

	if (facing_left)
	{
		anim_left->play(position.x, position.y, delta);
	}
	else
	{
		anim_right->play(position.x, position.y, delta);
	}
	DrawWeapon();
	ShowHealthBar();
	for (Weapon* iter : weaponList) {
		iter->Draw();
	}
}
void Player::Move() {
	int dir_x = is_move_right - is_move_left;
	int dir_y = is_move_down - is_move_up;
	//人物移动的单位距离
	double len_dir = sqrt(dir_x * dir_x + dir_y * dir_y);
	//人物位置以单位速度移动
	if (len_dir != 0)
	{
		double normalized_x = dir_x / len_dir;
		double normalized_y = dir_y / len_dir;
		position.x += (int)(speed * normalized_x);
		position.y += (int)(speed * normalized_y);
	}

	//限制人物在窗口内移动
	if (position.x < 0) position.x = 0;
	if (position.y < 0) position.y = 0;
	if (position.x + PLAYER_WIDTH > WINDOW_WIDTH) position.x = WINDOW_WIDTH - PLAYER_WIDTH;
	if (position.y + PLAYER_HEIGHT > WINDOW_HEIGHT) position.y = WINDOW_HEIGHT - PLAYER_HEIGHT;

}
void Player::Hurt(int damage) {
	this->mHp -= damage;
}
