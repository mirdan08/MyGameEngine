#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Input.h"
class Engine {
public:
	Engine();
	void run();
	void input();
	void update(const float dt);
	void draw();
private:
	Window m_Window;
	sf::Time m_Time;
	sf::Clock m_Clock;
};