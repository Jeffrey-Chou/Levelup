#include "Precompiled.h"
#include "Button.h"

namespace KartGame {
Button::Button() {
	mShape.setSize(sf::Vector2f(100.0f, 100.0f));
	mShape.setOutlineColor(sf::Color::Green);
	//mShape.setOutlineThickness(1.0f);
	mShape.setPosition(sf::Vector2f(10.0f, 500.0f));
	mShape.setFillColor(sf::Color::Green);
}

Button::Button(const sf::Vector2f & size, const sf::Vector2f & position, const sf::Color & color) {
	mShape.setSize(size);
	mShape.setPosition(position);
	mShape.setOutlineColor(color);
	mShape.setFillColor(color);

	
}

void Button::SetSelected(const bool selected) {
	mSelected = selected;
}

bool Button::GetSelected() const
{
	return mSelected;
}

const sf::RectangleShape & Button::GetShape() const {
	return mShape;
}

sf::Text & Button::GetText() {
	return mText;
}

const sf::Text & Button::GetText() const {
	return mText;
}

bool Button::HasMouseOver(const sf::Vector2f & mousePos) {
	const sf::Vector2f& buttonPos = mShape.getPosition();
	const sf::Vector2f& buttonSize = mShape.getSize();
	if(mousePos.x >= buttonPos.x && mousePos.x <= buttonPos.x + buttonSize.x) {
		if(mousePos.y >= buttonPos.y && mousePos.y <= buttonPos.y + buttonSize.y) {
			return true;
		}
	}
	return false;
}

void Button::BindFunction(std::function<void()> func) {
	mOnClick = func;
}

void Button::Click() {
	mOnClick();
}

}