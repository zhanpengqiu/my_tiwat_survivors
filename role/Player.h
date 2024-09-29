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
    //与玩家按键状态有关
    bool is_move_up;
    bool is_move_down;
    bool is_move_left;
    bool is_move_right;
    //玩家武器之类的
public:
    int weaponNum;
    std::vector<Weapon*>weaponList;
    WeaponType weaponType;
    //玩家大小
    int PLAYER_WIDTH;	//玩家宽度	
    int PLAYER_HEIGHT;	//玩家高度

};

