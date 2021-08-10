#include "TestEntity.h"
void TestEntity::input() {
	dir.x = 0;
	dir.y = 0;
	if (Input::getInstance().isPressed(sf::Keyboard::Up))
		dir.y -= 1;
	if (Input::getInstance().isPressed(sf::Keyboard::Down))
		dir.y += 1;
	if (Input::getInstance().isPressed(sf::Keyboard::Left))
		dir.x -= 1;
	if (Input::getInstance().isPressed(sf::Keyboard::Right))
		dir.x += 1;
}
void TestEntity::update(const float dt) {
	pos.x += speed * dir.x * dt;
	pos.y += speed * dir.y * dt;
	if (Input::getInstance().justPressed(sf::Keyboard::Up) ||
		Input::getInstance().justPressed(sf::Keyboard::Down))
		anim.selectAnim("jump");
	if (Input::getInstance().justPressed(sf::Keyboard::Right) ||
		Input::getInstance().justPressed(sf::Keyboard::Left))
		anim.selectAnim("walk");
	anim.setPosition(pos.x,pos.y);
	anim.update(dt);
}

void TestEntity::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(anim);
}

void TestEntity::init() {
	speed = 50;
	dir.x = 0;
	dir.y = 0;
	anim.addAnim("stand",0,1,1);
	anim.addAnim("walk", 1, 3, 0.4);
	anim.addAnim("spawn", 2, 8, 1);
	anim.addAnim("jump", 4, 1, 1);
	anim.selectAnim("spawn");
}

void TestEntity::destroy() {}

sf::Vector2f TestEntity::getPosition() {
	return pos;
}