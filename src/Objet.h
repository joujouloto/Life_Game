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
	Objet(int pNumero_ligne, int pNumero_colonne);
	Objet(string pNom, int pNumero_ligne, int pNumero_colonne);
	
	
	//Méthodes d'accès aux atrributs
	string getNom();
	int getNumeroLigne();
	int getNumeroColonne();
	
	//Set
	void setNom(string pNom);
	
	
	//Retourne une description de l'objet
	virtual string toString() = 0;
	
	
	//Destructeur
	~Objet();
	
	
	protected:
	
	string nom;
	int numero_ligne;
	int numero_colonne;
	
};


#endif