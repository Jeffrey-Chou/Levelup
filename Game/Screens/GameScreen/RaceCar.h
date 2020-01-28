#pragma once

#include "SFML/Graphics.hpp"

namespace KartGame {

enum class KeyBinding {up, left, right, size};

class RaceCar {
public:
	RaceCar(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color);
	void Update();
	
	const sf::RectangleShape& GetBody() const;
	bool HandleKeyEvent(sf::Keyboard::Key code, bool flag);
	void AddKeyBinding(sf::Keyboard::Key key, KeyBinding binding);

	void SetIsAccelerating(const bool accelerate);
	void SetTurningRight(const bool turning);
	void SetTurningLeft(const bool turning);
private:
	sf::RectangleShape mBody;
	bool mIsAccelerating = false;
	bool mIsTurningRight = false;
	bool mIsTurningLeft = false;
	float mDegree = 0;
	float mSpeed = 0.f;
	static const float MAX_SPEED;
	static const float PI;
	static const float MAX_DEGREE;
	std::vector<std::pair<sf::Keyboard::Key, KeyBinding>> mKeys;
};

}