#include "Map.h"
//Initialise a des valeurs sécuritaires
Map::Map()
{
	_lignes = _colonnes = 0;
	_map = nullptr;
}

//Copie les valeurs de l'autre map dans la nouvelle. Permet la copie d'une map vide.
Map::Map(const Map & other)
{
	_lignes = other._lignes;
	_colonnes = other._colonnes;

	_map = new char*[_lignes];

	for (int i = 0; i < _lignes; i++)
	{
		_map[i] = new char[_colonnes];
		for (int j = 0; j < _colonnes; j++)
			_map[i][j] = other._map[i][j];
	}
}

//Initialise la valeur de la map a partir d'un fichier texte
Map::Map(const string & filepath)
{
	_map = nullptr;
	init(filepath);
}

//Désalloue toute la mémoire de la map.
Map::~Map()
{
	//Évite de travailler pour rien si le pointeur est null
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
	string lignes = "", colonnes = "";
	char c = file.get();
	while (c >= '0' && c <= '9')
	{
		lignes += c;
		c = file.get();
	}

	//Skip les charactères inutiles (espaces, virgules, etc.)
	while (c < '0' || c > '9')
		c = file.get();

	while (c >= '0' && c <= '9')
	{
		colonnes += c;
		c = file.get();
	}

	_lignes = atoi(lignes.c_str());
	_colonnes = atoi(colonnes.c_str());

	//Vérifie les erreurs
	if (!(_lignes && _colonnes))
		throw runtime_error("Erreur lors de la lecture de " + filepath + ". \n" +
			"Le nombre de colonnes ou de lignes est invalide.\n" +
			"Les deux valeurs devraient êtres numérique supérieures à 0.\n" +
			"Le nombre de ligne est de: " + to_string(_lignes) + ".\n" +
			"Le nombre de colonnes est de: " + to_string(_colonnes) + ".\n");


	//Si la map a déjà de la mémoire allouée, delete tout.
	if (_map)
	{
		for (int i = 0; i < _lignes; i++)
			delete[] _map[i];

		delete[] _map;
	}

	//Crée la nouvelle map
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

	//Si les dimensions du tableau dans le fichier ne matchent pas celles données en haut
	if (fileContent.length() != _lignes * _colonnes)
	{
		stringstream err;
		err << "Les dimensions spécifiées ne correspondent pas à la grosseur de la grille.\n" <<
			"La grille fait: " << to_string(fileContent.length()) << " éléments.\n" <<
			"Les dimensions spécifiées au début du fichier sont: " << to_string(_lignes) << " par " << to_string(_colonnes) <<
			"Ce qui correspond à " << to_string(_lignes * _colonnes) << " éléments.";
		throw runtime_error(err.str());

	}
		
	for (int i = 0; i < _lignes; i++)
		for (int j = 0; j < _colonnes; j++)
			_map[i][j] = fileContent[i + j * _colonnes];
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

ostream& operator<<(ostream& out, Map map)
{
	map.print(out);
	return out;
}

char Map::getValue(int x, int y) const
{
	if (!(_map && _lignes && _colonnes))
		throw exception("Tentative d'acces a une map non initialisée");
	if (x >= _lignes || y >= _colonnes)
		throw exception("Nombre de ligne ou de colonne trop grand");


	return _map[x][y];
}

void Map::setValue(int x, int y, char val)
{
	if (!(_map && _lignes && _colonnes))
		throw exception("Tentative d'acces a une map non initialisée");
	if (x >= _lignes || y >= _colonnes)
		throw exception("Nombre de ligne ou de colonne trop grand");

	_map[x][y] = val;
}

int Map::getSizeX() const
{
	return _lignes;
}

int Map::getSizeY() const
{
	return _colonnes;
}

pair<int, int> Map::getSize() const
{
	return pair<int, int>(_lignes, _colonnes);
}

