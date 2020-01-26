#include "Precompiled.h"
#include "MainMenuScreen.h"
namespace KartGame {
MainMenuScreen::MainMenuScreen(std::function<void()> func)
	: mPlayButton(sf::Vector2f(200.0f, 100.0f), sf::Vector2f(10.0f, 500.0f), sf::Color::Green){

	BaseScreen::SetText(mTitle, "Kart Game", sf::Vector2f(50.0f, 10.0f), sf::Color::Green);
	BaseScreen::SetText(mPlayButton.GetText(), "Start", mPlayButton.GetShape().getPosition(), sf::Color::White);
	mPlayButton.BindFunction(func);
}
void MainMenuScreen::HandleEvent(sf::RenderWindow * window, const sf::Event & event) {
	if(event.type == sf::Event::MouseButtonPressed) {
		sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
		if(mPlayButton.HasMouseOver(mousePos)) {
			mPlayButton.Click();
			//mPlayButton.
			//window->close();
		}
	}
}

void MainMenuScreen::Render(sf::RenderWindow * window) {
	window->clear();
	window->draw(mTitle);
	window->draw(mPlayButton.GetShape());
	window->draw(mPlayButton.GetText());
	window->display();
}

}
