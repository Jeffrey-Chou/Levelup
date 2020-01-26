#pragma once
#include "../BaseScreen.h"
#include "../Button.h"

namespace KartGame {

class MainMenuScreen : public BaseScreen {

public:
	MainMenuScreen(std::function<void()> func);
	virtual ~MainMenuScreen() = default;
	virtual void HandleEvent(sf::RenderWindow* window, const sf::Event& event) override;
	virtual void Render(sf::RenderWindow* window);
private:
	sf::Text mTitle;
	Button mPlayButton;

};

}