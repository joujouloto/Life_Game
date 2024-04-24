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
	Gaulois(char pSexe, unsigned pNumero_ligne, unsigned pNumero_colonne);
	
	//Setters
	void setPosition(unsigned pNumero_ligne, unsigned pNumero_colonne);
	
	
	
	//Méthodes autres
	string toString();
	
	void seDeplacerEnHaut();
	void seDeplacerEnBas();
	void seDeplacerA_Gauche();
	void seDeplacerA_Droite();
	void retournerAsonAnciennePosition();
	
	
	
	
	void vieillir();
	
	
	
	protected:
	
	unsigned age;
	char sexe;
	unsigned ancienNumLigne;
	unsigned ancienNumColonne;
	
	
};





#endif