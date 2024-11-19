#ifndef GAULOIS_H
#define GAULOIS_H

//------------------------------------------------
#include <iostream>

#include <string>

#include <memory>

#include <random>

#include <set>

#include <map>


//------------------------------------------------


//------------------------------------------------

#include "Position.h"


#include "Objet.h"


//------------------------------------------------

using _map = shared_ptr< set < shared_ptr<Objet> > >;



class Gaulois : public Objet
{
	public:
	
	//Contructeurs
	Gaulois();
	Gaulois(char pSexe);
	Gaulois(char pSexe, int pNumero_ligne, int pNumero_colonne);
	
	
	
	
	
	
	
	//Getters
	char getSexe();
	int getAge();
	int get_nb_gaulois_crees();
	
	int getIdGaulois();
	
	
	
	
	//Méthodes autres
	string toString();
	string getDeplacements();
	
	void vieillir();
	
	//Fonctions mouvements
	void seDeplacer(int pNumero_ligne, int pNumero_colonne, _map grille);
	void seDeplacer(Position nouvelle_position, _map grille);
	 
	void seDeplacer_aleatoirement(_map grille);
	void seDeplacer_a_gauche(_map grille);
	void seDeplacer_a_droite(_map grille);
	void seDeplacer_en_haut(_map grille);
	void seDeplacer_en_bas(_map grille);
	
	
	
	protected:
	
	int age;
	char sexe;
	
	static int nb_gaulois ;
	int id_gaulois;
	
	int nb_deplacements;
	map< int, Position> coordonnees_par_ou_passait_gaulois;
	
	
};





#endif