/*
	Nom du fichier: Jeu.cpp

*/

/*

//-----------------------------------------------------------------------------------------------

	Liste des includes officiels

*/
#include <iostream>

#include <string>

#include <map>

#include <random>

#include <memory>

#include <stdlib.h>

//-----------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------

/*
	Liste des includes que j'ai crée
*/

#include "Gaulois.h"

#include "Arbre.h"

#include "Jeu.h"


//-----------------------------------------------------------------------------------------------

using namespace std;

using _map = shared_ptr<map<string,shared_ptr<Objet>>>;
using _multimap = shared_ptr<multimap<string,shared_ptr<Objet>>>;
using _objet = shared_ptr<Objet>;

using _it_map = map<string,shared_ptr<Objet>>::iterator;
using _it_multimap = multimap<string,shared_ptr<Objet>>::iterator;


enum type_Objet { type_Arbre = 1, type_Gaulois = 2, type_Gauloise = 3 };

enum type_Deplacement { gauche = 1, droite = 2, haut = 3, bas = 4};



Jeu::Jeu(int p_nb_lignes, int p_nb_colonnes, int p_nb_elements_a_mettre_par_ligne)
{
	
	nb_lignes = p_nb_lignes;
	nb_colonnes = p_nb_colonnes;
	nb_elements_a_mettre_par_ligne_au_debut = p_nb_elements_a_mettre_par_ligne;
	
	
	initialiser_map(nb_lignes, nb_colonnes, nb_elements_a_mettre_par_ligne_au_debut);
	
	
	nb_total_d_elements_presents_dans_la_grille = grille->size();
}


void Jeu::initialiser_map(int nb_lignes, int nb_cases_par_ligne, int nb_objets_a_creer_par_ligne)
{
	grille = make_shared<map<string,shared_ptr<Objet>>>();	
	
	random_device rd;
	mt19937 gen(rd());
	
	random_device rd2;
	mt19937 gen2(rd2());
	
	
	uniform_int_distribution<> dis(1, nb_cases_par_ligne);//uniform distribution between 1 and 18
	uniform_int_distribution<> dis2(1, nb_objets_a_creer_par_ligne);//uniform distribution between 1 and 3
	
	int numero_ligne_nombre = 0;
	int numero_colonne_nombre = 0;
	int objet_genere = 0;
	
	string numero_ligne_string = "0";
	string numero_colonne_string = "0";
	
	
	
	
	for(int i = 1 ; i <= nb_lignes ; i++)
	{
		
		for (int n = 1; n <= nb_objets_a_creer_par_ligne ; ++n) 
		{
			numero_colonne_nombre = dis(gen);
			objet_genere = dis2(gen2);
			
			numero_ligne_nombre = i ;
			
			numero_ligne_string = to_string(numero_ligne_nombre);
			numero_colonne_string = to_string(numero_colonne_nombre);
			
			if(objet_genere==type_Arbre)
			{
				shared_ptr<Arbre> arbre = make_shared<Arbre>(numero_ligne_nombre,numero_colonne_nombre);	
				grille->insert(pair<string,shared_ptr<Objet>>(numero_ligne_string+"x"+numero_colonne_string,arbre));
			}
			else if(objet_genere==type_Gaulois)
			{
				shared_ptr<Gaulois> gaulois = make_shared<Gaulois>('M',numero_ligne_nombre,numero_colonne_nombre);	
				grille->insert(pair<string,shared_ptr<Objet>>(numero_ligne_string+"x"+numero_colonne_string,gaulois));
			}
			else if(objet_genere==type_Gauloise)
			{
				shared_ptr<Gaulois> gauloise = make_shared<Gaulois>('F',numero_ligne_nombre, numero_colonne_nombre);
				grille->insert(pair<string,shared_ptr<Objet>>(numero_ligne_string+"x"+numero_colonne_string,gauloise));
			}
			
			
		}
	}
}

void Jeu::afficher_infos_de_base_du_jeu()
{
	cout << "----------------------------------------------------------------JEU_DE_LA_VIE-----------------------" << endl;
	cout << "Nombre de lignes: "<< this->nb_lignes << endl
	<< " Nombre de colonnes: "<< this->nb_colonnes << endl
	<< " Nombre d'elements initiaux par ligne: "<< this->nb_elements_a_mettre_par_ligne_au_debut << endl
	<< " Nombre total d'elements dans la grille: "<< this->nb_total_d_elements_presents_dans_la_grille << endl;
	;
	
}

void Jeu::afficher_contenu_de_la_grille()
{
	int compteur = 1 ;
	int compteur_nb_lignes = 1;
	
	
	cout << "-----------------------------------------------CONTENU_DE_LA_GRILLE---------------------------------" << endl;
	cout << "------------------Numero_de_ligne----------"<<compteur_nb_lignes<<endl;
	
	for ( _it_map it=grille->begin(); it!=grille->end(); ++it) 
	{	
		if(compteur>nb_elements_a_mettre_par_ligne_au_debut)
		{
			compteur_nb_lignes++;
			cout << "------------------Numero_de_ligne----------"<<compteur_nb_lignes<<endl;
			compteur=1;
		}


		cout << it->first << it->second->toString()<< endl;
		compteur++;
	}
	
	
	
}


int Jeu::get_nb_elements_par_ligne(int numero_ligne)
{
	int nb_elements_par_la_ligne = 0;
	
	
	for ( _it_map it=grille->begin(); it!=grille->end(); ++it) 
	{
		if(it->second->getNumeroLigne()==numero_ligne)
		{
			nb_elements_par_la_ligne++;
		}
	}
	
	
	return nb_elements_par_la_ligne;
	
}

int Jeu::get_nb_elements_par_colonne(int numero_colonne)
{
	int nb_elements_par_la_colonne = 0;
	
	
	for ( _it_map it=grille->begin(); it!=grille->end(); ++it) 
	{
		if(it->second->getNumeroColonne()==numero_colonne)
		{
			nb_elements_par_la_colonne++;
		}
	}
	
	
	return nb_elements_par_la_colonne;
}

void Jeu::afficher_nb_elements_par_ligne()
{
	
	
	for(int i = 1 ; i <= this->nb_lignes ; i++)
	{
		cout << "numero de ligne "<< i<< " :" << this->get_nb_elements_par_ligne(i) << endl;
	}
	
	
	
}

void Jeu::afficher_nb_elements_par_colonne()
{
	
	
	for(int j = 1 ; j <= this->nb_colonnes ; j++)
	{
		cout << "numero de colonne " << j << " :"<< this->get_nb_elements_par_colonne(j) << endl;
	}	
}

