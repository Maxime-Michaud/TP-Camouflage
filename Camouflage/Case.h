/* En-t�te du programme
=========================
Programme: Camouflage
Fichier: Case.h
Auteur : Am�lie Frappier et Maxime Michaud-Corriveau
Date cr�ation : 04/09/2015
Date modification:
Description :   */

/* Directives au pr�-processeur
================================= */
#pragma once
#include <iostream>

using namespace std;

/* D�finition de la classe
=========================== */
class Case {

private:
	char _value;		//valeur contenue dans la pi�ce
	bool _valid;		//indique si la case contient quelque chose ou est vide

public:
	
	Case();					//constructeur sans param�tres
	~Case();				//destructeur
	
	char getValue() const;			//getter de la valeur
	bool getValid() const;			//getter de la valeur de validation

	void setValue(char value);		//setter de la valeur
	void setValid(bool valid);		//setter de la valeur de validation
};