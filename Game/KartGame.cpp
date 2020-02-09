#include "Precompiled.h"
#include "KartGame.h"
#include <iostream>

#include "Screens/MainMenuScreen/MainMenuScreen.h"
#include "Screens/GameScreen/GameScreen.h"


namespace KartGame {

KartGame::KartGame() {
	mWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(1024, 768), "Kart Game", sf::Style::Default);
	mWindow->setFramerateLimit(60);
	mScreenStack.push(std::make_unique<MainMenuScreen>(std::bind(&KartGame::AddGameScreen, this)));
	BaseScreen::LoadFont();
}

void KartGame::Run() {
	while (mWindow->isOpen())
	{
		BaseScreen* currentScreen = mScreenStack.top().get();
		sf::Event event;
		while (mWindow->pollEvent(event))
		{
			currentScreen->HandleEvent(mWindow.get(), event);
		}
		bool popScreen = currentScreen->Update();
		currentScreen->Render(mWindow.get());
		if(popScreen) {
			mScreenStack.pop();
		}
		//mWindow->clear();

		//RenderSquare(*mWindow);
		//mWindow->display();
	}
}

void KartGame::AddGameScreen() {
	std::cout << "adding a game screen" << std::endl;
	mScreenStack.push(std::make_unique<GameScreen>());
}


}
