/* En-t�te du programme
=========================
Programme: Camouflage
Fichier: Piece.h
Auteur : Am�lie Frappier et Maxime Michaud-Corriveau
Date cr�ation : 04/09/2015
Date modification:
Description :   */

/* Directives au pr�-processeur
================================= */
#pragma once
#include <iostream>
#include "Tile.h"

using namespace std;

/* D�finition de la classe 
=========================== */
class Piece {

protected:

	char _name;				//nom de la pi�ce
	int _rotation;			//valeur de la rotation de la pi�ce
	Tile _tiles[2][2];		//pi�ce de la Tile

public:
	
	//Piece();													//constructeur par d�faut
	//Piece(char name, char a1, char a2, char b1, char b2);		//constructeur avec param�tres
	virtual ~Piece();											//destructeur

	void init(char name, char a1, char a2, char b1, char b2);	//initialise la pi�ce

	char getName() const;										//getter du nom
	int getRotation() const;									//getter de la rotation
	Tile getTile(int line, int column) const;			//getter de la case

	void print(ostream &out) const;								//affiche la pi�ce

	virtual int rotation() = 0;								//Effectue une rotation

};

ostream& operator<< (ostream & out, const Piece & piece);