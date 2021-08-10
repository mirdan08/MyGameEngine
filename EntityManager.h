#pragma once
#include "Entity.h"
#include "Window.h"
#include <vector>
class EntityManager {
public:
	EntityManager() {};
	void addEntity(Entity* entity);
	void removeEntity(const int id);
	void update(const float dt);
	void draw();
	void input();
	void init();
private:
	std::vector<Entity*> m_Entities;
	Window* m_Window;
};