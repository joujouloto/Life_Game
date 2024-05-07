
#include <fstream>
#include <iostream>
#include <string>


#include "Jeu.h"


using namespace std;

using _it_map = map<string,shared_ptr<Objet>>::iterator;


//Fonctions pour tester le code du projet

void tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE )
{
	fstream file;
    file.open("../../tests/tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne.txt", ios::out|ios::app);
    string line;
	
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	Jeu jeu = Jeu(NB_LIGNES,NB_COLONNES,NB_ELEMENTS_INITIAUX_PAR_LIGNE);
	
	
	cout << "----tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne-----: "<< endl 
	<<  NB_LIGNES << " lignes "  << endl
	<< NB_COLONNES << " colonnes " << endl
	<< NB_ELEMENTS_INITIAUX_PAR_LIGNE << " elements_initiaux " << endl
	<< jeu.get_nb_total_elements_presents_dans_la_grille() << " nombre total d'elements " << endl
	<< NB_LIGNES*NB_ELEMENTS_INITIAUX_PAR_LIGNE << " nombre total qui est cense y avoir " << endl;
		
	if(jeu.get_nb_total_elements_presents_dans_la_grille()== NB_LIGNES*NB_ELEMENTS_INITIAUX_PAR_LIGNE)
	{
		cout << "OK" << endl;
			
	}else
	{
		cout << "NOK" << endl;
	}
	
	
	jeu.afficher_nb_elements_par_ligne();
	
	jeu.afficher_contenu_de_la_grille();
	
	cout << "----Fin-tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne-----: "<< endl; 
	
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
	
	
}

void tester_que_les_objets_se_deplacent_sans_collision(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE)
{
	
	fstream file;
    file.open("../../tests/tester_que_les_objets_se_deplacent_sans_collision.txt", ios::out|ios::app);
    string line;
	
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	cout << "----tester_que_les_objets_se_deplacent_sans_collision-------: "<< endl ;
	
	
	Jeu jeu = Jeu(NB_LIGNES,NB_COLONNES,NB_ELEMENTS_INITIAUX_PAR_LIGNE);
	
	cout << "-------------------------------------grille initialisee--- " << endl;
	jeu.afficher_contenu_de_la_grille();
	
	
	
	jeu.faire_deplacer_objets_dans_grille_de_transition();
	
	cout << "-------------------------------------contenu de la grille de transition " << endl;
	jeu.afficher_grille_de_transition();
	
	cout << "-------------------------------------contenu de la multimap qui contient que les elements en collision " << endl;
	
	jeu.mettre_objets_en_collision_dans_une_multimap();
	jeu.afficher_multimap_qui_contient_que_les_elements_en_collision();
	
	
	cout << "-------------------------------------contenu de la map qui contient que les elements qui etaient en collision sont priorises " << endl;
	
	jeu.appliquer_les_regles_de_priorite_sur_les_collisions();
	jeu.afficher_map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite();
	
	
	cout << "------------------------------------la nouvelle grille--- " << endl;
	
	jeu.regrouper_tous_les_elements();
	jeu.afficher_contenu_de_la_grille();
	
	
	
	cout << "----Fin-tester_que_les_objets_se_deplacent_sans_collision-------: "<< endl ;
	
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
}


void tester_que_les_objets_se_deplacent_bien(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE, unsigned TOURS)
{
	fstream file;
    file.open("../../tests/tester_que_les_objets_se_deplacent_bien.txt", ios::out|ios::app);
    string line;
	
	// Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	cout << "----tester_que_les_objets_se_deplacent_bien-------: "<< endl ;
	
	
	Jeu jeu = Jeu(NB_LIGNES,NB_COLONNES,NB_ELEMENTS_INITIAUX_PAR_LIGNE);
	
	cout << "-------------------------------------grille initialisee--- " << endl;
	jeu.afficher_contenu_de_la_grille();
	
	
	
	
	for(unsigned i = 1;i<=TOURS;i++)
	{
		cout << "-->>>>>>Jeu en mouvement: Tour " << i << endl;
	
		jeu.faire_deplacer_objets();
		jeu.afficher_contenu_de_la_grille();
	}
	
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
	
}

//quand il y a juste des déplacements
void tester_qu_il_y_a_bien_le_meme_nombre_d_elements_apres_chaque_tour(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE, unsigned TOURS)
{
	fstream file;
    file.open("../../tests/tester_qu_il_y_a_bien_le_meme_nombre_d_elements_apres_chaque_tour.txt", ios::out|ios::app);
    string line;
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	
	Jeu jeu = Jeu(NB_LIGNES,NB_COLONNES,NB_ELEMENTS_INITIAUX_PAR_LIGNE);
	
	jeu.initialiser_map();
	
	for(unsigned i = 1; i <= TOURS ;i++)
	{
		cout << "-->>>>>> Jeu en mouvement: Tour " << i << endl;
		jeu.faire_deplacer_objets();
		cout << " nombre d elements: " << jeu.get_nb_total_elements_presents_dans_la_grille() << endl;
		cout << " nombre total de gaulois et de gauloises: " << jeu.get_nb_total_gaulois() << endl;
		cout << " nombre total de gauloises: " << jeu.get_nb_total_gaulois_feminin() << endl;
		cout << " nombre total de gaulois: " << jeu.get_nb_total_gaulois_masculin() << endl;
		cout << " nombre total d'arbres: " << jeu.get_nb_total_arbres() << endl;
	}
	
	
	
	
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
}


void tester_la_SDL(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE)
{
	fstream file;
    file.open("../../tests/tester_la_SDL.txt", ios::out|ios::app);
    string line;
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	
	Jeu jeu = Jeu(NB_LIGNES,NB_COLONNES,NB_ELEMENTS_INITIAUX_PAR_LIGNE);
	
	jeu.SDL();
	
	
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
}

void tester_le_nombre_de_morts(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE, unsigned TOURS, unsigned age_de_deces_probable)
{
	fstream file;
    file.open("../../tests/tester_le_nombre_de_morts.txt", ios::out|ios::app);
    string line;
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	
	Jeu jeu = Jeu(NB_LIGNES,NB_COLONNES,NB_ELEMENTS_INITIAUX_PAR_LIGNE);
	jeu.initialiser_map();
	
	for(unsigned i = 1; i <= TOURS ;i++)
	{
		cout << "-->>>>>>Jeu en mouvement: Tour " << i << endl;
		jeu.faire_deplacer_objets();
		jeu.faire_vieillir_population_gauloise();
		jeu.faire_mourir_les_gaulois_trop_vieux(age_de_deces_probable);
		
		
	}
	
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
}


void tester()
{
	
	
	
	cout << " Tests " << endl;
	
	/*
	tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne(3,10,4);
	tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne(7,10,5);
	tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne(7,10,9);
	tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne(7,10,10);*/
	
	//tester_que_les_objets_se_deplacent_sans_collision(3, 5, 2);
	
	
	//tester_que_les_objets_se_deplacent_bien(10,7,3,10);

	tester_qu_il_y_a_bien_le_meme_nombre_d_elements_apres_chaque_tour(10,7,3,100);
	
	
	//tester_la_SDL(10,7,3);
	
	//tester_le_nombre_de_morts(7,10,5,30,10);
}
	
	











