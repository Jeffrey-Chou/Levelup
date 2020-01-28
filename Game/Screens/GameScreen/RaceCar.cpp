#include "Precompiled.h"
#include "RaceCar.h"

#include <cmath>

namespace KartGame {

const float RaceCar::MAX_SPEED = 15.f;
const float RaceCar::PI = 3.141592654f;
const float RaceCar::MAX_DEGREE = 10.f;

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
}
void RaceCar::Update() {
	if(mIsAccelerating) {
		mSpeed = mSpeed < MAX_SPEED ? mSpeed + 1.f : MAX_SPEED;
	}
	else {
		mSpeed = mSpeed > 0.f ? mSpeed - 1.f : 0;
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

bool RaceCar::HandleKeyPressed(sf::Keyboard::Key code)
{
	return false;
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


}