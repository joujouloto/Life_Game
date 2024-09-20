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

#include "constantes.h"



//-----------------------------------------------------------------------------------------------

using namespace std;



Jeu_v2::Jeu_v2()
{
	nb_lignes = 20 ;
	nb_colonnes = 20;
	nb_elements_a_mettre_par_ligne_au_debut = 0;
	
	
	initialiser_grille();
	
	
	nb_total_d_elements_presents_dans_la_grille = grille->size();
}


void Jeu_v2::initialiser_grille()
{
	grille = make_shared< set <shared_ptr<Objet> > > ();
	
	
	shared_ptr<Gaulois> gaulois_1,
	gaulois_2,
	gaulois_3;
	
	gaulois_1 = make_shared<Gaulois>(homme,7,5);
	grille->insert(gaulois_1);
	
	
	gaulois_2 = make_shared<Gaulois>(homme,10,3);
	grille->insert(gaulois_2);
	
	gaulois_3 = make_shared<Gaulois>(homme,4,3);
	grille->insert(gaulois_3);
	
	
}


string Jeu_v2::afficher_dans_chaine_contenu_grille()
{
	stringstream ss;
	shared_ptr<Gaulois> gaulois;
	shared_ptr<Objet> objet;
	shared_ptr<Arbre> arbre;
	
	ss << "-------------------------Contenu de la grille---------------------------------------------------";
	ss << "\n";
	
	for (_it_grille it=grille->begin(); it != grille->end(); ++it)
	{
		 objet = *it;
		
		
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
		
		
		
	}
	
	
	
	
	
	ss << "\n";
	
	
	
	return ss.str();
}



















