/* En-t�te du programme
=========================
Programme: Camouflage
Fichier: Case.cpp
Auteur : Am�lie Frappier et Maxime Michaud-Corriveau
Date cr�ation : 04/09/2015
Date modification:
Description :   */

/* Directives au pr�-processeur
================================= */
#include "Case.h"

using namespace std;

/* Constructeur 
================ */
Case::Case() {

}

/* Destructeur 
=============== */
Case::~Case() {

}

/* Getters
============ */
char Case::getValue() const {
	return _value;
}

bool Case::getValid() const {
	return _valid;
}

/* Setters 
=========== */
void Case::setValue(char value) {
	_value = value;
}

void Case::setValid(bool valid) {
	_valid = valid;
}