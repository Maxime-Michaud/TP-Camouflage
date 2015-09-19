/* En-t�te du programme
=========================
Programme: Camouflage
Fichier: ThreeTilePiece.h
Auteur : Am�lie Frappier et Maxime Michaud-Corriveau
Date cr�ation : 04/09/2015
Date modification:
Description :   */

/* Directives au pr�-processeur
================================= */
#pragma once
#include <iostream>
#include "Piece.h"

using namespace std;

/* D�finition de la classe
=========================== */
class ThreeTilePiece : public Piece {

public:

	ThreeTilePiece();												//constructeur par d�faut
	ThreeTilePiece(char name, char a1, char a2, char b1, char b2);	//constructeur avec param�tres
	~ThreeTilePiece();												//destructeur

	virtual int rotation();											//effectue une rotation de la pi�ce

};