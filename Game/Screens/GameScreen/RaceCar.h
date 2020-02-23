#pragma once

#include "SFML/Graphics.hpp"
#include "Track.h"

namespace KartGame {

enum class KeyBinding {up, left, right, size};

class RaceCar {
public:
	RaceCar(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color);
	void Update(const Track& track);
	
	const sf::RectangleShape& GetBody() const;
	bool HandleKeyEvent(sf::Keyboard::Key code, bool flag);
	void AddKeyBinding(sf::Keyboard::Key key, KeyBinding binding);

	void SetIsAccelerating(const bool accelerate);
	void SetTurningRight(const bool turning);
	void SetTurningLeft(const bool turning);

	void IncrementLap(const Track& track);
	int GetLap() const;
	bool IsOffTrack(const Track& track);
	void CheckCollision(const RaceCar& otherCar);
	void HandleCollision();

private:
	sf::RectangleShape mBody;
	bool mIsAccelerating = false;
	bool mIsTurningRight = false;
	bool mIsTurningLeft = false;
	float mDegree = 0;
	float mSpeed = 0.f;
	sf::Vector2f mCollisionForce;
	float mCurrentMax = MAX_SPEED;
	int mLap = 1;
	int mCheckpoint = 1;
	static constexpr float MAX_SPEED = 10.f;
	static constexpr float OFFROAD_SPEED = 1.f;
	static constexpr float PI = 3.141592654f;;
	static constexpr float MAX_DEGREE = 10.f;
	std::vector<std::pair<sf::Keyboard::Key, KeyBinding>> mKeys;
};

}