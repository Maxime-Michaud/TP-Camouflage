/* En-t�te du programme
=========================
Programme: Camouflage
Fichier: Tile.cpp
Auteur : Am�lie Frappier et Maxime Michaud-Corriveau
Date cr�ation : 04/09/2015
Date modification:
Description :   */

/* Directives au pr�-processeur
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
	
	if (value != NULL) {
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