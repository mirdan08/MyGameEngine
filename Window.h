#pragma once
#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <SFML/Graphics.hpp>
class Window :public sf::RenderWindow{
public:
	Window(const std::string& windowName);
	sf::Vector2f getCenter();
	void beginDraw();
	void update();
	void draw(const sf::Drawable& drawable);
	bool isOpen();
	void endDraw();
	void setView(sf::View& view);
private:
	sf::RenderWindow m_Window;
};
#endif
