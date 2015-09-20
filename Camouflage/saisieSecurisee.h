/* En-t�te du programme
=======================
Programme:        saisieSecurisee.h
Auteur:           Maxime Michaud-Corriveau
Date cr�ation:    16/02/2015
Description:      L'objectif de ce fichier d'en-t�te
				  est de regrouper les fonctions
				  de saisie, de validation ainsie que
				  les fonctions d'ouverture fichier et de
				  test de fichiers vides.*/
/*Directives au pr�-processeur
==============================*/
#include <string>
#include <iostream>
#include <fstream>
#pragma once

//vide le buffer et remet le flux valide
void viderBuffer(std::istream & entree);

//Affiche un message et permet � l'utilisateur d'entrer un int
int saisirInt(std::string message);
//surcharge pour �viter le message
int saisirInt();

//valide qu'un int saisi par saisirInt est positif
int saisirIntPositif(std::string message);

//Affiche un message variable et permet a l'utilisateur d'entr� un float qui est retourn�
float saisirFloat(std::string message);

//Valide que les floats de saisirFloat sont positifs et non nuls
float saisirFloatPositif(std::string message);

//Permet de valider une entr�e selon des crit�res choisis lors de la programmation
char saisirCharValide(std::string message, char critere1, char critere2);

//Permet de saisir une string qui n'est pas vide
std::string saisirStringNonVide(std::string message);

//Demande a l'utilisateur s'il veut effectuer un autre calcul
bool questionOuiNon(std::string message);

//vide le buffer et fait un ignore d�un buffer vide, donc fait une pause
void pause();

//Fais une pause jusqu'a ce que l'utilisateur appuie sur enter
void enter();

//Ouvre un fichier dans un flux re�u en entr�e. Retourne une valeur bool�ene qui
//correspond � la pr�sence ou l'absence du fichier
bool ouvrirFichier(std::ifstream & stream, std::string filepath, std::string messageAbsent);
//Surcharge sans message d'absence
bool ouvrirFichier(std::ifstream & stream, std::string filepath);

//V�rifie si le flux re�u en entr�e est vide ou non et retourne une valeur bool�ene selon le cas.
bool siFichierVide(std::ifstream & stream, std::string messageVide);