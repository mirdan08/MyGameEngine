#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

struct Animation {
	int pos;
	int length;
	float time;
};

class Animator :public sf::Drawable{
public:
	Animator(sf::Texture& texture,const int width,const int height);
	void addAnim(const std::string name,const int pos,const int length,const float time);
	void update(const float dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void selectAnim(const std::string name);
	void setPosition(const float x, const float y);
private:
	std::string m_Name;
	std::map<std::string, Animation> m_Animations;
	Animation m_CurrentAnimation;
	sf::Sprite m_SpriteSheet;
	float m_CurrentTime;
	float m_FrameLength;
	sf::IntRect m_CurrentSprite;
	int m_SpriteId;
};

