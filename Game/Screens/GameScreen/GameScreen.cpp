#include "Precompiled.h"
#include "GameScreen.h"

KartGame::GameScreen::GameScreen()
	: mCar1(sf::Vector2f(20.0f, 30.0f), sf::Vector2f(60.0f, 400.0f), sf::Color::Green)
	, mCar2(sf::Vector2f(20.0f, 30.0f), sf::Vector2f(100.0f, 400.0f), sf::Color::Red) {
	mCar1.AddKeyBinding(sf::Keyboard::W, KeyBinding::up);
	mCar1.AddKeyBinding(sf::Keyboard::A, KeyBinding::left);
	mCar1.AddKeyBinding(sf::Keyboard::D, KeyBinding::right);

	mCar2.AddKeyBinding(sf::Keyboard::Up, KeyBinding::up);
	mCar2.AddKeyBinding(sf::Keyboard::Left, KeyBinding::left);
	mCar2.AddKeyBinding(sf::Keyboard::Right, KeyBinding::right);
}

void KartGame::GameScreen::HandleEvent(sf::RenderWindow * window, const sf::Event & event) {
	if(event.type == sf::Event::KeyPressed) {
		mCar1.HandleKeyEvent(event.key.code, true);
		mCar2.HandleKeyEvent(event.key.code, true);
	}
	else if(event.type == sf::Event::KeyReleased) {
		mCar1.HandleKeyEvent(event.key.code, false);
		mCar2.HandleKeyEvent(event.key.code, false);
	}
	BaseScreen::HandleEvent(window, event);
}

void KartGame::GameScreen::Update() {
	mCar1.Update(mTrack);
	mCar2.Update(mTrack);
}

void KartGame::GameScreen::Render(sf::RenderWindow * window) {

	window->clear(sf::Color(102, 51, 0));

	mTrack.RenderTrack(window);
	window->draw(mCar1.GetBody());
	window->draw(mCar2.GetBody());
	
	window->display();
}
