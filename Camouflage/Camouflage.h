/* En-tête du programme
=========================
Programme:		Camouflage
Fichier:		Camouflage.h
Auteur :		Amélie Frappier et Maxime Michaud-Corriveau
Création :		22/09/2015
Description :   Classe principale du jeu Camouflage */

#pragma once
#include "MapCamouflage.h"
#include "Piece.h"
#include "ThreeTilePiece.h"
#include "TwoTilePiece.h"
#include <time.h>

using namespace std;

//TODO: fonction pour calculer le temps pris pour l'algorithme
//et fonction pour mettre en sortie la solution de la map
class Camouflage {
private:
	bool _isSolved;				//détermine si le tout est solutionné
	Piece *_gamePieces[6];		//pièces du jeu
	MapCamouflage _gameMap;		//tous les éléments en rapport avec la map

public:
	Camouflage();	//constructeur
	~Camouflage();	//destructeur
	
	string getMap();					//appelle une nouvelle map et retourne son nom
	void print(ostream &out) const;		//affiche le résultat du jeu
	bool solve(int nbPiece);			//solutionne la map
	void start();						//démarre le solutionnaire
	void showTime(ostream& out, struct tm *timeDebut, struct tm *timeFin);	//affiche le temps d'exécution

};

ostream& operator<< (ostream& out, const Camouflage& camo);