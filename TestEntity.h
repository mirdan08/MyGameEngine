#pragma once
#include "Entity.h"
#include "Animator.h"
#include "Resources.h"
#include "Input.h"
class TestEntity : public Entity{
public:
	TestEntity() :anim(Resources::getTexture("./Graphics/spriteSheetTest.png"), 24, 24) {};
	void update(const float dt);
	void destroy();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void input();
	void init();
	sf::Vector2f getPosition();
private:
	sf::Vector2f pos;
	sf::Vector2f dir;
	Animator anim;
	float speed;
};