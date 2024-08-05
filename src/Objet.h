#ifndef _OBJET_H
#define _OBJET_H

#include <string>

#include <iostream>



using namespace std;

class Objet
{
	public:
	
	//Constructeurs
	Objet();
	Objet(string pNom);
	Objet(unsigned pNumero_ligne, unsigned pNumero_colonne);
	Objet(string pNom, unsigned pNumero_ligne, unsigned pNumero_colonne);
	
	
	//Méthodes d'accès aux atrributs
	string getNom();
	unsigned getNumeroLigne();
	unsigned getNumeroColonne();
	string getPosition();
	
	//Set
	void setNom(string pNom);
	
	
	//Retourne une description de l'objet
	virtual string toString() = 0;
	
	
	//Destructeur
	~Objet();
	
	
	protected:
	
	string nom;
	unsigned numero_ligne;
	unsigned numero_colonne;
	
};


#endif