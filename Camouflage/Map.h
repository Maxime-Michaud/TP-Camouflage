/* En-t�te du programme
=========================
Programme:		Camouflage
Fichier:		Map.h
Auteur :		Am�lie Frappier et Maxime Michaud-Corriveau
Cr�ation :		19/09/2015
Description :   Classe Map g�n�rique qui permet cr�er une grille dynamique de characteres. 
				La map est remplie a partir d'un fichier texte*/

#pragma once
#include <string>
#include <ostream>
#include <exception>
#include "saisieSecurisee.h"
#include <fstream>

using namespace std;

class Map
{
protected:
	char ** _map;
	int _lignes;
	int _colonnes;

public:
	Map();											//Constructeur vide. N'initialise rien.
	Map(Map & other);								//Constructeur de copie. Copie les valeurs de la map
	Map(const string & filepath);					//Construit et initialise la map
	virtual ~Map();									//Efface les pointeurs en m�moire dynamique

	void init(const string & filepath);				//Charge la map a partir d'un fichier
	virtual void print(ostream & sortie) const;		//Affiche la map dans un flux de sortie

	char getValue(int x, int y) const;				//Donne la valeur de la map a la position x, y
	void setValue(int x, int y, char val);	//Set la valeur de la map a la position x, y
};

//Initialise a des valeurs s�curitaires
Map::Map()
{
	_lignes = _colonnes = 0;
	_map = nullptr;
}

//Copie les valeurs de l'autre map dans la nouvelle. Permet la copie d'une map vide.
Map::Map(Map & other)
{
	_lignes = other._lignes;
	_colonnes = other._colonnes;

	_map = new T*[_lignes];

	for (int i = 0; i < _lignes; i++)
	{
		_map[i] = new T[_colonnes];
		for (int j = 0; j < _colonnes; j++)
			_map[i][j] = other._map[i][j];
	}
}

//Initialise la valeur de la map a partir d'un fichier texte
Map::Map(const string & filepath)
{
	init(filepath);
}

//D�salloue toute la m�moire de la map.
Map::~Map()
{
	//�vite de travailler pour rien si le pointeur est null
	if (!_map)
		return;

	for (int i = 0; i < _lignes; i++)
		delete[] _map[i];

	delete[] _map;

	_map = nullptr;
}

//Construit la map a partir d'un fichier texte
inline void Map::init(const string & filepath)
{
	ifstream file;

	if (!ouvrirFichier(file, filepath))
		throw invalid_argument("Le fichier " + filepath + " est absent de votre ordinateur!");

	//Set la valeur de lignes
	string lignes = "" , colonnes = "";
	char c = file.get();
	while (c >= '0' && c <= '9')
	{
		lignes += c;
		c = file.get();
	}

	//Skip les charact�res inutiles (espaces, virgules, etc.)
	while (c < '0' || c > '9')
		c = file.get();

	while (c >= '0' && c <= '9')
	{
		colonnes += c;
		c = file.get();
	}

	_lignes = atoi(lignes);
	_colonnes = atoi(colonnes);

	//V�rifie les erreurs
	if (!(_lignes && _colonnes))
		throw runtime_error("Erreur lors de la lecture de " + filepath + ". \n" +
							"Le nombre de colonnes ou de lignes est invalide.\n" +
							"Les deux valeurs devraient �tres num�rique sup�rieures � 0.\n" +
							"Le nombre de ligne est de: " + to_string(_lignes) + ".\n" +
							"Le nombre de colonnes est de: " + to_string(_colonnes) + ".\n");


	//Si la map a d�j� de la m�moire allou�e, delete tout.
	if (_map)
	{
		for (int i = 0; i < _lignes; i++)
			delete[] _map[i];

		delete[] _map;
	}

	//Cr�e la nouvelle map
	_map = new char *[_lignes];
	for (int i = 0; i < _lignes; i++)
		_map[i] = new char[_colonnes];

	//Lis le fichier jusqu'a la fin
	string fileContent = "";
	while (file.peek() != EOF)
	{
		string line;
		file >> line;
		fileContent += line;
	}

	if (fileContent.length() != _lignes * _colonnes)
		throw runtime_error("Les dimensions sp�cifi�es ne correspondent pas � la grosseur de la grille.\n" +
							"La grille fait: " + to_string(fileContent.length()) + " �l�ments.\n" +
							"Les dimensions sp�cifi�es au d�but du fichier sont: " + to_string(_lignes) + " par " + to_string(_colonnes) +
							"Ce qui correspond � " + to_string(_lignes * _colonnes) + " �l�ments.");

	for (int i = 0; i < _lignes; i++)
		for (int j = 0; j < _colonnes; j++)
			_map[i][j] = fileContent.c_str[i + j * _colonnes];
}

inline void Map::print(ostream & sortie) const
{
	for (int i = 0; i < _colonnes; i++)
	{
		for (int j = 0; j < _lignes; j++)
			sortie << _map[i][j];
		sortie << endl;
	}

}

inline char Map::getValue(int x, int y) const
{
	if (!(_map && _lignes && _colonnes))
		throw exception("Tentative d'acces a une map non initialis�e");
	if (x >= _lignes || y >= _colonnes)
		throw exception("Nombre de ligne ou de colonne trop grand");


	return _map[x][y];
}

inline void Map::setValue(int x, int y, char val) 
{
	if (!(_map && _lignes && _colonnes))
		throw exception("Tentative d'acces a une map non initialis�e");
	if (x >= _lignes || y >= _colonnes)
		throw exception("Nombre de ligne ou de colonne trop grand");

	_map[x][y] = val;
}

