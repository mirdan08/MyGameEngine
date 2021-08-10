#include "TestScene.h"
#include "SceneManager.h"
#include "Resources.h"
#include <iostream>

void TestScene::init() {
	anim.addAnim("stand",0,1,1);
	anim.addAnim("walk", 1, 3, 0.3);
	anim.addAnim("spawn", 2, 8, 0.8);
	anim.addAnim("rainbow", 3, 8, 1);
	anim.addAnim("jump",4,1,1);
	
}

void TestScene::update(const float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		SceneManager::getInstance().loadScene("Test2");
	anim.update(dt);
}

void TestScene::draw(Window& window){
	window.draw(anim);
}

void TestScene::input() {
}