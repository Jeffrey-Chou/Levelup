#pragma once
#include <functional>
#include "SFML/Graphics.hpp"

namespace KartGame {

class Button {
public:
	Button();
	Button(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color);

	void SetSelected(const bool selected);
	bool GetSelected() const;
	const sf::RectangleShape& GetShape() const;

	sf::Text& GetText();
	const sf::Text& GetText() const;

	bool HasMouseOver(const sf::Vector2f& mousePos);
	void BindFunction(std::function<void()> func);
	void Click();
private:
	sf::RectangleShape mShape;
	sf::Text mText;
	bool mSelected = false;
	bool mHovered = false;
	std::function<void()> mOnClick = nullptr;
};

}