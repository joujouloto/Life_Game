#ifndef _JEU_V2_H
#define _JEU_V2_H


//------------------------------------------------

#include <map>

#include <memory>

#include <SDL2/SDL.h>




//------------------------------------------------


//------------------------------------------------

#include "Objet.h"


//------------------------------------------------


using _grille = shared_ptr< map < Position,shared_ptr<Objet>  > >;
using _objet = shared_ptr<Objet>;

using _it_grille = map < Position,shared_ptr<Objet>  >::iterator;


class Jeu_v2
{
	public:
	Jeu_v2();
	
	
	void initialiser_grille();
	
	//void verifier_que_objets_se_deplacent_dans_les_limites_de_la_grille();
	
	
	//toString
	string afficher_dans_chaine_contenu_grille();
	
	
	
	
	protected:
	int nb_lignes;
	int nb_colonnes;
	int nb_elements_a_mettre_par_ligne_au_debut;
	int nb_total_d_elements_presents_dans_la_grille;
	_grille grille;
	
	
};


#endif