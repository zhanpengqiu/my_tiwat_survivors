#pragma once
#include "config.h"
#include "Role.h"
#include "Weapon.h"
class Player :
    public Role
{
public:
    Player();
    ~Player();
    void Draw(int delta);
    void DrawWeapon();
    void Move();
    void Hurt(int damage);
    void ProcessEvent(const ExMessage& msg);
    void UpdateWeapon(WeaponType weaponType, int weaponnum);
private:
    //����Ұ���״̬�й�
    bool is_move_up;
    bool is_move_down;
    bool is_move_left;
    bool is_move_right;
    //�������֮���
public:
    int weaponNum;
    std::vector<Weapon*>weaponList;
    WeaponType weaponType;
    //��Ҵ�С
    int PLAYER_WIDTH;	//��ҿ��	
    int PLAYER_HEIGHT;	//��Ҹ߶�

};

