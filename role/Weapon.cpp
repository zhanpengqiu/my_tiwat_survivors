#include "Weapon.h"
void Bullet::Draw()const {
	setlinecolor(RGB(255, 155, 50));
	setlinecolor(RGB(200, 75, 10));
	fillcircle(position.x, position.y, RADIUS);
}