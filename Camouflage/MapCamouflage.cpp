/* En-tête du programme
=========================
Programme:		Camouflage
Fichier:		MapCamouflage.cpp
Auteur :		Amélie Frappier et Maxime Michaud-Corriveau
Création :		19/09/2015
Description :   Classe dérivée de map pour le jeu de camouflage aux pôles. Contient certains
				membres spécifique au jeu.*/

#include "MapCamouflage.h"

//Initialise avec un nullptr
MapCamouflage::MapCamouflage()
{
	_pieces = nullptr;
}

//Initialise la map a partir du fichier, puis alloue la mémoire pour _pieces
MapCamouflage::MapCamouflage(const string & filepath)
	: Map(filepath)
{
	//Alloue la mémoire
	_pieces = new char **[_lignes];

	for (int i = 0; i < _lignes; i++)
	{
		_pieces[i] = new char *[_colonnes];
		for (int j = 0; j < _colonnes; j++)
		{
			_pieces[i][j] = new char[2];
			_pieces[i][j][0] = _pieces[i][j][1] = '\0';
		}
	}
}

//Copie la map et les pieces d'une autre MapCamouflage
MapCamouflage::MapCamouflage(const MapCamouflage & other)
	:Map(other)
{
	//Alloue la mémoire et assigne les valeurs de other
	_pieces = new char **[_lignes];

	for (int i = 0; i < _lignes; i++)
	{
		_pieces[i] = new char *[_colonnes];
		for (int j = 0; j < _colonnes; j++)
		{
			_pieces[i][j] = new char[2];
			_pieces[i][j][0] = other._pieces[i][j][0];
			_pieces[i][j][1] = other._pieces[i][j][1];
		}
	}
}

//Désalloue la mémoire de _pieces
MapCamouflage::~MapCamouflage()
{	
	for (int i = 0; i < _lignes; i++)
	{
		for (int j = 0; j < _colonnes; j++)
		{
			delete[] _pieces[i][j];
		}
		delete[] _pieces[i];
	}
	delete[] _pieces;

	_pieces = nullptr;
}

//Vérifie si il est possible de placer la pièce a la position x, y
bool MapCamouflage::tryPieceAt(const Piece & piece, int x, int y) const
{
	//Si il y a déjà une pièce aux positions de la piece, retourne false
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			//Vérifie si il y a une colision entre deux pièces
			if (piece.getTile(i, j).getValid() && _pieces[x + i][y + j][0] != '\0')
				return false;
				
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2;j++)
}