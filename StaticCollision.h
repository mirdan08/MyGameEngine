#pragma once
#include <SFML/Graphics.hpp>
#include "DynamicCollision.h"
class StaticCollision {
public:
	virtual sf::FloatRect getCollision() {};
	virtual void handleDynamic(DynamicCollision& collision) {};
private:
	sf::FloatRect m_Collision;
};