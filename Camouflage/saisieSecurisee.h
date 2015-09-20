/* En-tête du programme
=======================
Programme:        saisieSecurisee.h
Auteur:           Maxime Michaud-Corriveau
Date création:    16/02/2015
Description:      L'objectif de ce fichier d'en-tête
				  est de regrouper les fonctions
				  de saisie, de validation ainsie que
				  les fonctions d'ouverture fichier et de
				  test de fichiers vides.*/
/*Directives au pré-processeur
==============================*/
#include <string>
#include <iostream>
#include <fstream>
#pragma once

//vide le buffer et remet le flux valide
void viderBuffer(std::istream & entree);

//Affiche un message et permet à l'utilisateur d'entrer un int
int saisirInt(std::string message);
//surcharge pour éviter le message
int saisirInt();

//valide qu'un int saisi par saisirInt est positif
int saisirIntPositif(std::string message);

//Affiche un message variable et permet a l'utilisateur d'entré un float qui est retourné
float saisirFloat(std::string message);

//Valide que les floats de saisirFloat sont positifs et non nuls
float saisirFloatPositif(std::string message);

//Permet de valider une entrée selon des critères choisis lors de la programmation
char saisirCharValide(std::string message, char critere1, char critere2);

//Permet de saisir une string qui n'est pas vide
std::string saisirStringNonVide(std::string message);

//Demande a l'utilisateur s'il veut effectuer un autre calcul
bool questionOuiNon(std::string message);

//vide le buffer et fait un ignore d’un buffer vide, donc fait une pause
void pause();

//Fais une pause jusqu'a ce que l'utilisateur appuie sur enter
void enter();

//Ouvre un fichier dans un flux reçu en entrée. Retourne une valeur booléene qui
//correspond à la présence ou l'absence du fichier
bool ouvrirFichier(std::ifstream & stream, std::string filepath, std::string messageAbsent);
//Surcharge sans message d'absence
bool ouvrirFichier(std::ifstream & stream, std::string filepath);

//Vérifie si le flux reçu en entrée est vide ou non et retourne une valeur booléene selon le cas.
bool siFichierVide(std::ifstream & stream, std::string messageVide);