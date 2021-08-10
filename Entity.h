#pragma once
#include <SFML/Graphics.hpp>
class Entity : public sf::Drawable {
public:
	virtual void update(const float dt) {};
	virtual void destroy() {};
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const {};
	virtual void input() {};
	virtual void init() {};
};