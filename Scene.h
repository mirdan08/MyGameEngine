#pragma once
#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics.hpp>
#include "Window.h"
class Scene {
public:
	virtual void init() {};
	virtual void update(const float dt) {};
	virtual void draw(Window& window) {};
	virtual void input() {};
	virtual void destroy() {};
};
#endif