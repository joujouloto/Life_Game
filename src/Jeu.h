/*
	Nom du fichier: Jeu.h


*/

#ifndef _JEU_H
#define _JEU_H

#include "Objet.h"



using _map = shared_ptr<map<string,shared_ptr<Objet>>>;

class Jeu
{
	public:
	
	//Constructeurs
	Jeu(int p_nb_lignes, int p_nb_colonnes, int p_nb_elements_a_mettre_par_ligne);
	
	
	
	//Méthodes
	//Pour créer au début une grille avec des elements initialement
	void initialiser_map(int nb_lignes, int nb_cases_par_ligne, int nb_objets_a_creer_par_ligne);
	
	
	//Méthodes d'affichage sur console
	void afficher_infos_de_base_du_jeu();
	void afficher_contenu_de_la_grille();
	void afficher_nb_elements_par_ligne();
	void afficher_nb_elements_par_colonne();
	
	//Avoir le nombre d'éléments par ligne et par colonne
	int get_nb_elements_par_ligne(int numero_ligne);
	int get_nb_elements_par_colonne(int numero_colonne);
	
	
	//Attributs
	protected:
	
	int nb_lignes;
	int nb_colonnes;
	int nb_elements_a_mettre_par_ligne_au_debut;
	int nb_total_d_elements_presents_dans_la_grille;
	_map grille;
	
};








#endif