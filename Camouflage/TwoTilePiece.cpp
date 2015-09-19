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

	//inidique si la premi�re pi�ce a �t� trouv�e
	bool foundFirst = false;
	//Trouve les tiles qui sont valide et store leur coordonn�es dans deux paires
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (_tiles[i][j].getValid()) {
				if (!foundFirst) {
					foundFirst = true;
					_validTiles[0].first = i;
					_validTiles[0].second = j;
				}
				else {
					_validTiles[1].first = i;
					_validTiles[1].second = 1;
				}
			}
		}
	}
}

/* Destructeur
================ */
TwoTilePiece::~TwoTilePiece() {

}

int TwoTilePiece::rotation() {
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