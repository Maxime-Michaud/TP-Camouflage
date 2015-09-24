/* En-t�te du programme
=========================
Programme:		Camouflage
Fichier:		Camouflage.h
Auteur :		Am�lie Frappier et Maxime Michaud-Corriveau
Cr�ation :		22/09/2015
Description :   Classe principale du jeu Camouflage */

#pragma once
#include "MapCamouflage.h"
#include "Piece.h"
#include "ThreeTilePiece.h"
#include "TwoTilePiece.h"

using namespace std;

//TODO: fonction pour calculer le temps pris pour l'algorithme
//et fonction pour mettre en sortie la solution de la map
class Camouflage {
private:
	bool _isSolved;				//d�termine si le tout est solutionn�
	Piece *_gamePieces[6];		//pi�ces du jeu
	MapCamouflage _gameMap;		//tous les �l�ments en rapport avec la map
	float _solveTime;			//temps pris pour r�aliser la solution

public:
	Camouflage();	//constructeur
	~Camouflage();	//destructeur
	
	string getMap();					//appelle une nouvelle map et retourne son nom
	void print(ostream &out) const;		//affiche le r�sultat du jeu
	bool solve(int nbPiece);			//solutionne la map
	void start();						//d�marre le solutionnaire
};

ostream& operator<< (ostream& out, const Camouflage& camo);