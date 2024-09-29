#pragma once
#include "config.h"
//�������ù������ģʽʵ��
class Weapon
{
public:
	Weapon() {};
	virtual ~Weapon() {};
	virtual void Draw() const=0;
	virtual int GetDamageValue()=0;
public:
	POINT position = { 0,0 };
};

class Bullet :public Weapon {
public:
	Bullet()=default;
	~Bullet() = default;
	void Draw()const;
	int GetDamageValue() { return damageValue; };
private:
	const int RADIUS = 10;
	int damageValue = 3;
};

