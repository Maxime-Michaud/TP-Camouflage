/* En-t�te du programme
=========================
Programme:		Camouflage
Fichier:		MapCamouflage.h
Auteur :		Am�lie Frappier et Maxime Michaud-Corriveau
Cr�ation :		19/09/2015
Description :   Classe d�riv�e de map pour le jeu de camouflage aux p�les. Contient certains 
				membres sp�cifique au jeu.*/

#pragma once
#include "Map.h"
#include "Piece.h"

class MapCamouflage :public Map
{
	char *** _pieces;	
public:
	MapCamouflage();										//Ne fais pas d'initialisation
	MapCamouflage(const string & filepath);					//Initialise la map de base et alloue la m�moire de _pieces
	MapCamouflage(const MapCamouflage & other);				//Copie une instance de mapcamouflage dans une nouvelle
	virtual	~MapCamouflage();

	bool tryPieceAt(const Piece & piece, int x, int y)const;//Essaye de placer une pi�cea la position x, y et retourne 
															//si c'est une position correcte ou non
	void placeNewPiece(const Piece & piece, int x, int y);	//Place une pi�cea la position x, y
	bool isBoardFull()const;								//Retourne si la grille est pleine
	bool isSolved()const;									//Retourne si la grille est r�solue
};

