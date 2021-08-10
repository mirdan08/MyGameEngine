#include "Level.h"
#include <fstream>
#include <iostream>
void Level::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw( m_VertexArray, m_Texture);
}

std::string Level::getName() {
	return m_Name;
}

void Level::setName(const std::string name) {
	m_Name = name;
}

void Level::setTileTextures(sf::Texture& texture) {
	m_Texture = &texture;
}

void Level::setTileSize(const float size) {
	m_TileSize = size;
}

void Level::setSize(const int width,const int height) {
	m_Tiles.resize(height);
	for (auto &i : m_Tiles) {
		i.resize(width);
	}
}

void Level::addTile(const char tile, const sf::Vector2i tilePos) {
	m_TileSprites.insert(std::pair<char, sf::Vector2i>(tile, tilePos));
}

void Level::resetTiles() {
	m_Tiles.clear();
}

void Level::loadLevel(const std::string path) {
	std::ifstream input(path);
	sf::Vector2f texPos;
	sf::Vector2f curPos;
	int y = 0;//x and y coordinates for positioning the vertexes
	int x = 0;
	int i = 0;//current index of vertexes
	m_VertexArray.setPrimitiveType(sf::Quads);
	m_VertexArray.resize(32 * 32 * 4);
	for (std::string line;std::getline(input,line);) {
		x = 0;
		m_Tiles.push_back(std::vector<char>());
		for (char& c : line) {
			texPos=m_TileSprites[c];
			texPos.x *= m_TileSize;
			texPos.y *= m_TileSize;
			m_VertexArray[i + 0].position = sf::Vector2f(x*m_TileSize, y * m_TileSize);
			m_VertexArray[i + 1].position = sf::Vector2f(x * m_TileSize + m_TileSize, y * m_TileSize);
			m_VertexArray[i + 2].position = sf::Vector2f(x * m_TileSize + m_TileSize, y * m_TileSize + m_TileSize);
			m_VertexArray[i + 3].position = sf::Vector2f(x * m_TileSize, y * m_TileSize + m_TileSize);

			m_VertexArray[i + 0].texCoords = sf::Vector2f(texPos.x, texPos.y);
			m_VertexArray[i + 1].texCoords = sf::Vector2f(texPos.x+m_TileSize, texPos.y);
			m_VertexArray[i + 2].texCoords = sf::Vector2f(texPos.x + m_TileSize, texPos.y + m_TileSize);
			m_VertexArray[i + 3].texCoords = sf::Vector2f(texPos.x, texPos.y + m_TileSize);
			m_Tiles[y].push_back(c);
			i += 4;
			x++;
		}
		y++;
	}
}