
#pragma once

#include <SFML\Graphics.hpp> 
#include <iostream>				//Utilisé pour les messages d'erreur
#include <string>
#include "TextBox.h"
using namespace std;

enum TextSize {
	Header = 50,
	Regular = 30,
	Small = 20
};

enum Alignment {
	Left,
	Center,
	Right
};

class GUI 
{
	sf::RenderWindow _window;	//Fenêtre dans laquelle on fait l'affichage
	sf::Font _font;				//Police de charactère utilisée

public:
	GUI();	//Initialise une fenêtre et la police et affiche un message d'accueil
	 
	void write(const string & text, float x, float y, TextSize size, sf::Text::Style style = sf::Text::Style::Regular);			//Écris du texte. Retourne
	void write(const string & text, Alignment align, float y, TextSize size, sf::Text::Style style = sf::Text::Style::Regular);	//ÉCris du texte

};


