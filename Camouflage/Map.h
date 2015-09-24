/* En-tête du programme
=========================
Programme:		Camouflage
Fichier:		Map.h
Auteur :		Amélie Frappier et Maxime Michaud-Corriveau
Création :		19/09/2015
Description :   Classe Map générique qui permet créer une grille dynamique de characteres. 
				La map est remplie a partir d'un fichier texte*/

#pragma once
#include <string>
#include <ostream>
#include <exception>
#include "saisieSecurisee.h"
#include <fstream>
#include <sstream>
#include <tuple>

using namespace std;

class Map
{
protected:
	char ** _map;
	int _lignes;
	int _colonnes;

public:
	Map();											//Constructeur vide. N'initialise rien.
	Map(const Map & other);							//Constructeur de copie. Copie les valeurs de la map
	Map(const string & filepath);					//Construit et initialise la map
	virtual ~Map();									//Efface les pointeurs en mémoire dynamique

	void init(const string & filepath);				//Charge la map a partir d'un fichier
	virtual void print(ostream & sortie) const;		//Affiche la map dans un flux de sortie



	char getValue(int x, int y) const;				//Donne la valeur de la map a la position x, y
	void setValue(int x, int y, char val);			//Set la valeur de la map a la position x, y
	int getSizeX() const;							//Donne la largeur de _map. 0 si map n'est pas initialisée
	int getSizeY() const;							//Donne la hauteur de _map. 0 si map n'est pas initialisée
	pair<int, int> getSize() const;					//Donne les dimensions de _map. 0,0 si map n'est pas initialisée
};

ostream& operator<<(ostream& out, Map map);