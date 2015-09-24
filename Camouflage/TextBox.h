#pragma once

#include <SFML\Graphics.hpp>
#include <string>
#include <assert.h>

using namespace std;

class TextBox : public sf::Drawable
{
	string _value;					//Contenu de la textbox
	sf::Text _label;				//Étiquette de la textbox

	sf::RectangleShape _rect;		//Rectangle de la textbox
	
	int _height;

	const sf::Font * _lblFont;
	const sf::Font * _txtFont; 

	bool _lblFontFromFile, _txtFontFromFile;	//Indique s'il faut delete les fonts
	bool _multiline;

public:
	//N'initialise rien.
	TextBox();
	TextBox(string label, sf::Font & lblFont, int height, sf::RenderTarget & target);

	~TextBox();

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	//Getters et setters
	string getText() const;						//Retourne le texte contenu dans la textbox
	void setText(const string & Text);			//Permet d'afficher un texte par defaut
	string getLabel() const;					//Retourne le texte du label de la textbox
	void setLabel(const string & Text);			//Change le texte de l'étiquette
	sf::RectangleShape getPosition() const;		//Donne la position occupée par le label et la textbox combinée
	sf::RectangleShape getBox() const;			//Donne la boite de texte
	void setHeight(unsigned int y);				//Positionne verticalement la textbox
	void setLblFont(const sf::Font & font);		//Set la font du label
	void setTxtFont(const sf::Font & font);		//Set la font du texte de l'utilisateur
	bool loadLblFont(const string & path);		//Charge la font du label a partir d'un fichier
	bool loadTxtFont(const string & path);		//Charge la font du texte a partir d'un fichier
	const sf::Font* getLblFont() const;			//Get la font du label
	const sf::Font* getTxtFont() const;			//Get la font du texte de l'utilisateur
	sf::Vector2f getTxtPos() const;				//Get la position du texte

	//Donne le focus de la fenetre au textbox. Permet l'entrée de donnée. Retourne l'event qui fait perdre le focus
	sf::Event giveFocus(sf::Window & window);
};

