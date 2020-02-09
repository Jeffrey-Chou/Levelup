#include "Precompiled.h"
#include "Track.h"

namespace KartGame {

Track::Track() {
	sf::CircleShape shape(200);
	
	shape.setPosition(300, 400);
	shape.setOrigin(200, 200);
	
	shape.setFillColor(sf::Color(102,51,0));
	shape.setOutlineThickness(-80);
	shape.setOutlineColor(sf::Color(128, 128, 128));
	
	shape.scale(1.3f, 1.3f);

	sf::CircleShape shape2(200);
	shape2.setOrigin(200, 200);
	shape2.setFillColor(sf::Color(102, 51, 0));
	shape2.setOutlineThickness(-80);
	shape2.setOutlineColor(sf::Color(128, 128, 128));
	shape2.scale(1.3f, 1.3f);
	shape2.move(750.f, 400.f);
	mTracks.push_back(shape);
	mTracks.push_back(shape2);

	sf::RectangleShape flag1(sf::Vector2f(120, 80));
	flag1.setFillColor(sf::Color::White);
	flag1.setPosition(40, 350);

	sf::RectangleShape flag2(sf::Vector2f(120, 80));
	flag2.setFillColor(sf::Color::White);
	flag2.setPosition(900, 350);
	mFlags.push_back(flag1);
	mFlags.push_back(flag2);
}

void Track::RenderTrack(sf::RenderWindow * window) {
	for(const sf::CircleShape& track : mTracks) {
		window->draw(track);
	}
	for(const sf::RectangleShape& flag : mFlags) {
		window->draw(flag);
	}
}

const std::vector<sf::CircleShape>& Track::GetTrack() const
{
	return mTracks;
}

const std::vector<sf::RectangleShape>& Track::GetFlags() const {
	return mFlags;
}

}
