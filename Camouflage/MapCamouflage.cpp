/* En-tête du programme
=========================
Programme:		Camouflage
Fichier:		MapCamouflage.cpp
Auteur :		Amélie Frappier et Maxime Michaud-Corriveau
Création :		19/09/2015
Modification :	23/09/2015
Description :   Classe dérivée de map pour le jeu de camouflage aux pôles. Contient certains
				membres spécifique au jeu.*/

#include "MapCamouflage.h"

//Initialise avec un nullptr
MapCamouflage::MapCamouflage()
{
	_solution = nullptr;
}

//Initialise la map a partir du fichier, puis alloue la mémoire pour _solution
MapCamouflage::MapCamouflage(const string & filepath)
	: Map(filepath)
{
	//Alloue la mémoire
	_solution = new char **[_lignes];

	for (int i = 0; i < _lignes; i++)
	{
		_solution[i] = new char *[_colonnes];
		for (int j = 0; j < _colonnes; j++)
		{
			_solution[i][j] = new char[2];
			_solution[i][j][0] = _solution[i][j][1] = '\0';
		}
	}
}

//Copie la map et les pieces d'une autre MapCamouflage
MapCamouflage::MapCamouflage(const MapCamouflage & other)
	:Map(other)
{
	//Alloue la mémoire et assigne les valeurs de other
	_solution = new char **[_lignes];

	for (int i = 0; i < _lignes; i++)
	{
		_solution[i] = new char *[_colonnes];
		for (int j = 0; j < _colonnes; j++)
		{
			_solution[i][j] = new char[2];
			_solution[i][j][0] = other._solution[i][j][0];
			_solution[i][j][1] = other._solution[i][j][1];
		}
	}
}

//Désalloue la mémoire de _solution
MapCamouflage::~MapCamouflage()
{	
	for (int i = 0; i < _lignes; i++)
	{
		for (int j = 0; j < _colonnes; j++)
		{
			delete[] _solution[i][j];
		}
		delete[] _solution[i];
	}
	delete[] _solution;

	_solution = nullptr;
}

void MapCamouflage::initSolution() {

	//Alloue la mémoire
	_solution = new char **[_lignes];

	for (int i = 0; i < _lignes; i++)
	{
		_solution[i] = new char *[_colonnes];
		for (int j = 0; j < _colonnes; j++)
		{
			_solution[i][j] = new char[2];
			_solution[i][j][0] = _solution[i][j][1] = '\0';
		}
	}

}

//Vérifie si il est possible de placer la pièce a la position x, y
bool MapCamouflage::tryPieceAt(const Piece & piece, int x, int y) const
{

	//Si l'une des tuiles de la pièce tombe out of bounds, retourne faux
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (x + i >= _lignes || y + j >= _colonnes) {
				return false;
			}
		}
	}

	//Si il y a déjà une pièce aux positions de la piece, retourne false
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			//Vérifie si la pièce ne rentre pas en collision avec une autre
			if (piece.getTile(i, j).getValid() && _solution[x + i][y + j][0] != '\0') {
				return false;
			}
		}	
	}
		
	
	//Vérifie si la pièce correspond à l'endroit donné dans la map
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (piece.getTile(i, j).getValid()) {
				//Compare l'élément sur la map avec la pièce
				//Retourne faux si la pièce ne concorde pas avec la map
				switch (_map[x][y]) {
				case 'E':
					if (piece.getTile(i,j).getValue() != 'P') {
						return false;
					}
					break;
				case 'B':
					if (piece.getTile(i, j).getValue() != 'O') {
						return false;
					}
					break;
				case 'I':
					if (piece.getTile(i, j).getValue() != ' ') {
						return false;
					}
					break;
				}
			}
		}
	}

	//Si toutes les positions concordent, retourner vrai
	return true;
}

//Insère la pièce dans le tableau de solution _solution
//à la position donnée
void MapCamouflage::placeNewPiece(const Piece & piece, int x, int y) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			_solution[x + i][y + j][0] = piece.getName();
			_solution[x + i][y + j][1] = piece.getTile(i, j).getValue();
		}
	}
}

//Retire la pièce donnée dans le tableau Solution
void MapCamouflage::removePiece(const Piece & piece, int x, int y) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (_solution[x + i][y + j][0] == piece.getName()) {
				_solution[x + i][y + j][0] = '\0';
				_solution[x + i][y + j][1] = '\0';
			}
		}
	}
}

//Vérifie si la map est remplie
bool MapCamouflage::isBoardFull() const {
	for (int i = 0; i < _lignes; i++) {
		for (int j = 0; j < _colonnes; j++) {
			if (_solution[i][j][0] == '\0') {
				return false;
			}
		}
	}
}

//Affiche la solution à l'écran
void MapCamouflage::print(ostream& out) const {
	for (int i = 0; i < _lignes; i++) {
		out << endl;
		for (int j = 0; j < _colonnes; j++) {
			out << _solution[i][j][0] << _solution[i][j][1] << " ";
		}
	}
}

ostream& operator<< (ostream& out, const MapCamouflage & mapCamo) {
	mapCamo.print(out);
	return out;
}