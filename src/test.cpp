
#include <fstream>
#include <iostream>
#include <string>


#include "Jeu.h"
#include "Gaulois.h"


using namespace std;

using _it_map = map<string,shared_ptr<Objet>>::iterator;


//Fonctions pour tester le code du projet


//meme_nombre_d_elements_a_la_creation

//----------------------------------------------------------------------------------------------------------------



void tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE )
{
	fstream file;
    file.open("../../tests/meme_nombre_d_elements_a_la_creation/tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne.txt", ios::out|ios::app);
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

//----------------------------------------------------------------------------------------------------------------


//fonction_deplacement

//----------------------------------------------------------------------------------------------------------------

void tester_que_les_objets_se_deplacent_sans_collision(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE)
{
	
	fstream file;
    file.open("../../tests/fonction_deplacement/tester_que_les_objets_se_deplacent_sans_collision.txt", ios::out|ios::app);
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
    file.open("../../tests/fonction_deplacement/tester_que_les_objets_se_deplacent_bien.txt", ios::out|ios::app);
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
	int nb_elements_dans_grille_transition = 0;
	int nb_elements_en_collision = 0;
	int nb_elements_ou_on_applique_la_priorite = 0;
	
	
	
	
	fstream file;
    file.open("../../tests/fonction_deplacement/tester_qu_il_y_a_bien_le_meme_nombre_d_elements_apres_chaque_tour.txt", ios::out|ios::app);
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
		
		jeu.faire_deplacer_objets_dans_grille_de_transition();
		
		

		nb_elements_dans_grille_transition = jeu.grille_de_transition->size() ;
		
		
		
		jeu.mettre_objets_en_collision_dans_une_multimap();
		nb_elements_en_collision = jeu.multimap_contenant_que_les_elements_en_collision->size();
		
		cout << "affichage multimap contenant que les elements en collision " << endl;
		jeu.afficher_multimap_qui_contient_que_les_elements_en_collision();
		
		jeu.appliquer_les_regles_de_priorite_sur_les_collisions();
		nb_elements_ou_on_applique_la_priorite = jeu.map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->size();
		
		
		
		if(nb_elements_en_collision!=nb_elements_ou_on_applique_la_priorite)
		{
			
			cout << "affichage multimap ou on applique la priorite " << endl;
			jeu.afficher_map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite();
			
			
			cout << " nombre d'elements dans grille de transition: "<< nb_elements_dans_grille_transition << endl;
			cout << " nombre d'elements dans multimap de collision: " << nb_elements_en_collision << endl;
			cout << " nombre d'elements dans map où on applique la priorité: " << nb_elements_ou_on_applique_la_priorite << endl;
			cout << "Le nombre d'elements en collision n'est pas egal au nombre d'elements auxquels on applique la priorite " << endl;
			
			
		}
		
		if(nb_elements_en_collision==1||nb_elements_ou_on_applique_la_priorite==1)
		{
			cout << " nombre d'elements dans grille de transition: "<< nb_elements_dans_grille_transition << endl;
			cout << " nombre d'elements dans multimap de collision: " << nb_elements_en_collision << endl;
			cout << " nombre d'elements dans map où on applique la priorité: " << nb_elements_ou_on_applique_la_priorite << endl;
			cout << "Le nombre d'elements en collision n'est pas egal  1 ou de meme pour les elements ou on applique la priorite" << endl;
		}
		
		
		
		jeu.regrouper_tous_les_elements();
		
		
		
		
		/*
		cout << " nombre d elements: " << jeu.get_nb_total_elements_presents_dans_la_grille() << endl;
		cout << " nombre total de gaulois et de gauloises: " << jeu.get_nb_total_gaulois() << endl;
		cout << " nombre total de gauloises: " << jeu.get_nb_total_gaulois_feminin() << endl;
		cout << " nombre total de gaulois: " << jeu.get_nb_total_gaulois_masculin() << endl;
		cout << " nombre total d'arbres: " << jeu.get_nb_total_arbres() << endl;*/
	}
	
	
	
	
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
}

//----------------------------------------------------------------------------------------------------------------


//SDL

//----------------------------------------------------------------------------------------------------------------

void tester_la_SDL(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE)
{
	fstream file;
    file.open("../../tests/SDL/tester_la_SDL.txt", ios::out|ios::app);
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

//----------------------------------------------------------------------------------------------------------------


//vieilissement

//----------------------------------------------------------------------------------------------------------------

void tester_le_nombre_de_morts(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE, unsigned TOURS, unsigned age_de_deces_probable)
{
	fstream file;
    file.open("../../tests/vieillissement/tester_le_nombre_de_morts.txt", ios::out|ios::app);
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

//----------------------------------------------------------------------------------------------------------------

//fonction_appliquer_les_regles_de_priorite

//----------------------------------------------------------------------------------------------------------------

void tester_la_fonction_appliquer_les_regles_de_priorite_sur_les_collisions(unsigned NB_LIGNES, unsigned NB_COLONNES)
{
	fstream file;
    file.open("../../tests/fonction_appliquer_les_regles_de_priorite/tester_de_la_fonction_appliquer_les_regles_de_priorite_sur_les_collisions().txt", ios::out|ios::app);
    string line;
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	
	Jeu jeu = Jeu(NB_LIGNES,NB_COLONNES,0);
	
	shared_ptr<Gaulois> gaulois_1;
	shared_ptr<Gaulois> gaulois_2;
	shared_ptr<Gaulois> gauloise_3;
	shared_ptr<Gaulois> gauloise_4;
	shared_ptr<Gaulois> gaulois_5;
	
	
	cout << "---------------Création d'elements dans la grille où on applique la priorite------------------" << endl;
	cout << " On cree des elements volontairement en collision pour tester si la fonction appliquer_les_regles_de_priorite_sur_les_collisions() fonctionne bien " << endl;
	
	/*
		affichage multimap contenant que les elements en collision 
		2x5 =>  Gaulois
		1x5 >> 2x5
		age: 1
		
		2x5 =>  Gaulois
		3x5 >> 3x5
		age: 1
		
		3x5 =>  Gauloise
		3x4 >> 3x5
		age: 1
		
		3x5 =>  Gauloise
		4x5 >> 4x5
		age: 1
		
		affichage multimap ou on applique la priorite 
		2x5 =>  Gaulois
		1x5 >> 2x5
		age: 1
		
		3x5 =>  Gaulois
		3x5 >> 3x5
		age: 1
		
		4x5 =>  Gauloise
		4x5 >> 4x5
		age: 1
		
		*/
	
	gaulois_1 = make_shared<Gaulois>('M',1,5);
	gaulois_1->seDeplacer(2,5);
	jeu.ajouter_objet_dans_multimap_contenant_que_les_elements_en_collision(gaulois_1);
	
	
	
	
	gaulois_2 = make_shared<Gaulois>('M',2,5);
	gaulois_2->seDeplacer(3,5);
	jeu.ajouter_objet_dans_multimap_contenant_que_les_elements_en_collision(gaulois_2);
	
	gauloise_3 = make_shared<Gaulois>('F',3, 4);
	gauloise_3->seDeplacer(3,5);
	jeu.ajouter_objet_dans_multimap_contenant_que_les_elements_en_collision(gauloise_3);
	
	gauloise_4 = make_shared<Gaulois>('F',4, 5);
	gauloise_4->seDeplacer(3,5);
	jeu.ajouter_objet_dans_multimap_contenant_que_les_elements_en_collision(gauloise_4);
	
	
	
	gaulois_5 = make_shared<Gaulois>('M',5, 5);
	gaulois_5->seDeplacer(4,5);
	jeu.ajouter_objet_dans_multimap_contenant_que_les_elements_en_collision(gaulois_5);
	
	jeu.afficher_multimap_qui_contient_que_les_elements_en_collision();
	
	
	//On applique la priorite
	
	
	
	cout << "----------------On applique la priorite---------------------------------------------" << endl;
	
	jeu.appliquer_les_regles_de_priorite_sur_les_collisions();
	
	jeu.afficher_map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite();
	
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
}


//----------------------------------------------------------------------------------------------------------------

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

	//tester_qu_il_y_a_bien_le_meme_nombre_d_elements_apres_chaque_tour(10,7,3,100);
	
	
	//tester_la_SDL(10,7,3);
	
	//tester_le_nombre_de_morts(7,10,5,30,10);
	
	tester_la_fonction_appliquer_les_regles_de_priorite_sur_les_collisions(10, 10);
	
}
	
	











