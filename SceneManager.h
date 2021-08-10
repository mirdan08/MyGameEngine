#pragma once
#include "Scene.h"
#include "Window.h"
#include "EntityManager.h"
#include <Map>
class SceneManager {
public:
	void input();
	void update(const float dt);
	void draw(Window& window);
	void loadScene(const std::string scene);
	void addScene(std::string name,Scene *scene);
	sf::View& getCamera();
	static SceneManager& getInstance();

private:
	//EntityManager m_EntityManager;
	sf::View m_Camera;
	SceneManager();
	Scene* m_CurScene;
	std::map<std::string, Scene*> m_Scenes;
};