/*
	Nom du fichier: Jeu.h


*/

#ifndef _JEU_H
#define _JEU_H

#include "Objet.h"

#include <map>

#include <memory>



using _map = shared_ptr<map<string,shared_ptr<Objet>>>;
using _multimap = shared_ptr<multimap<string,shared_ptr<Objet>>>;
using _objet = shared_ptr<Objet>;

using _it_map = map<string,shared_ptr<Objet>>::iterator;
using _it_multimap = multimap<string,shared_ptr<Objet>>::iterator;

class Jeu
{
	public:
	
	//Constructeurs
	Jeu(unsigned p_nb_lignes, unsigned p_nb_colonnes, unsigned p_nb_elements_a_mettre_par_ligne);
	
	
	
	//Méthodes
	//Pour créer au début une grille avec des elements initialement
	void initialiser_map(unsigned nb_lignes, unsigned nb_cases_par_ligne, unsigned nb_objets_a_creer_par_ligne);
	
	
	//Méthodes d'affichage sur console
	void afficher_infos_de_base_du_jeu();
	void afficher_contenu_de_la_grille();
	void afficher_nb_elements_par_ligne();
	void afficher_nb_elements_par_colonne();
	
	//Afficher grille de transition de type multimap
	void afficher_grille_de_transition();
	
	//Afficher multimap qui contient que les elements en collision
	void afficher_multimap_qui_contient_que_les_elements_en_collision();
	
	//Afficher map qui contient les elements qui etaient en collision sont priorisés
	void afficher_map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite();
	
	
	//Avoir le nombre d'éléments par ligne et par colonne
	unsigned get_nb_elements_par_ligne(unsigned numero_ligne);
	unsigned get_nb_elements_par_colonne(unsigned numero_colonne);
	
	//Avoir le nombre total d'elements dans la grille
	unsigned get_nb_total_elements_presents_dans_la_grille();
	
	//méthodes pour faire correctement déplacer les objets sur la grille
	void faire_deplacer_objets_dans_grille_de_transition();
	shared_ptr<Objet> faire_deplacer_un_gaulois_e_dans_grille(shared_ptr<Objet> objet);
	void mettre_objets_en_collision_dans_une_multimap();
	void appliquer_les_regles_de_priorite_sur_les_collisions();
	void regrouper_tous_les_elements();
	
	//Méthode qui simplifie et qui regroupe les 5 précédentes
	void faire_deplacer_objets();
	
	
	
	
	//-------------------------------------------------------------------------------
	
	//Attributs
	protected:
	
	unsigned nb_lignes;
	unsigned nb_colonnes;
	unsigned nb_elements_a_mettre_par_ligne_au_debut;
	unsigned nb_total_d_elements_presents_dans_la_grille;
	_map grille;
	
	
	//Attributs que l'on veut pas trop montrer (interne au fonctionnement du déplacement des objets)
	_multimap grille_de_transition;
	_multimap multimap_contenant_que_les_elements_en_collision;
	_map map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite;
	
	
	
	
	
};








#endif