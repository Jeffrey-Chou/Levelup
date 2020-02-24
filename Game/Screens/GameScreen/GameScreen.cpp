#include "Precompiled.h"
#include "GameScreen.h"
#include <cstdlib>

KartGame::GameScreen::GameScreen()
	: mCar1(sf::Vector2f(20.0f, 30.0f), sf::Vector2f(80.0f, 500.0f), sf::Color::Green)
	, mCar2(sf::Vector2f(20.0f, 30.0f), sf::Vector2f(120.0f, 500.0f), sf::Color::Red) {
	mCar1.AddKeyBinding(sf::Keyboard::W, KeyBinding::up);
	mCar1.AddKeyBinding(sf::Keyboard::A, KeyBinding::left);
	mCar1.AddKeyBinding(sf::Keyboard::D, KeyBinding::right);

	mCar2.AddKeyBinding(sf::Keyboard::Up, KeyBinding::up);
	mCar2.AddKeyBinding(sf::Keyboard::Left, KeyBinding::left);
	mCar2.AddKeyBinding(sf::Keyboard::Right, KeyBinding::right);
}

void KartGame::GameScreen::HandleEvent(sf::RenderWindow * window, const sf::Event & event) {
	switch(mState) {
	case GameState::Start: case GameState::CountDown:
		break;
	case GameState::RaceTime:
		if(event.type == sf::Event::KeyPressed) {
			mCar1.HandleKeyEvent(event.key.code, true);
			mCar2.HandleKeyEvent(event.key.code, true);
		}
		else if(event.type == sf::Event::KeyReleased) {
			mCar1.HandleKeyEvent(event.key.code, false);
			mCar2.HandleKeyEvent(event.key.code, false);
		}
		break;
	case GameState::Finished:
		if(event.type == sf::Event::MouseButtonPressed) {
			mState = GameState::Exit;
		}
		break;
	default:
		BaseScreen::HandleEvent(window, event);
	}
	
}

bool KartGame::GameScreen::Update() {
	switch(mState) {
	case GameState::Start: 
		mState = GameState::CountDown;
		mClock.restart();
	case GameState::CountDown:
		BaseScreen::SetText(mGameText, std::to_string(static_cast<int>(4 - mClock.getElapsedTime().asSeconds())), sf::Vector2f(500.0f, 10.0f), 100, sf::Color::Green);
		if(mClock.getElapsedTime().asSeconds() > 3) {
			mClock.restart();
			mGameText.setString("");
			mState = GameState::RaceTime;
		}
		break;
	case GameState::RaceTime:
		BaseScreen::SetText(mGameText, std::to_string(mClock.getElapsedTime().asSeconds()), sf::Vector2f(400.0f, 10.0f), 50, sf::Color::Green);
	case GameState::Finished:
		mCar1.Update(mTrack);
		mCar2.Update(mTrack);
		mCar1.CheckCollision(mCar2);
		mCar2.CheckCollision(mCar1);
		mCar1.HandleCollision();
		mCar2.HandleCollision();
		if(mCar1.GetLap() > 3 && mCar2.GetLap() > 3) {
			BaseScreen::SetText(mGameText, "fight to the death", sf::Vector2f(50.0f, 10.0f), 100, sf::Color::Green);
		}
		else if(mCar1.GetLap() > 3) {
			mState = GameState::Finished;
			BaseScreen::SetText(mGameText, "P1 is a winner", sf::Vector2f(50.0f, 10.0f), 100, sf::Color::Green);
		}
		else if(mCar2.GetLap() > 3) {
			mState = GameState::Finished;
			BaseScreen::SetText(mGameText, "P2 is a winner", sf::Vector2f(50.0f, 10.0f), 100, sf::Color::Green);
		}

		break;
	}

	return mState == GameState::Exit;
}

void KartGame::GameScreen::Render(sf::RenderWindow * window) {

	window->clear(sf::Color(102, 51, 0));

	mTrack.RenderTrack(window);
	window->draw(mCar1.GetBody());
	window->draw(mCar2.GetBody());
	window->draw(mGameText);
	window->display();
}
