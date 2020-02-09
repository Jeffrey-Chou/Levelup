#pragma once

#include "SFML/Graphics.hpp"

namespace KartGame {

class Track {
public:
	Track();
	void RenderTrack(sf::RenderWindow* window);
	const std::vector<sf::CircleShape>& GetTrack() const;
	const std::vector<sf::RectangleShape>& GetFlags() const;
private:
	std::vector<sf::CircleShape> mTracks;
	std::vector<sf::RectangleShape> mFlags;
};

}