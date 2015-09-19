/* En-tête du programme
=========================
Programme: Camouflage
Fichier: Piece.cpp
Auteur : Amélie Frappier et Maxime Michaud-Corriveau
Date création : 04/09/2015
Date modification:
Description :   */

/* Directives au pré-processeur
================================= */
#include "Piece.h"

using namespace std;
/* Destructeur
==============*/

Piece::~Piece() {

}

/* Initialisation 
=================== */
void Piece::init(char name, char a1, char a2, char b1, char b2) {
	_name = name;
	_tiles[0][0].setValue(a1);
	_tiles[0][1].setValue(a2);
	_tiles[1][0].setValue(b1);
	_tiles[1][1].setValue(b2);
	_rotation = 0;
}

/* Getters 
============ */
char Piece::getName() const {
	return _name;
}

int Piece::getRotation() const {
	return _rotation;
}

Tile Piece::getTile(int line, int column) const {
	return _tiles[line][column];
}

/* Affiche la pièce 
==================== */
void Piece::print(ostream &out) const {
	for (int i = 0; i < 2; i++) {
		out << endl;
		for (int j = 0; j < 2; j++) {
			if (_tiles[i][j].getValid()) {
				cout << _tiles[i][j].getValue();
			} 
			else {
				cout << " ";
			}
		}
	}
}

//Implémentation de base de la rotation pour une rotation sur la grille
int Piece::rotation() {
	_rotation++;
	Tile tmp;

	tmp = _tiles[0][0];
	_tiles[0][0] = _tiles[0][1];
	_tiles[0][1] = _tiles[1][1];
	_tiles[1][1] = _tiles[1][0];
	_tiles[1][0] = tmp;


	return _rotation;
}

ostream& operator<< (ostream & out, const Piece & piece)
{
	piece.print(out);
	return out;
}