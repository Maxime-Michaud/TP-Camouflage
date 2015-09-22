/* En-tête du programme
=========================
Programme: Camouflage
Fichier: Piece.h
Auteur : Amélie Frappier et Maxime Michaud-Corriveau
Date création : 04/09/2015
Date modification:
Description :   */

/* Directives au pré-processeur
================================= */
#pragma once
#include <iostream>
#include "Tile.h"

using namespace std;

/* Définition de la classe 
=========================== */
class Piece {

protected:

	char _name;				//nom de la pièce
	int _rotation;			//valeur de la rotation de la pièce
	Tile _tiles[2][2];		//pièce de la Tile

public:
	
	//Piece();													//constructeur par défaut
	//Piece(char name, char a1, char a2, char b1, char b2);		//constructeur avec paramètres
	virtual ~Piece();											//destructeur

	void init(char name, char a1, char a2, char b1, char b2);	//initialise la pièce

	char getName() const;										//getter du nom
	int getRotation() const;									//getter de la rotation
	Tile getTile(int line, int column) const;			//getter de la case

	void print(ostream &out) const;								//affiche la pièce

	virtual int rotation() = 0;								//Effectue une rotation

};

ostream& operator<< (ostream & out, const Piece & piece);