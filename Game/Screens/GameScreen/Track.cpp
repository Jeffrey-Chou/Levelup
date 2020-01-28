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
}

void Track::RenderTrack(sf::RenderWindow * window) {
	for(const sf::CircleShape& track : mTracks) {
		window->draw(track);
	}
}

const std::vector<sf::CircleShape>& Track::GetTrack() const
{
	return mTracks;
}

}
