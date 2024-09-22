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
	string getType();
	int getNbObjets();
	int getIdObjet();
	
	//Set
	void setNom(string pNom);
	void setType(string pType);
	
	//Retourne une description de l'objet
	virtual string toString() = 0;
	
	
	//Destructeur
	~Objet();
	
	
	protected:
	
	
	string type;
	
	string nom;
	unsigned numero_ligne;
	unsigned numero_colonne;
	int static nb_objets;
	int id_objet;
	
};


#endif