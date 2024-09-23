#ifndef _OBJET_H
#define _OBJET_H

#include <string>

#include <iostream>

#include "Position.h"

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
	Position getPosition();
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
	Position position;
	int static nb_objets;
	int id_objet;
	
};


#endif