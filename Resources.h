#pragma once

#ifndef RESOURCES_H
#define RESOURCES_H


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourceManager.h"
class Resources {
public:
	 static sf::Texture& getTexture(const std::string name);
	 static sf::SoundBuffer& getSoundBuffer(const std::string name);

private:
	static Resources& getInstance();
	Resources() ;
	ResourceManager<sf::Texture> m_Textures;
	ResourceManager<sf::SoundBuffer> m_Sounds;
};
#endif
