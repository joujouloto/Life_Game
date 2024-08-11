#ifndef GAULOIS_H
#define GAULOIS_H

//------------------------------------------------
#include <iostream>

#include <string>

#include <memory>

#include <random>

#include <map>
//------------------------------------------------


//------------------------------------------------
#include "Objet.h"



//------------------------------------------------


using namespace std;



using _map = shared_ptr<map<string,shared_ptr<Objet>>>;

class Gaulois : public Objet
{
	public:
	
	//Contructeurs
	Gaulois();
	Gaulois(char pSexe);
	Gaulois(char pSexe, unsigned pNumero_ligne, unsigned pNumero_colonne);
	
	//Setters
	void seDeplacer(unsigned pNumero_ligne, unsigned pNumero_colonne);
	
	
	//Getters
	unsigned getAncienneLigne();
	unsigned getAncienneColonne();
	unsigned getAge();
	
	
	//Méthodes autres
	string toString();
	
	void seDeplacerEnHaut();
	void seDeplacerEnBas();
	void seDeplacerA_Gauche();
	void seDeplacerA_Droite();
	void retournerAsonAnciennePosition();
	
	void seDeplacerAleatoirement(_map grille);
	
	
	
	
	void vieillir();
	
	
	
	protected:
	
	unsigned age;
	char sexe;
	unsigned ancienNumLigne;
	unsigned ancienNumColonne;
	
	
};





#endif