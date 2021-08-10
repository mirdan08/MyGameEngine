#pragma once
#include <bitset>
#include <SFML/Graphics.hpp>
#include <map>
class Input{
public:
	void updateInput();
	bool justPressed(const sf::Keyboard::Key key);
	bool isPressed(const sf::Keyboard::Key key);
	bool isUp(const sf::Keyboard::Key key);
	bool justReleased(const sf::Keyboard::Key key);
	void addKey(const sf::Keyboard::Key key);
	static Input& getInstance();
private:
	Input() {};
	std::bitset<16> m_CurrentInput;
	std::bitset<16> m_OldInput;
	std::map<sf::Keyboard::Key, int> m_Keys;
	int m_LastKey;
};