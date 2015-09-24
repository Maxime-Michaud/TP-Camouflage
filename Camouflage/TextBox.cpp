#include "TextBox.h"


TextBox::TextBox()
{
	_lblFont = _txtFont = nullptr;
	_lblFontFromFile = _txtFontFromFile = false;
	_height = 0;
}

TextBox::TextBox(string label, sf::Font & lblFont,int height, sf::RenderTarget & target)
{
	_txtFont = nullptr;
	_lblFontFromFile = _txtFontFromFile = false;
	_lblFont = &lblFont;
	_height = height;


	//Création de l'étiquette
	_label = sf::Text(label, *_lblFont);
	_label.setPosition(sf::Vector2f(10, height));

	//Création du textbox
	_rect = sf::RectangleShape(sf::Vector2f(250, 45));
	_rect.setOutlineColor(sf::Color(120, 120, 120, 255));
	_rect.setOutlineThickness(2);

	//Vérifie si tout rentre sur une ligne et assigne la valeur a _multiline
	if (_multiline = ((target.getSize().x - _label.getGlobalBounds().width) < 300))
		_rect.setPosition(sf::Vector2f(10, height + 25 + _label.getGlobalBounds().height));
	else
		_rect.setPosition(sf::Vector2f(50 + _label.getGlobalBounds().width, height));


}

TextBox::~TextBox()
{
	if (_lblFontFromFile)
		delete _lblFont;
	if (_txtFontFromFile)
		delete _txtFont;
}

//Code pour SFML
void TextBox::draw(sf::RenderTarget & target, sf::RenderStates states)const
{
	target.draw(_label);
	target.draw(_rect);

	//Dessine le contenu de la textbox. Si le texte n'a pas de police, utilise celle de l'étiquette
	sf::Text text;

	if (_txtFont != nullptr)
		text = sf::Text(_value, *_txtFont);
	else 
		text = sf::Text(_value, *_lblFont);

	text.setPosition(getTxtPos());
	target.draw(text);
}

//Getter et Setter
//Obtiens le texte de la textbox
string TextBox::getText() const
{
	return _value;
}

//Set le texte dans la textbox. Permet d'afficher des valeurs par défaut
void TextBox::setText(const string & Text)
{
	_value = Text;
}

//Obtiens le texte de l'étiquette
string TextBox::getLabel() const
{
	//Le constructeur de sf::Text initialise sa variable m_string a "", donc pas de danger même si label n'a pas encore reçu de texte
	return _label.getString();
}

//Change l'étiquette. _lblFont doit etre initialisé avant
void TextBox::setLabel(const string & Text)
{
	//Si la font de l'étiquette n'est pas initialisée, quitte le programme 
	assert(_lblFont != nullptr);

	_label = sf::Text(Text, *_lblFont);
	_label.setPosition(sf::Vector2f(10, _height));
}

//Obtiens l'espace utilisé par la textbox et la label
sf::RectangleShape TextBox::getPosition() const
{

	//Calcule la largeur totale
	int Width = _label.getGlobalBounds().width + _rect.getGlobalBounds().width + 50;
	
	//Additionne les  deux hauteurs si multiline, sinon choisis la plus haute
	int height = _multiline? 25 + _rect.getGlobalBounds().height + _label.getGlobalBounds().height :
				  _label.getGlobalBounds().height >= _rect.getGlobalBounds().height ?
					  _label.getGlobalBounds().height :
					  _rect.getGlobalBounds().height;
	int left = _label.getGlobalBounds().left;
	int top = _label.getGlobalBounds().top;

	sf::RectangleShape rect(sf::Vector2f(Width, height));
	rect.setPosition(sf::Vector2f(left, top));
	return rect;

}

//Donne la boite de texte
sf::RectangleShape TextBox::getBox() const
{
	return _rect;
}

//Set la hauteur
void TextBox::setHeight(unsigned int y)
{
	_height = y;

	//Repositionne les éléments du textbox
	_label.setPosition(_label.getPosition().x, y);

	if (!_multiline)
		_rect.setPosition(_rect.getPosition().x, y);
	else
		_rect.setPosition(_rect.getPosition().x, y + 25 + _label.getGlobalBounds().height);
}

//set la font du label
void TextBox::setLblFont(const sf::Font & font)
{
	//Libère la mémoire si elle a été chargée dynamiquement
	if (_lblFontFromFile)
	{
		_lblFontFromFile = false;
		delete _lblFont;
	}

	_lblFont = &font;
	_label.setFont(*_lblFont);
}

//set la font du texte entré par l'utilisateur
void TextBox::setTxtFont(const sf::Font & font)
{
	//Libère la mémoire si elle a été chargée dynamiquement
	if (_txtFontFromFile)
	{
		_txtFontFromFile = false;
		delete _txtFont;
	}

	_txtFont = &font;
}

//Charge la font du label a partir d'un fichier. la valeur de retour indique le succès ou l'échec du chargement
bool TextBox::loadLblFont(const string & path)
{
	//Charge la police dans une police temporaire puisque _lblFont pointe vers des const
	auto font = new sf::Font;

	//En cas d'échec
	if (!font->loadFromFile(path))
	{
		delete font;
		return false;
	}

	_label.setFont(*_lblFont);
	_lblFontFromFile = true;
	_lblFont = font;

	return true;
}

//Charge la font du textbox a partir d'un fichier. la valeur de retour indique le succès ou l'échec du chargement
bool TextBox::loadTxtFont(const string & path)
{
	//Charge la police dans une police temporaire puisque _lblFont pointe vers des const
	auto font = new sf::Font;

	//En cas d'échec
	if (!font->loadFromFile(path))
	{
		delete font;
		return false;
	}

	_txtFontFromFile = true;
	_txtFont = font;

	return true;
}

//Donne la font du label
const sf::Font* TextBox::getLblFont() const
{
	return _lblFont;
}

//Donne la font du texte
const sf::Font * TextBox::getTxtFont() const
{
	return _txtFont;
}

sf::Vector2f TextBox::getTxtPos() const
{
	return sf::Vector2f(
			_rect.getGlobalBounds().left + 10,
			_rect.getGlobalBounds().top
		);
}