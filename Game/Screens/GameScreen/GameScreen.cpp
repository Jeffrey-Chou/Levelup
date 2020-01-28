#include "Precompiled.h"
#include "GameScreen.h"

KartGame::GameScreen::GameScreen()
	:mCar(sf::Vector2f(25.0f, 50.0f), sf::Vector2f(100.0f, 500.0f), sf::Color::Green){
}

void KartGame::GameScreen::HandleEvent(sf::RenderWindow * window, const sf::Event & event) {
	if(event.type == sf::Event::MouseButtonPressed) {
		window->close();
	}
	else if(event.type == sf::Event::KeyPressed) {
		if(event.key.code == sf::Keyboard::W) {
			mCar.SetIsAccelerating(true);
		}
		if(event.key.code == sf::Keyboard::D) {
			mCar.SetTurningRight(true);
		}
		if(event.key.code == sf::Keyboard::A) {
			mCar.SetTurningLeft(true);
		}
	}
	else if(event.type == sf::Event::KeyReleased) {
		if(event.key.code == sf::Keyboard::W) {
			mCar.SetIsAccelerating(false);
		}
		if(event.key.code == sf::Keyboard::D) {
			mCar.SetTurningRight(false);
		}
		if(event.key.code == sf::Keyboard::A) {
			mCar.SetTurningLeft(false);
		}
	}
}

void KartGame::GameScreen::Update() {
	mCar.Update();
}

void KartGame::GameScreen::Render(sf::RenderWindow * window) {
	window->clear();
	window->draw(mCar.GetBody());
	window->display();
}
