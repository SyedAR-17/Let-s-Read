#pragma once
//LIBRARIES
#include<iostream>
#include<SFML\Graphics.hpp>
#include"GlobalV.h"
#include"Button.h"
using namespace std;
using namespace sf;


//SCREEN FUNCTION
void MainScreen()
{
	string input; //INPUT VARAIBLE
	RenderWindow MainScreen(VideoMode(750, 500), "Lets Read", Style::Titlebar | Style::Close); //CREATING THE WINDOW
	Event E; //EVENT CAPTURE VARAIBLE
	Texture Image; //TO CREATE AN AND DRAW AN IMAGE
	Font f; 
	//FONT AND LOADING THE FONT 
	f.loadFromFile("Fonts/Formal.ttf");
	if (!f.loadFromFile("Fonts/Formal.ttf")) //ERROR CATCHING
	{
		cout << "Not loaded" << endl;
	}
	//LOADING THE IMAGE TO DRAW ON BG
	Image.loadFromFile("Image/Background.jpg");
	Sprite img(Image); //CREATING TE SPRITE
	Button Login("Login", { 100,30 }, 30, sf::Color::Transparent); //CREATING BUTTONS
	Button EXIT("EXIT", { 100,30 }, 30, sf::Color::Transparent);

	//SETTING BUTTON PROPERTIES
	Login.setPosition(530, 150);
	EXIT.setPosition(530, 200);
	Login.setFont(f);
	EXIT.setFont(f);
	Text readerText;
	readerText.setPosition(450, 50);
	readerText.setFont(f);
	readerText.setCharacterSize(60);
	readerText.setFillColor(Color::White);
	readerText.setString("LETS READ");

	//LOOPING THE SCREEN
	while (ScreenCounter==0)
	{
		while (MainScreen.pollEvent(E))
		{
			switch (E.type) //CATCHING THE EVENT TO SWTICH ON IT
			{
			case Event::Closed:
			{
				MainScreen.close();
				break;
			}
			case Event::MouseMoved:
				if (Login.isMouseover(MainScreen) || EXIT.isMouseover(MainScreen)) //CATCHING THE MOUSE EVENT
				{
					if (Login.isMouseover(MainScreen))
					{
						Login.settextcolor(Color::Red);
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							MainScreen.close();
							ScreenCounter = 1;
						}
					}
					else
					{
						EXIT.settextcolor(Color::Red);
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							exit(1);
						}
					}
				}
				else //CATCHING IF THE MOUSE IS NOT OVER
				{
					Login.setbackcolor(Color::Transparent);
					Login.settextcolor(Color::White);
					EXIT.setbackcolor(Color::Transparent);
					EXIT.settextcolor(Color::White);
				}
			}
		}

		//DRAWING ALL THE EVENTS ON THE SCREEN
		MainScreen.draw(img);
		Login.drawto(MainScreen);
		EXIT.drawto(MainScreen);
		MainScreen.draw(readerText);
		MainScreen.draw(readerText);
		MainScreen.display();

	}
}