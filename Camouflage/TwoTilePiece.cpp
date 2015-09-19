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

	//inidique si la première pièce a été trouvée
	bool foundFirst = false;
	//Trouve les tiles qui sont valide et store leur coordonnées dans deux paires
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
	//Échange les pièces après 4 ou 8 rotations pour essayer toutes les possibilités
	if (_rotation % 4 == 0) {
		swap(
			_tiles[_validTiles[0].first][_validTiles[0].second],
			_tiles[_validTiles[1].first][_validTiles[1].second]
			);
		//Toutes les possibilité ont étés essayées
		if (_rotation == 8)
			_rotation = 0;
	}

	return _rotation;
}