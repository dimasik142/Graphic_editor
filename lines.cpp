#include "lines.h"
#include <SFML/Graphics.hpp>

lines::lines()
{
}


lines::~lines()
{
}

int lines::abs_number(int number){
	if (number >= 0)
		return number;
	else
		return number*(-1);
}

int lines::RadiusCalculation(int x,int y){
	if (abs_number(x - FirstPointX) < abs_number(y - FirstPointY))
		return x - FirstPointX;
	else
		return y - FirstPointY;
}

sf::CircleShape lines::FirstPointIn(int x, int y,sf::Color color){
	if (FirstPointX == -1 && FirstPointY == -1){
		FirstPointX = x;
		FirstPointY = y;
		sf::CircleShape circle(0);
		circle.setPosition(sf::Vector2f(-1, -1));
		return circle;
	}
	else{
		sf::CircleShape circle(RadiusCalculation(x,y) );
		circle.setFillColor(color);
		circle.setPosition(sf::Vector2f(FirstPointX, FirstPointY));
		FirstPointX = -1;
		FirstPointY = -1;
		return circle;
	}
}
//
//void lines::TextureRefresh(sf::RenderTexture texture){
//	for (int i = 0; i < 4; i++)
//		TextureArray[i] = TextureArray[i+1];
//	TextureArray[4] = texture;
//}
//
//sf::RenderTexture lines::TextureRepeat(){
//	for (int i = 0; i < 4; i++)
//		TextureArray[i+1] = TextureArray[i];
//	return TextureArray[4];
//}

