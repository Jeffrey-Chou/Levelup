#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
namespace KartGame {

class BaseScreen {
public:
	BaseScreen() = default;
	virtual ~BaseScreen() = default;
	virtual void HandleEvent(sf::RenderWindow* window, const sf::Event& event);
	virtual void Update() = 0;
	virtual void Render(sf::RenderWindow* window);

	static std::unique_ptr<sf::Font> FONT;
	static void LoadFont();
	static void SetText(sf::Text& text, const sf::String& str, const sf::Vector2f& position, const sf::Color& color);

private: 
};

}