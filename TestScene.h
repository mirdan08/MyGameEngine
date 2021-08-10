#pragma once
#include "Scene.h"
#include "Window.h"
#include "Animator.h"
#include "Resources.h"
#include "Input.h"
class TestScene : public Scene {
public:
	TestScene():anim(Resources::getTexture("./Graphics/spriteSheetTest.png"),24,24) {};
	void init();
	void update(const float dt);
	void draw(Window & window);
	void input();
private:
	Animator anim;
};