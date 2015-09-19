/* En-tête du programme
=========================
Programme: Camouflage
Fichier: TwoTilePiece.h
Auteur : Amélie Frappier et Maxime Michaud-Corriveau
Date création : 04/09/2015
Date modification:
Description :   */

/* Directives au pré-processeur
================================= */
#pragma once
#include <tuple>
#include <iostream>
#include "Piece.h"

using namespace std;

/* Définition de la classe
=========================== */
class TwoTilePiece : public Piece {
protected:
	pair<int, int> _validTiles[2];
public:

	TwoTilePiece();													//constructeur par défaut
	TwoTilePiece(char name, char a1, char a2, char b1, char b2);	//constructeur avec paramètres
	~TwoTilePiece();												//destructeur

	virtual int rotation();											//effectue une rotation de la pièce

};