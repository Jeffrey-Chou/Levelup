#include "Precompiled.h"
#include "GameScreen.h"

KartGame::GameScreen::GameScreen()
	: mCar1(sf::Vector2f(20.0f, 30.0f), sf::Vector2f(80.0f, 400.0f), sf::Color::Green)
	, mCar2(sf::Vector2f(20.0f, 30.0f), sf::Vector2f(120.0f, 400.0f), sf::Color::Red) {
	mCar1.AddKeyBinding(sf::Keyboard::W, KeyBinding::up);
	mCar1.AddKeyBinding(sf::Keyboard::A, KeyBinding::left);
	mCar1.AddKeyBinding(sf::Keyboard::D, KeyBinding::right);

	mCar2.AddKeyBinding(sf::Keyboard::Up, KeyBinding::up);
	mCar2.AddKeyBinding(sf::Keyboard::Left, KeyBinding::left);
	mCar2.AddKeyBinding(sf::Keyboard::Right, KeyBinding::right);
}

void KartGame::GameScreen::HandleEvent(sf::RenderWindow * window, const sf::Event & event) {
	if(!mFinished) {
		if(event.type == sf::Event::KeyPressed) {
			mCar1.HandleKeyEvent(event.key.code, true);
			mCar2.HandleKeyEvent(event.key.code, true);
		}
		else if(event.type == sf::Event::KeyReleased) {
			mCar1.HandleKeyEvent(event.key.code, false);
			mCar2.HandleKeyEvent(event.key.code, false);
		}
	}
	else {
		if(event.type == sf::Event::MouseButtonPressed) {
			mExitGame = true;
		}
	}
	BaseScreen::HandleEvent(window, event);
}

bool KartGame::GameScreen::Update() {
	mCar1.Update(mTrack);
	mCar2.Update(mTrack);
	if(!mFinished) {
		if(mCar1.GetLap() > 3 && mCar2.GetLap() > 3) {
			BaseScreen::SetText(mResult, "fight to the death", sf::Vector2f(50.0f, 10.0f), sf::Color::Green);
		}
		else if(mCar1.GetLap() > 3) {
			mFinished = true;
			BaseScreen::SetText(mResult, "P1 is a winner", sf::Vector2f(50.0f, 10.0f), sf::Color::Green);
		}
		else if(mCar2.GetLap() > 3) {
			mFinished = true;
			BaseScreen::SetText(mResult, "P2 is a winner", sf::Vector2f(50.0f, 10.0f), sf::Color::Green);
		}
	}
	return mExitGame;
}

void KartGame::GameScreen::Render(sf::RenderWindow * window) {

	window->clear(sf::Color(102, 51, 0));

	mTrack.RenderTrack(window);
	window->draw(mCar1.GetBody());
	window->draw(mCar2.GetBody());
	if(mFinished) {
		window->draw(mResult);
	}
	window->display();
}
