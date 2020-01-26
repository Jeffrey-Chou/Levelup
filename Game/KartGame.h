#pragma once

#include <memory>
#include <stack>

#include "Screens/BaseScreen.h"

#include "SFML/Graphics.hpp"

namespace KartGame {

class BaseScreen;

class KartGame {
public:
	KartGame();
	void Run();
	void AddGameScreen();
	
private:
	std::unique_ptr<sf::RenderWindow> mWindow = nullptr;
	std::stack<std::unique_ptr<BaseScreen>> mScreenStack;
};

}