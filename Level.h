#pragma once
#include <string>
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>
class Level : public sf::Drawable{
public:
	Level():m_Texture(NULL),
			m_TileSize(0),
			m_VertexArray(sf::Quads,4){};
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	std::string getName();
	void loadLevel(const std::string path);
	void setTileTextures(sf::Texture& texture);
	void setName(const std::string name);
	void setTileSize(const float size);
	void setSize(const int width, const int height);
	void addTile(const char tile,const sf::Vector2i tilePos);
	void resetTiles();
private:
	sf::Texture* m_Texture;
	sf::VertexArray m_VertexArray;
	std::string m_Name;
	std::map<char, sf::Vector2f> m_TileSprites;
	float m_TileSize;
	std::vector<std::vector<char>> m_Tiles;

};