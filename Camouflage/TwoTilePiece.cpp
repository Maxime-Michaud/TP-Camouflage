/* En-t�te du programme
=========================
Programme: Camouflage
Fichier: TwoTilePiece.cpp
Auteur : Am�lie Frappier et Maxime Michaud-Corriveau
Date cr�ation : 06/09/2015
Date modification:
Description :   */

/* Directives au pr�-processeur
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
	Op�rations a faire: 
		Rotation 0 -> 1
			swap(_tiles[0][1], _tiles[1][0])
		Rotation 1 -> 2
			swap(_tiles[0][0], _tiles[1][0])
		Rotation 2 -> 3
			swap(_tiles[1][0], _tiles[0][1])
		Rotation 3->0
			swap(_tiles[0][1], _tiles[0][0])

	*/
	Piece::rotation();
	//�change les pi�ces apr�s 4 ou 8 rotations pour essayer toutes les possibilit�s
	if (_rotation % 4 == 0) {
		swap(
			_tiles[_validTiles[0].first][_validTiles[0].second],
			_tiles[_validTiles[1].first][_validTiles[1].second]
			);
		//Toutes les possibilit� ont �t�s essay�es
		if (_rotation == 8)
			_rotation = 0;
	}

	return _rotation;
}