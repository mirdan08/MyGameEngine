#include "SceneManager.h"
#include "TestScene.h"
#include "TestScene2.h"
#include "Engine.h"
#include "Level.h"
int main()
{

    SceneManager::getInstance().addScene("Test",new TestScene());
    SceneManager::getInstance().addScene("Test2",new TestScene2());
    SceneManager::getInstance().loadScene("Test");
    Engine engine;
    engine.run();
    return 0;
}