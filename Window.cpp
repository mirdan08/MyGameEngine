#include "Window.h"
#include "SceneManager.h"
Window::Window(const std::string& windowName) 
	:m_Window(sf::VideoMode(800, 800), windowName) {
}

void Window::beginDraw() {
	m_Window.clear(sf::Color::Black);
}

void Window::endDraw() {
	m_Window.display();
}

void Window::draw(const sf::Drawable& drawable) {
	m_Window.draw(drawable);
}

void Window::update() {
	
}

bool Window::isOpen(){
	return m_Window.isOpen();
}

void Window::setView(sf::View& view) {
	m_Window.setView(view);
}