#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
#include"GlobalV.h"
#include"Librarain.h"
#include"Button.h"
using namespace std;
using namespace sf;

namespace
{
	void LibrarianScreenFunc()
{
	system("cls");
	Texture Image;
	Image.loadFromFile("Image/Background.jpg");
	Sprite img(Image);
	RenderWindow LibScreen(VideoMode(750, 500), "Lets Reads", Style::Titlebar | Style::Close);
	Button ADD("1.ADD A BOOK", { 100,30 }, 30, sf::Color::Transparent);
	Button DELETE("2.DELETE A BOOK", { 100,30 }, 30, sf::Color::Transparent);
	Button LOGOUT("3.LOGOUT", { 100,30 }, 30, sf::Color::Transparent);
	Font f;
	f.loadFromFile("Fonts/Formal.ttf");
	if (!f.loadFromFile("Fonts/Formal.ttf"))
	{
		cout << "Not loaded" << endl;
	}
	ADD.setPosition(520, 27);
	DELETE.setPosition(520, 87);
	LOGOUT.setPosition(520, 147);
	ADD.setFont(f);
	DELETE.setFont(f);
	LOGOUT.setFont(f);
	Event E;
	while (ScreenCounter == 3)
	{
		while (LibScreen.pollEvent(E))
		{
			switch (E.type)
			{
			case Event::Closed:
			{
				LibScreen.close();
				break;
			}
			case Event::MouseMoved:
			{
				if (ADD.isMouseover(LibScreen))
				{
					ADD.settextcolor(Color::Red);
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						Librarian l1;
						l1.addbook();
					}
				}
				else if (DELETE.isMouseover(LibScreen))
				{
					DELETE.settextcolor(Color::Red);
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						Librarian l2;
						l2.deletebook();
					}
				}
				else if (LOGOUT.isMouseover(LibScreen))
				{
					LOGOUT.settextcolor(Color::Red);
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						Librarian L3;
						L3.logoutLibrarian();
						ScreenCounter = 1;
						LibScreen.close();
					}
				}
				else
				{
					ADD.settextcolor(Color::White);
					DELETE.settextcolor(Color::White);
					LOGOUT.settextcolor(Color::White);
				}
				}
			}
		}
		LibScreen.draw(img);
		ADD.drawto(LibScreen);
		DELETE.drawto(LibScreen);
		LOGOUT.drawto(LibScreen);
		LibScreen.display();
	}

}
}

