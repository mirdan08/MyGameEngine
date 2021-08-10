#include "Input.h"

bool Input::justPressed(const sf::Keyboard::Key key) {
	return m_CurrentInput[m_Keys[key]] && !m_OldInput[m_Keys[key]];
}
bool Input::isPressed(const sf::Keyboard::Key key) {
	return m_CurrentInput[m_Keys[key]];
}
bool Input::isUp(const sf::Keyboard::Key key) {
	return !m_CurrentInput[m_Keys[key]];
}
bool Input::justReleased(const sf::Keyboard::Key key) {
	return !m_CurrentInput[m_Keys[key]] && m_OldInput[m_Keys[key]];
}
void Input::addKey(const sf::Keyboard::Key key) {
	m_Keys.insert(std::pair<sf::Keyboard::Key,int>(key,m_LastKey++));
}

void Input::updateInput() {
	m_OldInput = m_CurrentInput;
	for (auto& key : m_Keys) {
		m_CurrentInput[key.second] = sf::Keyboard::isKeyPressed(key.first);
	}
}

Input& Input::getInstance() {
	static Input input;
	return input;
}