/* En-t�te du programme
=========================
Programme:		Camouflage
Fichier:		MapCamouflage.cpp
Auteur :		Am�lie Frappier et Maxime Michaud-Corriveau
Cr�ation :		19/09/2015
Modification :	23/09/2015
Description :   Classe d�riv�e de map pour le jeu de camouflage aux p�les. Contient certains
				membres sp�cifique au jeu.*/

#include "MapCamouflage.h"

//Initialise avec un nullptr
MapCamouflage::MapCamouflage()
{
	_solution = nullptr;
}

//Initialise la map a partir du fichier, puis alloue la m�moire pour _solution
MapCamouflage::MapCamouflage(const string & filepath)
	: Map(filepath)
{
	//Alloue la m�moire
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
	//Alloue la m�moire et assigne les valeurs de other
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

//D�salloue la m�moire de _solution
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

	//Alloue la m�moire
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

//V�rifie si il est possible de placer la pi�ce a la position x, y
bool MapCamouflage::tryPieceAt(const Piece & piece, int x, int y) const
{

	//Si l'une des tuiles de la pi�ce tombe out of bounds, retourne faux
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (x + i >= _lignes || y + j >= _colonnes) {
				return false;
			}
		}
	}

	//Si il y a d�j� une pi�ce aux positions de la piece, retourne false
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			//V�rifie si la pi�ce ne rentre pas en collision avec une autre
			if (piece.getTile(i, j).getValid() && _solution[x + i][y + j][0] != '\0') {
				return false;
			}
		}	
	}
		
	
	//V�rifie si la pi�ce correspond � l'endroit donn� dans la map
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (piece.getTile(i, j).getValid()) {
				//Compare l'�l�ment sur la map avec la pi�ce
				//Retourne faux si la pi�ce ne concorde pas avec la map
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

//Ins�re la pi�ce dans le tableau de solution _solution
//� la position donn�e
void MapCamouflage::placeNewPiece(const Piece & piece, int x, int y) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			_solution[x + i][y + j][0] = piece.getName();
			_solution[x + i][y + j][1] = piece.getTile(i, j).getValue();
		}
	}
}

//Retire la pi�ce donn�e dans le tableau Solution
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

//V�rifie si la map est remplie
bool MapCamouflage::isBoardFull() const {
	for (int i = 0; i < _lignes; i++) {
		for (int j = 0; j < _colonnes; j++) {
			if (_solution[i][j][0] == '\0') {
				return false;
			}
		}
	}
}

//Affiche la solution � l'�cran
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