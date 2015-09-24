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
#include "TwoTilePiece.h"

using namespace std;

/* Constructeurs
================== */
TwoTilePiece::TwoTilePiece() {

}

TwoTilePiece::TwoTilePiece(char name, char a1, char a2, char b1, char b2) {
	//Initialise les Tiles
	init(name, a1, a2, b1, b2);
}

/* Destructeur
================ */
TwoTilePiece::~TwoTilePiece() {

}

int TwoTilePiece::rotation() {
	// Algo pour la rotation
	/*Les Tiles2Piece doivent commencer(_rotation==0) verticalement: 
		a *
		b *
	Rotation == 1:
		a b
		* *
	Rotation == 2
		b a
		* *
	Rotation == 3
		b * 
		a *
	Opérations a faire: 
		Rotation 0 -> 1
			swap(_tiles[0][1], _tiles[1][0])
		Rotation 1 -> 2
			swap(_tiles[0][0], _tiles[1][0])
		Rotation 2 -> 3
			swap(_tiles[1][0], _tiles[0][1])
		Rotation 3->0
			swap(_tiles[0][1], _tiles[0][0]

	*/
	switch (_rotation)
	{
	case 0:			
		swap(_tiles[0][1], _tiles[1][0]);
		break;
	case 1:
		swap(_tiles[0][0], _tiles[1][0]);
		break;
	case 2:
		swap(_tiles[1][0], _tiles[0][1]);
		break;
	case 3:
		swap(_tiles[0][1], _tiles[0][0]);
		break;
	}

	//Incrémente la rotation ou la reset a 0
	_rotation = (_rotation + 1) % 4;

	return _rotation;
}