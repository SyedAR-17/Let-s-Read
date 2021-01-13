#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
#include"GlobalV.h"
#include"Readers.h"
#include"Librarain.h"
#include"Button.h"
using namespace std;
using namespace sf;

namespace
{
	void LoginScreen()
	{
		system("cls");
		Texture T;
		T.loadFromFile("Image/Background.jpg");
		Sprite img(T);
		RenderWindow Login(VideoMode(750, 500), "Lets Reads", Style::Titlebar | Style::Close);
		Event E;
		Button Read("1.READER", { 100,30 }, 30, sf::Color::Transparent);
		Button Lib("2.LIBRARIAN", { 100,30 }, 30, sf::Color::Transparent);
		Button ExitButton("3.EXIT", { 100,30 }, 30, sf::Color::Transparent);
		Font f;
		f.loadFromFile("Fonts/Formal.ttf");
		if (!f.loadFromFile("Fonts/Formal.ttf"))
		{
			cout << "Not loaded" << endl;
		}
		Read.setPosition(520, 27);
		Lib.setPosition(520, 87);
		ExitButton.setPosition(520, 147);
		ExitButton.setFont(f);
		Lib.setFont(f);
		Read.setFont(f);
		reader reading;
		Librarian Library;
		while (ScreenCounter == 1)
		{
			while (Login.pollEvent(E))
			{
				switch (E.type)
				{
				case Event::Closed:
				{
					Login.close();
					break;
				}
				case Event::MouseMoved:
				{
					if (Read.isMouseover(Login))
					{
						Read.settextcolor(Color::Red);
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							reading.loginS();
							ScreenCounter = 2;
							Login.close();
						}
					}
					else if (Lib.isMouseover(Login))
					{
						Lib.settextcolor(Color::Red);
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							Library.loginLibrarian();
							ScreenCounter = 3;
							Login.close();
						}
					}
					else if (ExitButton.isMouseover(Login))
					{
						ExitButton.settextcolor(Color::Red);
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							exit(1);
						}
					}
					else
					{
						Read.settextcolor(Color::White);
						Lib.settextcolor(Color::White);
						ExitButton.settextcolor(Color::White);
					}
				}
				}
			}
			Login.clear();
			Login.draw(img);
			Lib.drawto(Login);
			Read.drawto(Login);
			ExitButton.drawto(Login);
			Login.display();

		}

	}

}
