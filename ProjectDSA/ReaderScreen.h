#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<SFML\System.hpp>
#include<SFML\Window.hpp>
#include<SFML\Graphics.hpp>
#include"GlobalV.h"
#include"Readers.h"
#include"Librarain.h"
#include"Button.h"
using namespace std;
using namespace sf;

void ReaderFuncScreen()
{
	system("cls");
	Texture Image;
	Image.loadFromFile("Image/Background.jpg");
	Sprite img(Image);
	RenderWindow ReaderScreen(VideoMode(750, 500), "Good Reads", Style::Titlebar | Style::Close);
	Button BooksList("1.Books List", { 100,60 }, 30, sf::Color::Transparent);
	Button WantToRead("2.Mark As Want To Read", { 100,60 }, 30, sf::Color::Transparent);
	Button MarkedAsRead("3.My Marked As Read", { 100,60 }, 30, sf::Color::Transparent);
	Button Recommend("4.Recommend Books", { 100,60 }, 30, sf::Color::Transparent);
	Button WantToReadListBtn("5.My Want To Read List", { 100,60 }, 30, sf::Color::Transparent);
	Button Logout("6.Logout", { 100,60 }, 30, sf::Color::Transparent);
	Font f;
	f.loadFromFile("Fonts/Formal.ttf");
	if (!f.loadFromFile("Fonts/Formal.ttf"))
	{
		cout << "Couldnt Load" << endl;
	}

	BooksList.setPosition(460, 27);
	WantToRead.setPosition(460, 87);
	MarkedAsRead.setPosition(460, 147);
	Recommend.setPosition(460, 207);
	WantToReadListBtn.setPosition(460, 267);
	Logout.setPosition(460, 327);
	BooksList.setFont(f);
	WantToRead.setFont(f);
	Recommend.setFont(f);
	MarkedAsRead.setFont(f);
	WantToReadListBtn.setFont(f);
	Logout.setFont(f);
	Event E;
	while (ScreenCounter == 2)
	{
		while (ReaderScreen.pollEvent(E))
		{
			Point1:
			switch (E.type)
			{
			case Event::Closed:
			{
				ReaderScreen.close();
				break;
			}
			case Event::MouseMoved:
			{
				if (BooksList.isMouseover(ReaderScreen))
				{
					BooksList.settextcolor(Color::Red);
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						reader r1;
						r1.BooksListings();
						goto Point1;
					}
				}
				else if (WantToRead.isMouseover(ReaderScreen))
				{
					WantToRead.settextcolor(Color::Red);
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						reader r2;
						r2.WantToRead();
						goto Point1;
					}
				}
				else if (WantToReadListBtn.isMouseover(ReaderScreen))
				{
					WantToReadListBtn.settextcolor(Color::Red);
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						reader r6;
						r6.WantToReadBooks();
						goto Point1;
					}
				}
				else if (MarkedAsRead.isMouseover(ReaderScreen))
				{
					MarkedAsRead.settextcolor(Color::Red);
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						reader r3;
						r3.MarkAsRead();
						goto Point1;
					}
				}
				else if (Recommend.isMouseover(ReaderScreen))
				{
					Recommend.settextcolor(Color::Red);
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						reader r4;
						r4.LaunchLibrarian();
						goto Point1;
					}
				}
				else if (Logout.isMouseover(ReaderScreen))
				{
					Logout.settextcolor(Color::Red);
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						reader r5;
						r5.logout();
						ScreenCounter = 1;
						ReaderScreen.close();
					}
				}
				else
				{
					BooksList.settextcolor(Color::White);
					WantToRead.settextcolor(Color::White);
					MarkedAsRead.settextcolor(Color::White);
					Recommend.settextcolor(Color::White);
					Logout.settextcolor(Color::White);
					WantToReadListBtn.settextcolor(Color::White);
				}
			}
			}
		}
		ReaderScreen.draw(img);
		BooksList.drawto(ReaderScreen);
		WantToRead.drawto(ReaderScreen);
		MarkedAsRead.drawto(ReaderScreen);
		Recommend.drawto(ReaderScreen);
		WantToReadListBtn.drawto(ReaderScreen);
		Logout.drawto(ReaderScreen);
		ReaderScreen.display();
	}
}