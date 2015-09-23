
#pragma once

#include <SFML\Graphics.hpp> 
#include <iostream>				//Utilis� pour les messages d'erreur
#include <string>
using namespace std;

enum TextSize {
	Header = 50,
	Regular = 30,
	FinePrint = 12
};

enum Alignment {
	Left,
	Center,
	Right
};

class GUI 
{
	sf::RenderWindow _window;	//Fen�tre dans laquelle on fait l'affichage
	sf::Font _font;				//Police de charact�re utilis�e

public:
	GUI();	//Initialise une fen�tre et la police et affiche un message d'accueil
	 
	void write(string text, float x, float y, TextSize size, sf::Text::Style style = sf::Text::Style::Regular);			//�cris du texte
	void write(string text, Alignment align, float y, TextSize size, sf::Text::Style style = sf::Text::Style::Regular);	//�Cris du texte

};


