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
    int speed;			//�����ƶ��ٶ�
    int ENEMY_WIDTH;		//���˿��	
    int ENEMY_HEIGHT;	//���˸߶�
    int damageValue = 3;
    //����Ѫ��
    PlayerList* players;
};

