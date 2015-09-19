/* En-tête du programme
=========================
Programme: Camouflage
Fichier: TwoTilePiece.cpp
Auteur : Amélie Frappier et Maxime Michaud-Corriveau
Date création : 06/09/2015
Date modification:
Description :   */

/* Directives au pré-processeur
================================= */
#include "ThreeTilePiece.h"

using namespace std;

/* Constructeurs
================== */
ThreeTilePiece::ThreeTilePiece() {

}

ThreeTilePiece::ThreeTilePiece(char name, char a1, char a2, char b1, char b2) {
	init(name, a1, a2, b1, b2);
}

/* Destructeur
================ */
ThreeTilePiece::~ThreeTilePiece() {

}

int ThreeTilePiece::rotation() {
	Piece::rotation();

	//Toutes les possibilités ont étés utilisées
	if (_rotation == 4)
		_rotation = 0;

	return  _rotation;
}