#pragma once

#include "../BaseScreen.h"
#include "RaceCar.h"
#include "Track.h"

namespace KartGame {

class GameScreen : public BaseScreen {
public:
	GameScreen();
	virtual void HandleEvent(sf::RenderWindow* window, const sf::Event& event);
	virtual bool Update();
	virtual void Render(sf::RenderWindow* window);
private:
	RaceCar mCar1;
	RaceCar mCar2;
	Track mTrack;
	sf::Text mResult;
	bool mFinished = false;
	bool mExitGame = false;
};

}