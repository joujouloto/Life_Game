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
	
	void seDeplacerEnHaut(_map grille);
	void seDeplacerEnBas(_map grille, int NB_COLONNES);
	void seDeplacerA_Gauche(_map grille);
	void seDeplacerA_Droite(_map grille, int NB_LIGNES);
	void retournerAsonAnciennePosition();
	
	void seDeplacerAleatoirement(_map grille, int NB_LIGNES, int NB_COLONNES);
	
	
	
	
	void vieillir();
	
	
	
	protected:
	
	unsigned age;
	char sexe;
	unsigned ancienNumLigne;
	unsigned ancienNumColonne;
	
	
};





#endif