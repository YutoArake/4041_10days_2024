#include "SceneFactory.h"
#include "GameTitleScene.h"
#include "GameSelectScene.h"
#include "GameLoadScene.h"
#include "GameDemoScene.h"
#include "GamePlayScene.h"
#include "GameClearScene.h"
#include "GameOverScene.h"

BaseScene* SceneFactory::CreateScene(const std::string& sceneName)
{
    // éüÇÃÉVÅ[ÉìÇê∂ê¨
    BaseScene* newScene = nullptr;

    if (sceneName == "TITLE") {
        newScene = new GameTitleScene();
    }
    else if (sceneName == "SELECT") {
        newScene = new GameSelectScene();
    }
    else if (sceneName == "LOAD") {
        newScene = new GameLoadScene();
    }
    else if (sceneName == "DEMO") {
        newScene = new GameDemoScene();
    }
    else if (sceneName == "PLAY") {
        newScene = new GamePlayScene();
    }
    else if (sceneName == "CLEAR") {
        newScene = new GameClearScene();
    }
    else if (sceneName == "GAMEOVER") {
        newScene = new GameOverScene();
    }

    return newScene;
}