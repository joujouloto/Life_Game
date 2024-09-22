#include <fstream>
#include <iostream>
#include <string>
#include <random>
#include <ctime>


#include "Gaulois.h"
#include "Jeu_v2.h"



using namespace std;


//Fonctions pour tester le code du projet

//Afficher la date à chaque fois qu'il y a un test



void afficher_date()
{
	// date / heure actuelle basée sur le système actuel
   time_t tmm = time(0);
   
   // convertir en forme de chaîne
   char* dt = ctime(&tmm);
   cout << "La date et l'heure locales sont: " << dt << endl;
   
   
   // convertir en tm struct pour UTC
  /* tm *g = gmtime(&tmm);
   dt = asctime(g);
   cout << "La date et l'heure UTC sont:"<< dt << endl;*/
}


void tester_nouvelle_architecture_de_conception()
{
	string chemin_dossier_tests = "../../tests/";
	string chemin_fichier = "nouvelle_architecture/premier_test.txt";
	
	
	
	
	fstream file;
    file.open(chemin_dossier_tests+chemin_fichier, ios::out|ios::app);
    string line;
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	afficher_date();
	
	
	Jeu_v2 jeu = Jeu_v2();
	
	string str_contenu_grille = jeu.afficher_dans_chaine_contenu_grille();
	
	cout << str_contenu_grille;
	
	
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
	
}

void tester_v2()
{
	
	cout << " Tests_v2 " << endl;
	
	
	
	tester_nouvelle_architecture_de_conception();
	
}