/* En-tête du programme
=========================
Programme:			Camouflage
Fichier:			Tile.h
Auteur :			Amélie Frappier et Maxime Michaud-Corriveau
Date création :		04/09/2015
Date modification:
Description :   */

/* Directives au pré-processeur
================================= */
#pragma once
#include <iostream>

using namespace std;

/* Définition de la classe
=========================== */
class Tile {

private:
	char _value;		//valeur contenue dans la pièce
	bool _valid;		//indique si la Tile contient quelque chose ou est vide

public:
	
	Tile();					//constructeur sans paramètres
	~Tile();				//destructeur
	
	char getValue() const;			//getter de la valeur
	bool getValid() const;			//getter de la valeur de validation

	void setValue(char value);		//setter de la valeur
	void setValid(bool valid);		//setter de la valeur de validation
};