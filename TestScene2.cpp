#include "TestScene2.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Input.h"
#include <iostream>
void TestScene2::init() {
	level.setTileTextures(Resources::getTexture("./Graphics/Tiles.png"));
	level.setTileSize(8);
	level.addTile('q', sf::Vector2i(0, 0));
	level.addTile('a', sf::Vector2i(1, 0));
	level.addTile(' ', sf::Vector2i(2, 0));
	level.loadLevel("./Level/level1.txt");
	ent.init();
}

void TestScene2::update(const float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		SceneManager::getInstance().loadScene("Test");
	}
	ent.update(dt);
}

void TestScene2::draw(Window& window) {
	m_Camera.setCenter(ent.getPosition());
	window.draw(level);
	window.draw(ent);
}

void TestScene2::input() {
	ent.input();
}