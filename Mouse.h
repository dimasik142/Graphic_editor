#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class Mouse
{
public:
	Mouse();
	~Mouse();
	void giveHeight(int value);
	void giveWitch(int value);
	int getHeight();
	int getWitch();
	void givePointPosition(sf::Vector2i position);
	void givePointDiferent(sf::Vector2i position);
	int getPointCordinate_X();
	int getPointCordinate_Y();
	int PointSize = 35;
	sf::Color color;
	sf::Color BackgroundColor = sf::Color::White;

private:
	int height = 0;
	int witch = 0;
	int X_position = 0;
	int Y_position = 0;
	int X_diferent = 0;
	int Y_diferent = 0;
};

