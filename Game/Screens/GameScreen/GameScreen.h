#pragma once

#include "../BaseScreen.h"

namespace KartGame {

class GameScreen : public BaseScreen {
public:
	virtual void HandleEvent(sf::RenderWindow* window, const sf::Event& event);
	virtual void Render(sf::RenderWindow* window);
private:
};

}