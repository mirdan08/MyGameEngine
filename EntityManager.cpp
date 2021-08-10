#include "EntityManager.h"

void EntityManager::addEntity(Entity* entity) {
	m_Entities.push_back(entity);
}

void EntityManager::removeEntity(const int id) {
	m_Entities[id]->destroy();
	m_Entities.erase(m_Entities.begin() + id);
}

void EntityManager::update(const float dt) {
	for (auto& e : m_Entities) 
		e->update(dt);
}
void EntityManager::draw() {
	for (auto& e : m_Entities)
		m_Window->draw(*e);
}

void EntityManager::input() {
	for (auto& e : m_Entities)
		e->input();
}

void EntityManager::init() {
	for (auto& e : m_Entities)
		e->init();
}
