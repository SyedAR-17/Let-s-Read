#pragma once
//LIBRARIES
#include<iostream>
#include<string>
#include<SFML\Graphics.hpp>

using namespace std;
using namespace sf;

//CLASS
class Button
{
	Text text; //DATA MEMBERS
	RectangleShape button;
public:
	Button(string t, Vector2f size, int chrsize, sf::Color bgcolor)//CONSTRUCTOR
	{
		text.setString(t);
		text.setCharacterSize(chrsize);
		
		button.setSize(size);
		button.setFillColor(bgcolor);
	}

	//SETTING THE FONT
	void setFont(Font &font)
	{
		text.setFont(font);
	}

	//SETTING THE TEXT COLOR
	void settextcolor(sf::Color color)
	{
		text.setFillColor(color);
	}

	//SETTING THE RECT COLOR
	void setbackcolor(Color color)
	{
		button.setFillColor(color);
	}

	//SETTING THE POSITON
	void setPosition(int x,int y)
	{
		button.setPosition(x,y);
		float xpos = button.getPosition().x + (button.getGlobalBounds().width/ 6.f) - text.getGlobalBounds().width / 6.f;
		float ypos = button.getPosition().y + (button.getGlobalBounds().height / 100.f)- text.getGlobalBounds().height / 100.f;
		//SETTING THE TEXT POSITION
		text.setPosition({ xpos,ypos });
	}

	//DRAW THE BUTTON ON THE SCREEN
	void drawto(RenderWindow& window)
	{
		window.draw(button);
		window.draw(text);
	}

	//CHECKING IF THE MOUSE HAS MOVED OVER THE BUTTON
	bool isMouseover(RenderWindow& window)
	{
		float mouseX = Mouse::getPosition(window).x;
		float mouseY = Mouse::getPosition(window).y;

		float btnposX = button.getPosition().x;
		float btnposY = button.getPosition().y;

		float btnxposwidth = button.getPosition().x + button.getGlobalBounds().width;
		float btnyposheight = button.getPosition().y + button.getGlobalBounds().height;

		if (mouseX < btnxposwidth && mouseX >btnposX&& mouseY<btnyposheight && mouseY > btnposY)
		{
			return true;
		}
		return false;
	}

};