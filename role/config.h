#pragma once
#include "graphics.h"
#include <vector>
#include <math.h>
#include <iostream>
#include <memory>

#define FRAME_WIDTH 100
#define FRAME_HEIGHT 100
#define SHADOW_WIDTH 48
enum UiRunningType
{
	BEGING = 0,
	RUNNING,
	QUITTING
};
enum WeaponType {
	BULLET = 0,
	SWARD
};