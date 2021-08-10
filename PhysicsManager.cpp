#include "PhysicsManager.h"

void PhysicsManager::updateCollisions() {//static - dynamic
	for (auto& dynamicEnt : m_DynamicCollisions) {
		for (auto& staticEnt : m_StaticCollisions) {
			resolveCollision(*dynamicEnt,*staticEnt);
		}
	}
	//dynamic - dynamic
	for (int i = 0;i < m_DynamicCollisions.size();i++) {
		for (int j = 0;j < m_DynamicCollisions.size();j++) {
			if (i != j) {
				resolveCollision(*m_DynamicCollisions[i], *m_DynamicCollisions[j]);
			}
		}
	}
}

void PhysicsManager::addDinamicCollision(DynamicCollision& collision) {
	m_DynamicCollisions.push_back(new DynamicCollision(collision));
}
void PhysicsManager::addStaticCollision(StaticCollision& collision) {
	m_StaticCollisions.push_back(new StaticCollision(collision));
}

void PhysicsManager::resolveCollision(DynamicCollision& dynamicCol, StaticCollision& staticCol) {
	if (!checkCollision(staticCol.getCollision(), dynamicCol.getCollision()))
		return;
	staticCol.handleDynamic(dynamicCol);
}

void PhysicsManager::resolveCollision(DynamicCollision& dynamicCol1, DynamicCollision& dynamicCol2) {
	if (checkCollision(dynamicCol1.getCollision(), dynamicCol2.getCollision())) {
		dynamicCol1.interact(dynamicCol2);
		dynamicCol2.interact(dynamicCol1);
	}
}

bool PhysicsManager::checkCollision(const sf::FloatRect& col1, const sf::FloatRect& col2) {
	return  col1.left				<= (col2.left + col2.width) &&
		   (col1.left + col1.width) >= (col2.left + col2.width) &&
			col1.top				<= (col2.top + col2.height) &&
		   (col1.top + col2.height) >= (col2.top + col2.height);
}