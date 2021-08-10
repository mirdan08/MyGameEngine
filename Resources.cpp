
#include "Resources.h"
Resources::Resources() {}
Resources& Resources::getInstance() {
	static Resources instance;
	return instance;
}

sf::Texture& Resources::getTexture(const std::string name) {
	return getInstance().m_Textures.getResource(name);
}

sf::SoundBuffer& Resources::getSoundBuffer(const std::string name) {
	return getInstance().m_Sounds.getResource(name);
}