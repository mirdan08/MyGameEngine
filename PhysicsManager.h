#pragma once
#include "StaticCollision.h"
#include "DynamicCollision.h"
#include <vector>
class PhysicsManager {
public:
	void addStaticCollision(StaticCollision& collision);
	void addDinamicCollision(DynamicCollision& collision);
	void updateCollisions();
private:
	std::vector<StaticCollision*> m_StaticCollisions;
	std::vector<DynamicCollision*> m_DynamicCollisions;
	void resolveCollision(DynamicCollision& dynamicCol,StaticCollision &staticCol);
	void resolveCollision(DynamicCollision& dynamicCol1, DynamicCollision& dynamicCol2);
	bool checkCollision(const sf::FloatRect& col1,const sf::FloatRect& col2);
};