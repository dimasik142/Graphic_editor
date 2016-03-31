#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
class lines
{
public:
	lines();
	~lines();
	int LinePointX = 0;
	int LinePointY = 0;
	int LineBackPointX = -1;
	int LineBackPointY = -1;
	int LineSize = 4;
	int LinePositionX = 0;
	int LinePositionY = 0;
	int abs_number(int number);
	int RadiusCalculation(int x,int y);
	sf::CircleShape FirstPointIn(int x, int y, sf::Color color);
	int FirstPointX = -1, FirstPointY = -1;
	//sf::RenderTexture TextureRepeat();
	//void TextureRefresh(sf::RenderTexture texture);
private:
	//sf::RenderTexture TextureArray;

};

