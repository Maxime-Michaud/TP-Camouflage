/* En-t�te du programme
=========================
Programme:		Camouflage
Fichier:		mainCamouflage.cpp
Auteur :		Am�lie Frappier et Maxime Michaud-Corriveau
Cr�ation :		04/09/2015
Modification:	06/09/2015
Description :   */

/* TODO: am�liorations � apporter au programme
=================================================
* 
*/


/* Directives au pr�-processeur
================================= */
#include "Piece.h"
#include "TwoTilePiece.h"
#include "ThreeTilePiece.h"

//Raccourci pour les laches 
#define PAUSE system("pause>NUL")

using namespace std;


/* M�thode principale
====================== */
int main() {

	Piece *pieces[2];
	pieces[0] = new ThreeTilePiece('1', '1', '2', NULL, '3');
	pieces[1] = new TwoTilePiece('A', 'a', 'b',NULL, NULL);


	for (auto piece : pieces) {
		cout << "\nLa pi�ce " << piece->getName() << " : ";
		piece->print(cout);

		while (piece->rotation()) {
			cout << endl << "Rotation #" << piece->getRotation() << endl;
			cout << *piece;
		}
		cout << "\n\n\n";

	}
	
	PAUSE;

	/*Changer le for pour un foreach, donc pas besoin de le changer chaque fois qu'on change 
	  le nombre pi�ces*/
	for (auto piece: pieces) {
		delete piece;
	}

	return 0;

}