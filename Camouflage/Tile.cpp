/* En-tête du programme
=========================
Programme:		Camouflage
Fichier:		Tile.cpp
Auteur :		Amélie Frappier et Maxime Michaud-Corriveau
Création :		04/09/2015
Modification:	04/09/2015
Description :   */

/* Directives au pré-processeur
================================= */
#include "Tile.h"

using namespace std;

/* Constructeur 
================ */
Tile::Tile() {

}

/* Destructeur 
=============== */
Tile::~Tile() {

}

/* Getters
============ */
char Tile::getValue() const {
	return _value;
}

bool Tile::getValid() const {
	return _valid;
}

/* Setters 
=========== */
void Tile::setValue(char value) {
	
	if (value != '\0') {
		_value = value;
		_valid = true;
	} 
	else {
		_valid = false;
	}
}

void Tile::setValid(bool valid) {
	_valid = valid;
}