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
#include "Map.h"

//Raccourci pour les laches 
#define PAUSE system("pause>NUL")

using namespace std;

#define TESTING_

#ifndef TESTING_

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

	/*Changer le for pour un foreach, donc pas besoin de le changer chaque fois qu'on change le nombre pièces*/
	for (auto piece: pieces) {
		delete piece;
	}

	return 0;

}

#else

//Fonctions de test 
void testMapVide()
{
	Map vide;
	cout << "Affichage d'une map vide: \n" << vide;

	try {
		cout << "vide.getValue(0, 0);\n";
		cout << vide.getValue(0, 0);
		cout << "Getvalue réussi";
	}
	catch (const exception & e)
	{
		cout << e.what() << endl << endl;
	}

	try {
		cout << "vide.setValue(0, 0, 'a');\n";
		vide.setValue(0, 0, 'a');
		cout << "Setvalue réussi";
	}
	catch (const exception & e)
	{
		cout << e.what() << endl << endl;
	}

	cout << "vide.getSizeX(): " << vide.getSizeX()
		<< "\nvide.getSizeY(): " << vide.getSizeY()
		<< "\nvide.getSize(): " << string("(" + to_string(vide.getSize().first) + ", " + to_string(vide.getSize().second) + ")") << endl << endl << endl;
}

void testMapExp25()
{

	//Constructeur qui appel init()
	Map exp25("./Maps/mapExpert25.txt");
	cout << "Affichage d'une map chargée a partir d'un fichier texte: \n" << exp25;

	try {
		cout << "exp25.getValue(0, 0); ";
		cout << exp25.getValue(0, 0);
		cout << "\nGetvalue réussi\n";
	}
	catch (const exception & e)
	{
		cout << e.what() << endl << endl;
	}

	try {
		cout << "exp25.setValue(0, 0, 'a');\n";
		exp25.setValue(0, 0, 'a');
		cout << "Setvalue réussi\n";
		cout << "\n" << "Nouvelle map\n" << exp25 << '\n';
	}
	catch (const exception & e)
	{
		cout << e.what() << endl << endl;
	}

	cout << "exp25.getSizeX(): " << exp25.getSizeX()
		<< "\nexp25.getSizeY(): " << exp25.getSizeY()
		<< "\nexp25.getSize(): " << string("(" + to_string(exp25.getSize().first) + ", " + to_string(exp25.getSize().second) + ")") << endl << endl << endl;

}

void testMapDivers()
{
	try {
		cout << "Initialisation avec un fichier invalide\n";
		Map fail("..\~./Obviously`very !WRONG! filepath..notatxtfile");
	}
	catch (const exception & e)
	{
		cout << e.what() << endl << endl;
	}
}
//Fonction main de test
void main()
{
	//Tests sur la classe Map de base
	//=================================================================================================================
	testMapVide();
	testMapExp25();
	testMapDivers();

	system("pause>NUL");


}

#endif