#ifndef FONC_H
#define FONC_H

#include <SDL2/SDL.h>

#include "Objet.h"

#include <map>

#include <memory>

using _map = shared_ptr<map<string,shared_ptr<Objet>>>;
using _multimap = shared_ptr<multimap<string,shared_ptr<Objet>>>;
using _objet = shared_ptr<Objet>;



//affichage
_map initialisation_jeu(
SDL_Renderer *renderer, _map grille, int nb_lignes, int nb_cases_par_ligne);

_map faire_tourner_le_jeu(
SDL_Renderer *renderer, _map grille, int nb_lignes, int nb_cases_par_ligne);

void boucle_SDL(SDL_Renderer *renderer, _map grille, int nb_lignes, int nb_cases_par_ligne);

void fermeture_SDL(SDL_Window *win, SDL_Renderer *renderer);

int initialisation_SDL(int nb_lignes, int nb_cases_par_ligne);


//moteur


//-------------------------------------------------------------
void afficher_map(_map grille);

/*
	Nom de la fonction: afficher_map
	
	Description: affiche textuellement sur console le contenu du paramètre grille
	
	Paramètres d'entrée: grille de type pointeur intelligent de map contenant une clé de type chaîne de caracteres et de valeur objet (voir fichier objet.h)
	
	Paramètres de sortie: rien
	
	Préconditions: map doit être initialisée
	
	Postconditions: rien

*/

//-------------------------------------------------------------

//------------------------------------------------------------------------------------------

//-------------------------------------------------------------
void afficher_multimap(_multimap grille);

/*
	Nom de la fonction: afficher_multimap
	
	Description: affiche textuellement sur console le contenu du paramètre grille
	
	Paramètres d'entrée: grille de type pointeur intelligent de multimap contenant une clé de type chaîne de caracteres et de valeur objet (voir fichier objet.h)
	
	Une multimap peut contenir des valeurs avec des mêmes clés tandis que qu'une map contient des valeurs avec des clés uniques
	
	Paramètres de sortie: rien
	
	Préconditions: map doit être initialisée
	
	Postconditions: rien

*/

//-------------------------------------------------------------

//------------------------------------------------------------------------------------------


//-------------------------------------------------------------
_map construire_map(int nb_lignes, int nb_cases_par_ligne, int nb_objets_a_creer_par_ligne = 3);


/*
	Nom de la fonction: construire_map
	
	Description: appelle la fonction generer_objet_aleatoirement pour créer aléatoirement des elements (pour l'instant des arbres, des gaulois, des gauloises) 
	(3 par ligne )
	
	Paramètres d'entrée: 	nb_lignes qui est de type entier qui est le nombre de lignes de la grille(map), 
							nb_cases_par_ligne qui est le nombre de colonnes de la grille ( une map est un tableau à 2 dimensions avec une clé qui identifie une 
							valeur ici un objet qui peut être un arbre, un gaulois ou une gauloise)
							nb_objets_a_creer_par_ligne 
	
	Paramètres de sortie: 	retourne une variable de type pointeur intelligent de map qui a pour clé une chaîne de caractères (ici 1x2, où 1 est le numero de ligne	
							et 2 est le numero de colonne) et a pour valeur un objet qui peut être un arbre, une gauloise ou un gaulois
	
	Préconditions: 			nb_lignes et nb_cases_par_ligne doivent être positifs 
							nb_objets_a_creer_par_ligne est par défaut à 3 , doit être positif et nb_lignes doit être supérieur à nb_objets_a_creer_par_ligne
	
	Postconditions: rie

*/

//-------------------------------------------------------------





_multimap mettre_objets_en_collision_dans_une_multimap(
_multimap grille_de_transition, int nb_lignes, int nb_cases_par_ligne);

_multimap gaulois_se_deplacent(
 _map ancienne_grille, int nb_lignes, int nb_cases_par_ligne);
 
 _map appliquer_les_regles_de_priorite_sur_les_collisions
 (_multimap multimap_contenant_que_les_elements_en_collision);

 _objet un_objet_qui_se_deplace ( _objet objet, int nb_lignes, int nb_cases_par_ligne);

_multimap mettre_elements_non_en_collision_dans_multimap(
_multimap grille_de_transition, int nb_lignes, int nb_cases_par_ligne);

#endif


