/* En-tête du programme
=========================
Programme: Camouflage
Fichier: ThreeTilePiece.h
Auteur : Amélie Frappier et Maxime Michaud-Corriveau
Date création : 04/09/2015
Date modification:
Description :   */

/* Directives au pré-processeur
================================= */
#pragma once
#include <iostream>
#include "Piece.h"

using namespace std;

/* Définition de la classe
=========================== */
class ThreeTilePiece : public Piece {

public:

	ThreeTilePiece();												//constructeur par défaut
	ThreeTilePiece(char name, char a1, char a2, char b1, char b2);	//constructeur avec paramètres
	~ThreeTilePiece();												//destructeur

	virtual int rotation();											//effectue une rotation de la pièce

};