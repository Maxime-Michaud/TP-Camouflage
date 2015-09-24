/* En-t�te du programme
=========================
Programme:		Camouflage
Fichier:		Camouflage.cpp
Auteur :		Am�lie Frappier et Maxime Michaud-Corriveau
Cr�ation :		22/09/2015
Modification:	23/09/2015
Description :   */

#include "Camouflage.h"

//Constructeur
Camouflage::Camouflage() {

	//Cr�ation des pi�ces
	_gamePieces[0] = new ThreeTilePiece('U', ' ', 'P', 'O', '\0');
	_gamePieces[1] = new ThreeTilePiece('V', 'P', ' ', 'O', '\0');
	_gamePieces[2] = new ThreeTilePiece('W', ' ', 'O', 'P', '\0');
	_gamePieces[3] = new TwoTilePiece('X', 'P', 'P', '\0', '\0');
	_gamePieces[4] = new TwoTilePiece('Y', 'P', 'O', '\0', '\0');
	_gamePieces[5] = new ThreeTilePiece('Z', ' ', '\0', 'O', ' ');

	_solveTime = 0;
	_isSolved = false;

}

//Destructeur
Camouflage::~Camouflage() {

	//Suppression des pi�ces
	for (int i = 0; i < 6; i++) {
		delete _gamePieces[i];
	}
	
	_solveTime = 0;
	_isSolved = false;
}

//Appelle une nouvelle map
string Camouflage::getMap() {
	
	string mapName;
	string mapFilePath;

	//saisit et valide le nom de la map et le filepath
	mapName = saisirStringNonVide("Saisissez le nom de la map � solutionner : ");
	mapFilePath = mapName;
	mapFilePath.insert(0, "./Maps/map");
	mapFilePath.append(".txt");

	//Initialise la map et la solution
	_gameMap.init(mapFilePath);
	_gameMap.initSolution();

	//_gameMap = MapCamouflage(mapFilePath);

	//TODO: Refaire la loop tant que map n'est pas vide.
	/*do {
		saisirStringNonVide("Saisissez le nom de la map � solutionner : ");
		_gameMap.init(mapName);	
	} while ();*/

	return mapName;
}

//D�marre le solutionnaire du jeu en soi
void Camouflage::start() {

	ofstream output;
	string mapName;

	cout << "Bienvenue au solutionnaire du jeu Camouflage" << endl
		<< "(parce qu'on est fondamentalement l�ches)" << endl;

	//Initialise la map
	mapName = getMap();
	mapName.insert(0, "solution");
	mapName.append(".txt");
	output.open(mapName);

	//Solutionne la map choisie � partir de la premi�re pi�ce
	_isSolved = solve(0);

	//Affiche le r�sultat du jeu en console et en sortie
	print(cout);

	print(output);



	output.close();

}

//Solutionne la map
bool Camouflage::solve(int nbPiece) {

	//Si le nombre de pi�ces est �gal � 6, retourner vrai, car
	//toutes les pi�ces sont plac�es
	if (nbPiece == 6)
		return true;

	//pour toutes les cases de la map, chaque position de la map
	//ainsi que chaque rotation de la pi�ce
	for (int i = 0; i < _gameMap.getSizeX() - 1; i++) {
		for (int j = 0; j < _gameMap.getSizeY() - 1; j++) {
			for (int r = 0; r < 4; r++) {
				if (_gameMap.tryPieceAt(*(_gamePieces[nbPiece]), i, j)) {
					_gameMap.placeNewPiece(*(_gamePieces[nbPiece]), i, j);
					bool isSolved = solve(nbPiece + 1);
					if (!isSolved) {
						_gameMap.removePiece(*(_gamePieces[nbPiece]),i,j);
					}
					else {
						return true;
					}
				}
				_gamePieces[nbPiece]->rotation();
			}
		}
	}

	//Si la map ne peut �tre solutionn�e, retourner faux
	return false;
}

void Camouflage::print(ostream& out) const {
	if (_isSolved) {
		out << "C'est fait! La solution a �t� r�alis�e en : " << _solveTime << " secondes." <<  endl; 
		out << _gameMap;
	}
	else {
		out << "Il est impossible de solutionner cette carte de jeu.";
	}
}

ostream& operator<< (ostream& out, const Camouflage& camo){
	camo.print(out);
	return out;
}