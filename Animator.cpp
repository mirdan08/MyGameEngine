#include "Animator.h"

Animator::Animator(sf::Texture& texture, const int width, const int height) {
	m_SpriteSheet.setTexture(texture);
	m_CurrentSprite.height = height;
	m_CurrentSprite.width = width;
	m_SpriteSheet.setOrigin(width / 2, height / 2);
}

void Animator::addAnim(const std::string name, const int pos, const int length, const float time) {
	Animation anim{pos,length,time};
	m_Animations.insert(std::pair<std::string,Animation>(name,anim));
}

void Animator::update(const float dt) {
	m_CurrentTime += dt;
	if (m_CurrentTime >= m_CurrentAnimation.length * m_FrameLength) {
		m_SpriteId = 0;
		m_CurrentTime = 0;
	}
	if (m_CurrentTime >= (m_SpriteId + 1)*m_FrameLength) {
		m_SpriteId++;
	}
	m_CurrentSprite.left = m_SpriteId * m_CurrentSprite.width;
	m_SpriteSheet.setTextureRect(m_CurrentSprite);
}

void Animator::selectAnim(const std::string name) {
	if (m_Name == name)
		return;
	m_Name = name;
	m_CurrentAnimation = m_Animations[name];
	m_FrameLength = m_CurrentAnimation.time / m_CurrentAnimation.length;
	m_CurrentSprite.top = m_CurrentAnimation.pos * m_CurrentSprite.height;
	m_CurrentTime = 0;
	m_SpriteId = 0;
}

void Animator::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(m_SpriteSheet);
}

void Animator::setPosition(const float x, const float y) {
	m_SpriteSheet.setPosition(x, y);
}