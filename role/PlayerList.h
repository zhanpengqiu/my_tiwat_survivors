#pragma once
#pragma once
#include "config.h"
#include "Player.h"
//���õ���ģʽʵ�֣���Ϊ���еĵ��˶�����һ���б���
//Ӧ����֤ȫ�ֵĵ���������һ��Ψһ��
class PlayerList
{
public:
	static PlayerList* getinstance() {
		if (instance == nullptr) {
			instance = new PlayerList();
		}
		return instance;
	}
	void UpdatePlayerStatus();
public:
	std::vector<Player*>playerList;
private:
	static PlayerList* instance;
	PlayerList() = default;
	~PlayerList();
};

