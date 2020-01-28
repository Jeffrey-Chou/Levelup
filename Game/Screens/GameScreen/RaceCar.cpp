#include "Precompiled.h"
#include "RaceCar.h"

#include <cmath>

namespace KartGame {

//const float RaceCar::MAX_SPEED = 10.f;
//const float RaceCar::OFFROAD_SPEED = 5.f;
//const float RaceCar::PI = 3.141592654f;
//const float RaceCar::MAX_DEGREE = 10.f;

RaceCar::RaceCar(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color) {
	//mBody.setSize(sf::Vector2f(100.0f, 100.0f));
	//mBody.setOrigin(50, 50);
	//mBody.setOutlineColor(sf::Color::Green);
	//mBody.setOutlineThickness(1.0f);
	//mBody.setPosition(sf::Vector2f(10.0f, 500.0f));
	//mBody.setFillColor(sf::Color::Green);
	mBody.setSize(size);
	mBody.setOrigin(size.x / 2, size.y / 2);
	mBody.setPosition(position);
	mBody.setOutlineColor(color);
	mBody.setFillColor(color);
	mKeys.reserve(static_cast<size_t>(KeyBinding::size));
}
void RaceCar::Update(const Track& track) {
	if(IsOffTrack(track)) {
		mCurrentMax = OFFROAD_SPEED;
	}
	else {
		mCurrentMax = MAX_SPEED;
	}
	if(mIsAccelerating) {
		mSpeed = mSpeed < mCurrentMax ? mSpeed + 0.25f : mCurrentMax;
	}
	else {
		mSpeed = mSpeed > 0.f ? mSpeed - 0.25f : 0;
	}
	if(mIsTurningRight) {
		mDegree = mDegree < MAX_DEGREE ? mDegree + 0.25f : MAX_DEGREE;
		//mBody.setRotation(++mDegree);
	}
	if(mIsTurningLeft) {
		mDegree = mDegree > -MAX_DEGREE ? mDegree - 0.25f : -MAX_DEGREE;
		//mBody.setRotation(--mDegree);
	}
	if(!mIsTurningRight && !mIsTurningLeft){
		mDegree = 0;
	}
	if(mSpeed) {
		mBody.rotate(mDegree);
		mBody.move(sf::Vector2f(std::sinf(mBody.getRotation() * PI / 180) * mSpeed, -std::cosf(mBody.getRotation() * PI / 180) * mSpeed));
	}
	
}



const sf::RectangleShape & RaceCar::GetBody() const {
	return mBody;
}

bool RaceCar::HandleKeyEvent(sf::Keyboard::Key code, bool flag) {
	KeyBinding binding = KeyBinding::size;
	for(const auto key : mKeys) {
		if(key.first == code) {
			binding = key.second;
			break;
		}
	}
	switch(binding) {
	case KeyBinding::up:
		SetIsAccelerating(flag);
		break;
	case KeyBinding::left:
		SetTurningLeft(flag);
		break;
	case KeyBinding::right:
		SetTurningRight(flag);
		break;
	default:
		return false;
	}
	return true;
}

void RaceCar::AddKeyBinding(sf::Keyboard::Key key, KeyBinding binding) {
	mKeys.push_back(std::pair<sf::Keyboard::Key, KeyBinding>(key, binding));
}

void RaceCar::SetIsAccelerating(const bool accelerate) {
	mIsAccelerating = accelerate;
}

void RaceCar::SetTurningRight(const bool turning) {
	mIsTurningRight = turning;
}

void RaceCar::SetTurningLeft(const bool turning) {
	mIsTurningLeft = turning;
}

bool RaceCar::IsOffTrack(const Track & track) {
	std::vector<float> distances;
	bool isInCircle = false;
	distances.reserve(4);
	const sf::FloatRect carBounds = mBody.getGlobalBounds();
	for(const sf::CircleShape& track : track.GetTrack()) {
		const sf::Vector2f& trackOrigin = track.getPosition();
		float innerRadius = track.getRadius() + track.getOutlineThickness();
		//float distance = std::hypot(trackOrigin.x - carBounds.left, trackOrigin.y - carBounds.top);
		CalculateDistances(distances, trackOrigin, carBounds);
		for(float distance : distances) {
			if(distance < track.getRadius()) {
				isInCircle = true;
			}
			if(distance < innerRadius) {
				return true;
			}
		}
		distances.clear();
	}
	return false;
}

void RaceCar::CalculateDistances(std::vector<float>& distances, const sf::Vector2f& origin, const sf::FloatRect & bounds) {
	distances.push_back(std::hypot(origin.x - bounds.left, origin.y - bounds.top));
	distances.push_back(std::hypot(origin.x - bounds.left + bounds.width, origin.y - bounds.top));
	distances.push_back(std::hypot(origin.x - bounds.left, origin.y - bounds.top + bounds.height));
	distances.push_back(std::hypot(origin.x - bounds.left + bounds.width, origin.y - bounds.top + bounds.height));
}


}