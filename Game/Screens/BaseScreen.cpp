#include "Precompiled.h"
#include "BaseScreen.h"

namespace KartGame {

std::unique_ptr<sf::Font> BaseScreen::FONT = std::make_unique<sf::Font>();

void BaseScreen::HandleEvent(sf::RenderWindow * window, const sf::Event & event) {
	if (event.type == sf::Event::Closed) {
		window->close();
	}
}

void BaseScreen::Render(sf::RenderWindow * window) {
	window->clear();
	window->display();
}

void BaseScreen::LoadFont() {
	if(!FONT->loadFromFile("sansation.ttf")) {
		volatile int i = 0;
		i = i;
	}
}

void BaseScreen::SetText(sf::Text & text, const sf::String & str, const sf::Vector2f & position, const sf::Color & color) {
	text.setFont(*FONT);
	text.setString(str);
	text.setCharacterSize(100);
	text.setPosition(position);
	text.setFillColor(color);
	text.setStyle(sf::Text::Bold);
}


}
