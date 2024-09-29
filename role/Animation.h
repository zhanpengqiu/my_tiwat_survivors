#pragma once
#include "config.h"



class Animation
{
public:
	Animation(LPCTSTR path, int num, int interval);
	~Animation();
	void play(int x, int y, int delta);
	
private:
	void putimage_alpha(int x, int y, IMAGE* img);
	int timer = 0;
	int idx_frame = 0;
	int interval_ms = 0;
	std::vector<IMAGE*>frame_list;
};