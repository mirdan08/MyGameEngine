#pragma once
#include "Scene.h"
#include "Window.h"
#include "SceneManager.h"
#include "Level.h"
#include "TestEntity.h"
#include "Input.h"
class TestScene2 : public Scene {
public:
	TestScene2():m_Camera(SceneManager::getInstance().getCamera()) {};
	void init();
	void update(const float dt);
	void draw(Window& window);
	void input();
private:
	sf::Vector2f pos;
	sf::View &m_Camera;
	Level level;
	TestEntity ent;
};