

#include "fonctions.h"

#include "Jeu.h"


using namespace std;

using _it_map = map<string,shared_ptr<Objet>>::iterator;


//Fonctions pour tester le code du projet

void tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne(int NB_LIGNES,int NB_COLONNES, int NB_ELEMENTS_INITIAUX_PAR_LIGNE )
{
	Jeu jeu = Jeu(NB_LIGNES,NB_COLONNES,NB_ELEMENTS_INITIAUX_PAR_LIGNE);
	
	
	cout << "----Test-----: "<< endl 
	<<  NB_LIGNES << " lignes "  << endl
	<< NB_COLONNES << " colonnes " << endl
	<< NB_ELEMENTS_INITIAUX_PAR_LIGNE << " elements_initiaux " << endl
	<< jeu.get_nb_total_elements_presents_dans_la_grille() << " nombre total d'elements " << endl;
		
	if(jeu.get_nb_total_elements_presents_dans_la_grille()== NB_LIGNES*NB_ELEMENTS_INITIAUX_PAR_LIGNE)
	{
		cout << "OK" << endl;
			
	}else
	{
		cout << "NOK" << endl;
	}
	
	cout << "----Fin-Test-----: "<< endl; 
}


void tester()
{
	cout << " Tester qu'il y ait bien tel nombre d'elements total dans la grille" << endl;
	
	
	tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne(10,12,4);
		
		
}
	
	
	
	/*
		Parametres de test
	
	
	int nb_lignes = 2;
	int nb_cases_par_ligne = 15;
	
	*/
	
	/*
	
		_map construire_map(int nb_lignes, int nb_cases_par_ligne)
		void generer_objet_aleatoirement( _map grille, int nb_lignes, int nb_cases_par_ligne)
	
	
	
	string numero_ligne_string = "0";
	
	string numero_colonne_string = "0";
	
	string cle = "0x0";
	
	_map grille = construire_map(nb_lignes,nb_cases_par_ligne);
	
	cout << "grille " << nb_lignes << " lignes et de " << nb_cases_par_ligne<< " de colonnes " << endl;
	
	cout << " verification de 3 elements par ligne " << endl;
	
	*/
	/*
	int numero_ligne_nombre = 1;
	int numero_colonne_nombre = 1;
	
	int comptage_elements_par_ligne = 0;
	int comptage_elements_total = 0;
	
	
	afficher_map(grille);
	*/
	
	
	/*
	for(int i = 1 ; i <= nb_lignes ; i++)
	{
		cout << "----------------------------" << endl;
		cout << "numero de ligne :" << i  << endl;
		
		numero_ligne_nombre = i ;
		
		numero_ligne_string = to_string(numero_ligne_nombre);
		
		comptage_elements_par_ligne = 0;
		*/
		/*
		for(int j = 1 ;  j <= nb_cases_par_ligne ; j++)
		{
			numero_colonne_nombre = j ;
			
			numero_colonne_string = to_string(numero_colonne_nombre);
		
			it = grille->find(numero_ligne_string+"x"+numero_colonne_string);
			
			
		
			if (it != grille->end())
			{
				cout << numero_ligne_string+"x"+numero_colonne_string+" present " << endl;
				comptage_elements_par_ligne++;
			}
		}*/
		
		
		/*cout << " nombre d'elements par ligne:" << comptage_elements_par_ligne << endl;
		
		comptage_elements_total = comptage_elements_total + comptage_elements_par_ligne ;*/
		
		/*cout << "----------------------------" << endl;
		
	}*/
	
	//cout << " nombre d'elements dans la grille: " << comptage_elements_total << " nombre d'elements attendus " << 3*nb_lignes <<endl;
	/*
		Il y a 3 elements par ligne souvent et une fois il y a seulement 2 elements par ligne. 
	*/
	


/*

	_multimap mettre_objets_en_collision_dans_une_multimap(
	_multimap grille_de_transition, int nb_lignes, int nb_cases_par_ligne);

	_multimap gaulois_se_deplacent(
	 _map ancienne_grille, int nb_lignes, int nb_cases_par_ligne);
	 
	 _map appliquer_les_regles_de_priorite_sur_les_collisions
	 (_multimap multimap_contenant_que_les_elements_en_collision);

	 _objet un_objet_qui_se_deplace ( _objet objet, int nb_lignes, int nb_cases_par_ligne);

	_multimap mettre_elements_non_en_collision_dans_multimap(
	_multimap grille_de_transition, int nb_lignes, int nb_cases_par_ligne);

	*/



void affichage()
{
	/*
	
	shared_ptr<map<string,shared_ptr<Objet>>> grille = construire_map(NB_LIGNES,NB_COLONNES);
	
	shared_ptr<multimap<string,shared_ptr<Objet>>> multimap_contenant_que_les_elements_en_collision ;
	
	
	shared_ptr<multimap<string,shared_ptr<Objet>>> grille_de_transition ;
	
	shared_ptr<map<string,shared_ptr<Objet>>> map_contenant_seulement_les_elements_priorises ;
	
	shared_ptr<multimap<string,shared_ptr<Objet>>> multimap_contenant_que_des_elements_non_en_collision;
	
	
	
	cout << "GRILLE DE " << NB_LIGNES << " LIGNES ET DE " << NB_COLONNES << " COLONNES " << endl;
	cout << " -------------------------------------------------------------------------" << endl;
	
	
	afficher_map(grille);
	
	cout << " -------------------------------------------------------------------------" << endl;
	
	cout << "GRILLE DE TRANSITION " << endl;
	cout << " -------------------------------------------------------------------------" << endl;
	grille_de_transition = gaulois_se_deplacent(grille, NB_LIGNES, NB_COLONNES);
	
	
	afficher_multimap(grille_de_transition);
	cout << " -------------------------------------------------------------------------" << endl;
	
	
	cout << " Elements en collision " << endl;
	cout << " -------------------------------------------------------------------------" << endl;
	multimap_contenant_que_les_elements_en_collision = mettre_objets_en_collision_dans_une_multimap(
	grille_de_transition, NB_LIGNES, NB_COLONNES);
	
	afficher_multimap(multimap_contenant_que_les_elements_en_collision);
	
	
	
	cout << " -------------------------------------------------------------------------" << endl;
	
	
	cout << " Priorite " << endl;
	
	
	if(!multimap_contenant_que_les_elements_en_collision->empty())
	{
		map_contenant_seulement_les_elements_priorises = 
		appliquer_les_regles_de_priorite_sur_les_collisions(multimap_contenant_que_les_elements_en_collision);
	
	
		afficher_map(map_contenant_seulement_les_elements_priorises);
	}
	
	cout << " -------------------------------------------------------------------------" << endl;
	
	cout << " Multimap contenant que les elements non en collision " << endl;
	
	multimap_contenant_que_des_elements_non_en_collision = mettre_elements_non_en_collision_dans_multimap(
    grille_de_transition, NB_LIGNES, NB_COLONNES);
	
	afficher_multimap(multimap_contenant_que_des_elements_non_en_collision);
	
	cout << " -------------------------------------------------------------------------" << endl;
	
	*/
	
}









