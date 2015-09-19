/* En-tête du programme
=========================
Programme:		Camouflage
Fichier:		mainCamouflage.cpp
Auteur :		Amélie Frappier et Maxime Michaud-Corriveau
Création :		04/09/2015
Modification:	06/09/2015
Description :   */

/* TODO: améliorations à apporter au programme
=================================================
* 
*/


/* Directives au pré-processeur
================================= */
#include "Piece.h"
#include "TwoTilePiece.h"
#include "ThreeTilePiece.h"

//Raccourci pour les laches 
#define PAUSE system("pause>NUL")

using namespace std;


/* Méthode principale
====================== */
int main() {

	Piece *pieces[2];
	pieces[0] = new ThreeTilePiece('1', '1', '2', NULL, '3');
	pieces[1] = new TwoTilePiece('A', 'a', 'b',NULL, NULL);


	for (auto piece : pieces) {
		cout << "\nLa pièce " << piece->getName() << " : ";
		piece->print(cout);

		while (piece->rotation()) {
			cout << endl << "Rotation #" << piece->getRotation() << endl;
			cout << *piece;
		}
		cout << "\n\n\n";

	}
	
	PAUSE;

	/*Changer le for pour un foreach, donc pas besoin de le changer chaque fois qu'on change 
	  le nombre pièces*/
	for (auto piece: pieces) {
		delete piece;
	}

	return 0;

}