/* En-tête du programme
=========================
Programme:		Camouflage
Fichier:		MapCamouflage.h
Auteur :		Amélie Frappier et Maxime Michaud-Corriveau
Création :		19/09/2015
Modification :	22/09/2015
Description :   Classe dérivée de map pour le jeu de camouflage aux pôles. Contient certains 
				membres spécifique au jeu.*/

#pragma once
#include "Map.h"
#include "Piece.h"

class MapCamouflage :public Map
{
	char *** _solution;

public:
	MapCamouflage();										//Ne fais pas d'initialisation
	MapCamouflage(const string & filepath);					//Initialise la map de base et alloue la mémoire de _solution
	MapCamouflage(const MapCamouflage & other);				//Copie une instance de mapcamouflage dans une nouvelle
	virtual	~MapCamouflage();

	void initSolution();									//Initialise la solution de mapCamouflage
	bool tryPieceAt(const Piece & piece, int x, int y)const;//Essaye de placer une piècea la position x, y et retourne 
															//si c'est une position correcte ou non
	void placeNewPiece(const Piece & piece, int x, int y);	//Place une pièce a la position x, y
	void removePiece(const Piece & piece, int x, int y);	//Retire la pièce à la position x, y
	bool isBoardFull()const;								//Retourne si la grille est pleine
	void print(ostream &out) const;							//Affiche la solution
};

ostream& operator<< (ostream& out, const MapCamouflage& mapCamo);	//surcharge de cout/print