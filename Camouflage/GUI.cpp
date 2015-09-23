#include "GUI.h"


GUI::GUI()
{
	_window.create(sf::VideoMode(800, 600), "Solutionnaire de camouflage aux poles");
	
	//Chargement de la police
	if (!_font.loadFromFile("Fonts/SnowtopCaps.otf"))
	{
		cout << "Le chargement de la police a echouer. Vous devrez continuez en mode console!";
		return;
	}
#ifdef _DEBUG
	cout << "Chargement de la police réussi";
#endif
	
	//Affichage du message d'accueil
	write("Bienvenue au solutionnaire!", Center, 0, Header);

	_window.display();
}


void GUI::write(string text, float x, float y, TextSize size, sf::Text::Style style)
{
	sf::Text txt(text, _font, size);
	txt.setPosition(x, y);
	_window.draw(txt);
}

void GUI::write(string text, Alignment align, float y, TextSize size, sf::Text::Style style)
{
	sf::Text txt(text, _font, size);

	int x;	//Alignement horizontal du texte

	switch (align)
	{
	case Left:
		x = 10;	//Décale un peu x du coté et se dit "Good enough"
		break;
	case Center:
		x = (_window.getSize().x - txt.getGlobalBounds().width) / 2;
		break;
	case Right:
		x = _window.getSize().x - txt.getGlobalBounds().width - 10;
		break;
	}

	txt.setPosition(x, y);

	_window.draw(txt);
}