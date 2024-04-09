#ifndef GAULOIS_H
#define GAULOIS_H

#include "Objet.h"

#include <iostream>

#include <string>

using namespace std;

class Gaulois : public Objet
{
	public:
	
	//Contructeurs
	Gaulois();
	Gaulois(char pSexe);
	Gaulois(char pSexe, int pNumero_ligne, int pNumero_colonne);
	
	//Setters
	void setPosition(int pNumero_ligne, int pNumero_colonne);
	
	
	
	//Méthodes autres
	string toString();
	
	void seDeplacerEnHaut();
	void seDeplacerEnBas();
	void seDeplacerA_Gauche();
	void seDeplacerA_Droite();
	void retournerAsonAnciennePosition();
	
	
	void vieillir();
	
	
	
	protected:
	
	int age;
	char sexe;
	int ancienNumLigne;
	int ancienNumColonne;
	
	
};





#endif