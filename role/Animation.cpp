#include "Animation.h"
//”Îª≠Õºœ‡πÿ
Animation::Animation(LPCTSTR path, int num, int interval) {
	interval_ms = interval;
	TCHAR path_file[256];
	for (int i = 0; i < num; i++)
	{
		_stprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file);
		frame_list.push_back(frame);
	}
}
void Animation::play(int x, int y, int delta) {
	timer += delta;
	if (timer >= interval_ms) {
		idx_frame = (idx_frame + 1) % frame_list.size();
		timer = 0;
	}
	putimage_alpha(x, y, frame_list[idx_frame]);
}
void Animation::putimage_alpha(int x, int y, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	GdiAlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}

Animation::~Animation() {
	auto it = frame_list.begin();
	while (it != frame_list.end()) {
		delete* it;
		it = frame_list.erase(it);
	}
}