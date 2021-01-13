#pragma once
//ADDING LIBRARIES
#include<iostream>
#include<string>
#include<SFML\Window.hpp>
#include<SFML\Graphics.hpp>
#include"GlobalV.h"
#include"Readers.h"
#include"Button.h"
using namespace std;
using namespace sf;

//CREATING SCREEN FUNCTION
namespace
{
	void ReaderSScreen()
	{
		system("cls");
		Texture Ima;
		Ima.loadFromFile("Image/Background.jpg");
		Sprite im(Ima);
		RenderWindow ReaderScreens(VideoMode(750, 500), "Lets Reads", Style::Titlebar | Style::Close); //CREATING THE WINDOW
		//CREATING BUTTONS
		Button BooksList("1.Books List", { 100,60 }, 30, sf::Color::Transparent);
		Button WantToRead("2.Mark As Want To Read", { 100,60 }, 30, sf::Color::Transparent);
		Button MarkedAsRead("3.Mark As Read", { 100,60 }, 30, sf::Color::Transparent);
		Button Recommend("4.Recommend Books", { 100,60 }, 30, sf::Color::Transparent);
		Button Search("5.Search A Books", { 100,60 }, 30, sf::Color::Transparent);
		Button WantToReadListBtn("6.My Want To Read List", { 100,60 }, 30, sf::Color::Transparent);
		Button Logout("7.Logout", { 100,60 }, 30, sf::Color::Transparent);

		//CHECKING AND LOADING THE FONT
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
		Search.setPosition(460, 327);
		Logout.setPosition(460, 387);
		Search.setFont(f);
		BooksList.setFont(f);
		WantToRead.setFont(f);
		Recommend.setFont(f);
		MarkedAsRead.setFont(f);
		WantToReadListBtn.setFont(f);
		Logout.setFont(f);
		Event E;
		while (ScreenCounter == 2)
		{
			while (ReaderScreens.pollEvent(E))
			{
			Point1:
				switch (E.type)
				{
				case Event::Closed:
				{
					ReaderScreens.close();
					break;
				}
				case Event::MouseMoved:
				{
					if (BooksList.isMouseover(ReaderScreens))
					{
						BooksList.settextcolor(Color::Red);
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							reader r1;
							r1.BooksListings();
							goto Point1;
						}
					}
					else if (WantToRead.isMouseover(ReaderScreens))
					{
						WantToRead.settextcolor(Color::Red);
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							reader r2;
							r2.WantToRead();
							goto Point1;
						}
					}
					else if (WantToReadListBtn.isMouseover(ReaderScreens))
					{
						WantToReadListBtn.settextcolor(Color::Red);
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							reader r6;
							r6.WantToReadBooks();
							goto Point1;
						}
					}
					else if (MarkedAsRead.isMouseover(ReaderScreens))
					{
						MarkedAsRead.settextcolor(Color::Red);
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							reader r3;
							r3.MarkAsRead();
							goto Point1;
						}
					}
					else if (Recommend.isMouseover(ReaderScreens))
					{
						Recommend.settextcolor(Color::Red);
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							reader r4;
							r4.LaunchLibrarian();
							goto Point1;
						}
					}
					else if (Search.isMouseover(ReaderScreens))
					{
						Search.settextcolor(Color::Red);
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							reader r8;
							r8.SearchBooks();
							goto Point1;
						}
					}
					else if (Logout.isMouseover(ReaderScreens))
					{
						Logout.settextcolor(Color::Red);
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							reader r5;
							r5.logout();
							ScreenCounter = 1;
							ReaderScreens.close();
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
						Search.settextcolor(sf::Color::White);
					}
				}
				}
			}

			//DRAWING ON THE SCREEN
			ReaderScreens.draw(im);
			BooksList.drawto(ReaderScreens);
			WantToRead.drawto(ReaderScreens);
			MarkedAsRead.drawto(ReaderScreens);
			Recommend.drawto(ReaderScreens);
			Search.drawto(ReaderScreens);
			WantToReadListBtn.drawto(ReaderScreens);
			Logout.drawto(ReaderScreens);
			ReaderScreens.display();
		}
	}
}
