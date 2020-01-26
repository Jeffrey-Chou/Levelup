#include "Precompiled.h"
#include "GameScreen.h"

void KartGame::GameScreen::HandleEvent(sf::RenderWindow * window, const sf::Event & event) {
	if(event.type == sf::Event::MouseButtonPressed) {
		window->close();
	}
}

void KartGame::GameScreen::Render(sf::RenderWindow * window) {
	window->clear();
	window->display();
}
