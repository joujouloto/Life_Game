/*
	Nom du fichier: Jeu_nouvelle_architecture.cpp

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

#include <set>

#include<chrono>
#include<thread>

#include <sstream>

//-----------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------

/*
	Liste des includes que j'ai crée
*/

#include "Gaulois.h"

#include "Arbre.h"

#include "Jeu_v2.h"

#include "Animal.h"



//-----------------------------------------------------------------------------------------------

using namespace std;



enum sexe_gaulois { homme = 'M' , femme = 'F'};

Jeu_v2::Jeu_v2()
{
	nb_lignes = 20 ;
	nb_colonnes = 20;
	nb_elements_a_mettre_par_ligne_au_debut = 0;
	
	
	initialiser_grille();
	
	
	nb_total_d_elements_presents_dans_la_grille = grille->size();
}


_grille Jeu_v2::getGrille()
{
		return grille;
}


void Jeu_v2::initialiser_grille()
{
	grille = make_shared< map < Position, shared_ptr<Objet> > > ();
	
	
	shared_ptr<Gaulois> gaulois_1,
	gaulois_2,
	gaulois_3;
	
	shared_ptr<Arbre> arbre_1,
	arbre_2,
	arbre_3;
	
	shared_ptr<Animal> animal_1;
	
	
	gaulois_1 = make_shared<Gaulois>(homme,7,5);
	grille->insert( { gaulois_1->getPosition(), gaulois_1} );
	
	gaulois_2 = make_shared<Gaulois>(homme,4,3);
	grille->insert( { gaulois_2->getPosition(), gaulois_2} );
	
	gaulois_3 = make_shared<Gaulois>(femme,8,9);
	grille->insert( { gaulois_3->getPosition(), gaulois_3} );
	
	arbre_1 = make_shared<Arbre>(2,5);
	grille->insert( { arbre_1->getPosition(), arbre_1} );
	
	arbre_2 = make_shared<Arbre>(1,6);
	grille->insert( { arbre_2->getPosition(), arbre_2} );
	
	arbre_3 = make_shared<Arbre>(10,7);
	grille->insert( { arbre_3->getPosition(), arbre_3} );
	
	animal_1 = make_shared<Animal>(9,9);
	grille->insert( {animal_1->getPosition(),animal_1});
	
	
	
	
	
}

//ATTENTION le contenu n'est pas mis à jour quand on fait deplacer un element
string Jeu_v2::afficher_dans_chaine_contenu_grille()
{
	stringstream ss;
	shared_ptr<Gaulois> gaulois;
	shared_ptr<Objet> objet;
	shared_ptr<Arbre> arbre;
	shared_ptr<Animal> animal;
	
	ss << "-------------------------Contenu de la grille---------------------------------------------------";
	ss << "\n";
	
	for (_it_grille it=grille->begin(); it != grille->end(); ++it)
	{
		 objet = it->second;
		
		
		ss << "\n";
		
		if(objet->getType()=="Gaulois")
		{
			gaulois = dynamic_pointer_cast<Gaulois> (objet);
			
			ss << gaulois->toString();
			
		}
		else if(objet->getType()=="Arbre")
		{
			
			arbre = dynamic_pointer_cast<Arbre> (objet);
			
			ss << arbre->toString();
			
		}
		else if(objet->getType()=="Animal")
		{
			animal = dynamic_pointer_cast<Animal> (objet);
			
			ss << animal->toString();
		}
		
		
		
	}
	
	
	
	
	
	ss << "\n ";
	

	
	
	
	return ss.str();
}



void Jeu_v2::faire_deplacer_elements()
{
	shared_ptr<Gaulois> gaulois_1;
	
	map< Position, shared_ptr<Objet> > :: iterator  it;
	
	Position position_1er_gaulois = Position(7,5);
	
	it = grille->find(position_1er_gaulois);
	
	gaulois_1 = dynamic_pointer_cast<Gaulois> (it->second);
	
	
	Position nouvelle_position = Position(7,6);
	
	gaulois_1->seDeplacer(nouvelle_position,grille);
	
	it = grille->find(nouvelle_position);
	
	
	gaulois_1 = dynamic_pointer_cast<Gaulois> (it->second);
	
	cout << endl;
	
	cout << gaulois_1->toString();

	//faire deplacer plusieurs objets
	
	shared_ptr<Gaulois> gaulois_2, gaulois_3, gaulois_4;
	
	
	cout << endl;
	
	gaulois_2 = make_shared<Gaulois>(homme,4,3);
	grille->insert( { gaulois_2->getPosition(), gaulois_2} );
	
	gaulois_2->seDeplacer_aleatoirement(grille);
		
	cout << gaulois_2->toString() << endl;
	
	
	gaulois_2->seDeplacer_aleatoirement(grille);
		
	cout << gaulois_2->toString() << endl;
	
	
	gaulois_2->seDeplacer_aleatoirement(grille);
		
	cout << gaulois_2->toString() << endl;
	
	
	
	
	
	
}
















