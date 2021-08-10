#include "Engine.h"
#include "SceneManager.h"
#include <iostream>
Engine::Engine() :m_Window("test game"){
}

void Engine::update(const float dt) {
	SceneManager::getInstance().update(dt);
}

void Engine::draw() {
	SceneManager::getInstance().draw(m_Window);
	m_Window.setView(SceneManager::getInstance().getCamera());
}

void Engine::input() {
	Input::getInstance().updateInput();
	SceneManager::getInstance().input();
}

void Engine::run() {
	std::cout << "start engine" << std::endl;
	Input::getInstance().addKey(sf::Keyboard::Up);
	Input::getInstance().addKey(sf::Keyboard::Down);
	Input::getInstance().addKey(sf::Keyboard::Right);
	Input::getInstance().addKey(sf::Keyboard::Left);
	while (m_Window.isOpen()) {
		m_Time = m_Clock.restart();
		input();
		update(m_Time.asSeconds());
		m_Window.beginDraw();
		draw();
		m_Window.endDraw();
	}
}