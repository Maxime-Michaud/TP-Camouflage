/* En-t�te du programme
=========================
Programme: Camouflage
Fichier: TwoTilePiece.h
Auteur : Am�lie Frappier et Maxime Michaud-Corriveau
Date cr�ation : 04/09/2015
Date modification:
Description :   */

/* Directives au pr�-processeur
================================= */
#pragma once
#include <tuple>
#include <iostream>
#include "Piece.h"

using namespace std;

/* D�finition de la classe
=========================== */
class TwoTilePiece : public Piece {
protected:
	pair<int, int> _validTiles[2];
public:

	TwoTilePiece();													//constructeur par d�faut
	TwoTilePiece(char name, char a1, char a2, char b1, char b2);	//constructeur avec param�tres
	~TwoTilePiece();												//destructeur

	virtual int rotation();											//effectue une rotation de la pi�ce

};