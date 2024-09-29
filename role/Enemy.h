#pragma once
#include "Role.h"
#include "PlayerList.h"
class Enemy :
    public Role
{
public:
    Enemy();
    ~Enemy();
    void Move();
    void Draw(int delta);
    void Hurt(int damage);
    int GetDamageValue() { return damageValue; }
    void ProcessEvent(const ExMessage& msg){}
private:
    int speed;			//敌人移动速度
    int ENEMY_WIDTH;		//敌人宽度	
    int ENEMY_HEIGHT;	//敌人高度
    int damageValue = 3;
    //敌人血量
    PlayerList* players;
};

