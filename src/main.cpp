

#include <SDL2/SDL.h>


#include "test.h"
#include "Jeu.h"


using namespace std;


/*
	On veut créer un jeu de la vie avec des gaulois. L'étoile * représente le gaulois.
	
	
	Grille de 3x3 avec 4 gaulois
	
	[*][ ][*]
	[ ][ ][*]
	[ ][*][ ]
*/





#undef main


int main( int argc, char *args[] ) {
	
	int retour = 0;
	
	//retour = initialisation_SDL(NB_LIGNES,NB_COLONNES);
	
	
	//affichage();
	
	//tester_qu_il_a_bien_3_elements_par_ligne();
	/*
	int NB_LIGNES = 7;
	int NB_COLONNES = 10;
	int NB_ELEMENTS_INITIAUX_PAR_LIGNE = 3;
	
	
	
	
	Jeu jeu = Jeu(NB_LIGNES,NB_COLONNES,NB_ELEMENTS_INITIAUX_PAR_LIGNE);
	
	jeu.afficher_infos_de_base_du_jeu();
	jeu.afficher_contenu_de_la_grille();
	
	jeu.afficher_nb_elements_par_ligne();
	jeu.afficher_nb_elements_par_colonne();*/
	
	
	tester();
	
	
	
    return retour;
	
	
  
}
