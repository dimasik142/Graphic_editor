#include "Mouse.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

Mouse::Mouse()
{
}

Mouse::~Mouse()
{
}

void Mouse::giveHeight(int value){
	height = value;
}

void Mouse::giveWitch(int value){
	witch = value;
}

int Mouse::getHeight(){
	return height;
}

int Mouse::getWitch(){
	return witch;
}

void Mouse::givePointPosition(sf::Vector2i position){
	sf::Vector2i v1(position);
	X_position = v1.x;
	Y_position = v1.y;
}

void Mouse::givePointDiferent(sf::Vector2i position){
	sf::Vector2i v1(position);
	X_diferent = v1.x;
	Y_diferent = v1.y;
}

int Mouse::getPointCordinate_X(){
	return (X_position - X_diferent);
}

int Mouse::getPointCordinate_Y(){
	return (Y_position - Y_diferent);
}
