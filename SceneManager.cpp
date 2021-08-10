#include "SceneManager.h"
#include "Window.h"
#include <iostream>
SceneManager& SceneManager::getInstance() {
	static SceneManager instance;
	return instance;
}
SceneManager::SceneManager():m_CurScene(nullptr),
							 m_Camera(sf::FloatRect(0,0,10*8,10*8)){
}
void SceneManager::input() {
	m_CurScene->input();
}

void SceneManager::draw(Window& window) {
	m_CurScene->draw(window);
}

void SceneManager::update(const float dt) {
	m_CurScene->update(dt);
}

void SceneManager::loadScene(const std::string scene) {
	for (auto it = m_Scenes.begin();it != m_Scenes.end();++it) {
		if (it->first == scene) {
			m_CurScene = it->second;
			m_CurScene->init();
			return;
		}
	}
}

void SceneManager::addScene(std::string name, Scene* scene) {
	m_Scenes.insert(std::pair<std::string,Scene*>(name,scene));
}

sf::View& SceneManager::getCamera() {
	return m_Camera;
}