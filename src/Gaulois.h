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

#include "Position.h"



//------------------------------------------------


using namespace std;



using _map = shared_ptr<map<Position,shared_ptr<Objet>>>;

class Gaulois : public Objet
{
	public:
	
	//Contructeurs
	Gaulois();
	Gaulois(char pSexe);
	Gaulois(char pSexe, int pNumero_ligne, int pNumero_colonne);
	
	//Setters
	void seDeplacer(int pNumero_ligne, int pNumero_colonne, _map grille);
	
	
	//Getters
	int getAge();
	int get_nb_gaulois_crees();
	string getDeplacements();
	int getIdGaulois();
	Position getPosition_actuelle();
	
	
	//Méthodes autres
	string toString();
	
	
	void vieillir();
	
	
	
	protected:
	
	int age;
	char sexe;
	int nb_deplacements;
	map< int, Position> coordonnees_par_ou_passait_gaulois;
	
	
	
	static int nb_gaulois ;
	int id_gaulois;
	
	
	
};





#endif