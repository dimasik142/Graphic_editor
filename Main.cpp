#include <SFML/Graphics.hpp>
#include <iostream>
#include "Mouse.h"
#include "lines.h"
#include <map>
#include <vector>
#include <memory>

using namespace std;
Mouse mous;
lines lineal;



int menu(){
	int menu = 0 ;
	cout << "     Enter the screen size " << endl;
	cout << " 800 / 600     Enter 1 " << endl;
	cout << " 1000 / 600    Enter 2 " << endl;
	cout << " 1300 / 700    Enter 3 " << endl;
	cout << " Enter numbers - 4 " << endl;
	cout << " Make a choice -> ";
	cin >> menu;
	if (menu == 4){
		int height = 0, witch = 0;
		cout << " Enter height ->  ";
		cin >> height;
		if ((height < 1300) && (height >0))
			mous.giveHeight(height);
		else
			mous.giveHeight(0);
		cout << " Enter witch ->  ";
		cin >> witch;
		if ((witch < 700) && (witch >0))
			mous.giveWitch(witch);
		else
			mous.giveWitch(0);
	}
	if (menu == 1){
		mous.giveHeight(800);
		mous.giveWitch(600);
	}
	if (menu == 2){
		mous.giveHeight(1000);
		mous.giveWitch(600);
	}
	if (menu == 3){
		mous.giveHeight(1300);
		mous.giveWitch(700);
	}
	system("cls");
	int DrawingMode = 0;
	cout << " What you want? " << endl;
	cout << " 1 - Draw points " << endl;
	cout << " 2 - Drav lines " << endl;
	cout << " 3 - Drav figures " << endl;
	cout << " 4 - Drav circle " << endl;
	cout << " 5 - Stirachka " << endl;
	cout << " Enter -> ";
	cin >> DrawingMode;
	return DrawingMode;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int DrawingMode = 0;
	bool StartLineSet = 0;
	DrawingMode = menu();
	mous.color = sf::Color::Blue;
	mous.BackgroundColor = sf::Color::White;
	mous.PointSize = 20;
	sf::RenderWindow window(sf::VideoMode(mous.getHeight(), mous.getWitch()), "Graphic editor");
	sf::Mouse::setPosition(sf::Vector2i(0, 0), window);
	sf::Vector2i position = sf::Mouse::getPosition();
	mous.givePointDiferent(position);
	//sf::RenderTexture RepeatTexture;
	vector<sf::Vector2f> lines;	
	sf::RenderTexture texture;
	if (!texture.create(mous.getHeight(), mous.getWitch()))
		return -1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
				mous.BackgroundColor = sf::Color::Red;
				window.clear(mous.BackgroundColor);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::G)){
				mous.BackgroundColor = sf::Color::Green;
				window.clear(mous.BackgroundColor);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
				mous.BackgroundColor = sf::Color::White;
				window.clear(mous.BackgroundColor);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
				mous.BackgroundColor = sf::Color::Blue;
				window.clear(mous.BackgroundColor);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::Y)){
				mous.BackgroundColor = sf::Color::Yellow;
				window.clear(mous.BackgroundColor);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
				DrawingMode = 1;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
				DrawingMode = 2;
				lineal.LineBackPointX = -1;
				lineal.LineBackPointY = -1;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){
				DrawingMode = 3;
				lineal.LineBackPointX = -1;
				lineal.LineBackPointY = -1;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)){
				DrawingMode = 4;
				lineal.FirstPointX = -1;
				lineal.FirstPointY = -1;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)){
				DrawingMode = 5;
				cout << " Ãóìêà " << endl;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				mous.color = sf::Color::Red;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
				mous.color = sf::Color::Green;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
				mous.color = sf::Color::Yellow;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				mous.color = sf::Color::White;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
				mous.color = sf::Color::Blue;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
				sf::Mouse::setPosition(sf::Vector2i(0, 0), window);
				sf::Vector2i position = sf::Mouse::getPosition();
				mous.givePointDiferent(position);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
				texture.clear(mous.BackgroundColor);
				lineal.LineBackPointX = -1;
				lineal.LineBackPointY = -1;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && DrawingMode == 4){
				lineal.FirstPointX = -1;
				lineal.FirstPointY = -1;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && DrawingMode == 2){
				lineal.LineBackPointX = -1;
				lineal.LineBackPointY = -1;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && DrawingMode == 3){
				lineal.LineBackPointX = -1;
				lineal.LineBackPointY = -1;
				sf::ConvexShape convex;
				convex.setPointCount(lines.size());
				for (int i = 0; i < lines.size(); i++){
					convex.setPoint(i, sf::Vector2f(lines[i]));
				}
				convex.setFillColor(mous.color);
				texture.draw(convex);
				texture.display();
				lines.clear();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
			//	texture = lineal.TextureRepeat();
			//	texture = RepeatTexture;
			/*	window.draw(texture);
				window.display();*/
			}
			else if (event.type == sf::Event::MouseWheelScrolled && DrawingMode == 1) {
				if (event.mouseWheelScroll.delta > 0) {
					mous.PointSize = mous.PointSize + 2;
				}
				else if (event.mouseWheelScroll.delta < 0) {
					if (mous.PointSize > 2){
						mous.PointSize = mous.PointSize - 2;
					}
				}
			}	
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && DrawingMode == 1){
				sf::Vector2i position = sf::Mouse::getPosition();
				mous.givePointPosition(position);
				sf::CircleShape shape(mous.PointSize);
				shape.setFillColor(mous.color);
				shape.setPosition(mous.getPointCordinate_X() - mous.PointSize, mous.getPointCordinate_Y() - mous.PointSize);
				texture.draw(shape);
				texture.display();
			} 
			else if (DrawingMode == 2 && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				sf::Vector2i position = sf::Mouse::getPosition();
				mous.givePointPosition(position);
				if (lineal.LineBackPointX == -1 && lineal.LineBackPointY == -1){
					lineal.LineBackPointX = mous.getPointCordinate_X();
					lineal.LineBackPointY = mous.getPointCordinate_Y();
					sf::CircleShape shape(1);
					shape.setFillColor(mous.color);
					shape.setPosition(sf::Vector2f(mous.getPointCordinate_X() - 0.5, mous.getPointCordinate_Y() - 0.5));
					texture.draw(shape);
					texture.display();
					StartLineSet = 1;
				}
				lineal.LinePointX = mous.getPointCordinate_X();
				lineal.LinePointY = mous.getPointCordinate_Y();
				sf::VertexArray line(sf::PrimitiveType::Lines);
				line.append(sf::Vertex(sf::Vector2f(lineal.LineBackPointX, lineal.LineBackPointY), mous.color));
				line.append(sf::Vertex(sf::Vector2f(lineal.LinePointX, lineal.LinePointY), mous.color));
				texture.draw(line);
				texture.display();
				StartLineSet = 1;
				lineal.LineBackPointX = lineal.LinePointX;
				lineal.LineBackPointY = lineal.LinePointY;
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && DrawingMode == 3){
				sf::Vector2i position = sf::Mouse::getPosition();
				mous.givePointPosition(position);
				lines.insert(lines.end(), sf::Vector2f(mous.getPointCordinate_X(), mous.getPointCordinate_Y()));
				if (lineal.LineBackPointX == -1 && lineal.LineBackPointY == -1){
					lineal.LineBackPointX = mous.getPointCordinate_X();
					lineal.LineBackPointY = mous.getPointCordinate_Y();
					sf::CircleShape shape(1);
					shape.setFillColor(mous.color);
					shape.setPosition(sf::Vector2f(mous.getPointCordinate_X() - 0.5, mous.getPointCordinate_Y() - 0.5));
					texture.draw(shape);
					texture.display();
					StartLineSet = 1;
				}
				lineal.LinePointX = mous.getPointCordinate_X();
				lineal.LinePointY = mous.getPointCordinate_Y();
				sf::VertexArray line(sf::PrimitiveType::Lines);
				line.append(sf::Vertex(sf::Vector2f(lineal.LineBackPointX, lineal.LineBackPointY), mous.color));
				line.append(sf::Vertex(sf::Vector2f(lineal.LinePointX, lineal.LinePointY), mous.color));
				texture.draw(line);
				texture.display();
				StartLineSet = 1;
				lineal.LineBackPointX = lineal.LinePointX;
				lineal.LineBackPointY = lineal.LinePointY;
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && DrawingMode == 4){
				sf::Vector2i position = sf::Mouse::getPosition();
				mous.givePointPosition(position);
				texture.draw(lineal.FirstPointIn(mous.getPointCordinate_X(), mous.getPointCordinate_Y(), mous.color));
				texture.display();
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && DrawingMode == 5){
				sf::Vector2i position = sf::Mouse::getPosition();
				mous.givePointPosition(position);
				sf::CircleShape circle(mous.PointSize);
				circle.setPosition(sf::Vector2f(mous.getPointCordinate_X() - mous.PointSize, mous.getPointCordinate_Y() - mous.PointSize));
				circle.setFillColor(mous.BackgroundColor);
				texture.draw(circle);
				texture.display();
			}
		}
		
		window.clear(mous.BackgroundColor);
		sf::Sprite sprite(texture.getTexture());
		//RepeatTexture = texture;
		window.draw(sprite);		
		//lineal.TextureRefresh(texture);
		if ((DrawingMode == 2 || DrawingMode == 3) && StartLineSet == 1){
			sf::Vector2i position = sf::Mouse::getPosition();
			mous.givePointPosition(position);
			lineal.LinePositionX = mous.getPointCordinate_X();
			lineal.LinePositionY = mous.getPointCordinate_Y();
		}
		if (DrawingMode == 1){
			sf::Vector2i position = sf::Mouse::getPosition();
			mous.givePointPosition(position);
			sf::CircleShape circle(mous.PointSize);
			circle.setPosition(sf::Vector2f(mous.getPointCordinate_X() - mous.PointSize, mous.getPointCordinate_Y() - mous.PointSize));
			circle.setOutlineColor(mous.color);
			circle.setOutlineThickness(3);
			circle.setFillColor(sf::Color::Transparent);
			window.draw(circle);
		}
		if (DrawingMode == 4 && lineal.FirstPointX != -1 && lineal.FirstPointY){
			sf::Vector2i position = sf::Mouse::getPosition();
			mous.givePointPosition(position);
			sf::CircleShape circle(lineal.RadiusCalculation(mous.getPointCordinate_X(),mous.getPointCordinate_Y() ));
			circle.setOutlineColor(mous.color);
			circle.setOutlineThickness(4);
			circle.setPosition(sf::Vector2f(lineal.FirstPointX, lineal.FirstPointY));
			window.draw(circle);
		}
		if (DrawingMode == 5){
			sf::Vector2i position = sf::Mouse::getPosition();
			mous.givePointPosition(position);
			sf::CircleShape circle(mous.PointSize);
			circle.setPosition(sf::Vector2f(mous.getPointCordinate_X() - mous.PointSize, mous.getPointCordinate_Y() - mous.PointSize));
			circle.setOutlineColor(sf::Color::Black);
			circle.setOutlineThickness(2);
			circle.setFillColor(mous.BackgroundColor);
			window.draw(circle);
		}
		sf::VertexArray line(sf::PrimitiveType::Lines);
		line.append(sf::Vertex(sf::Vector2f(lineal.LineBackPointX, lineal.LineBackPointY), mous.color));
		line.append(sf::Vertex(sf::Vector2f(lineal.LinePositionX, lineal.LinePositionY), mous.color));
		if (lineal.LineBackPointX != -1 && lineal.LineBackPointY != -1 )
			window.draw(line);			
		window.display();
	}
	return 0;
}

