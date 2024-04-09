/*
	Nom du fichier: moteur.cpp
	
	Description:	Contient les fonctions pour créer une grille de type map qui a pour clé 
					les coordonnées et pour valeur un objet soit un gaulois,gauloise ou arbre;
					les objets comme les gaulois(e)s se déplacent...
					
					
				

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

//-----------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------

/*
	Liste des includes que j'ai crée
*/



#include "Gaulois.h"

#include "Arbre.h"


//-----------------------------------------------------------------------------------------------

/*
	Définition de constantes
*/

#define LIMITE_GAUCHE 1
#define LIMITE_HAUT 1

//-----------------------------------------------------------------------------------------------



using namespace std;

using _map = shared_ptr<map<string,shared_ptr<Objet>>>;
using _multimap = shared_ptr<multimap<string,shared_ptr<Objet>>>;
using _objet = shared_ptr<Objet>;

using _it_map = map<string,shared_ptr<Objet>>::iterator;
using _it_multimap = multimap<string,shared_ptr<Objet>>::iterator;


enum type_Objet { type_Arbre = 1, type_Gaulois = 2, type_Gauloise = 3 };

enum type_Deplacement { gauche = 1, droite = 2, haut = 3, bas = 4};


//--------------------------------------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------
void afficher_map( _map grille)
{
	for ( _it_map it=grille->begin(); it!=grille->end(); ++it) 
	{
    	cout << it->first << " => " << it->second->toString() << endl;
	}
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

void afficher_multimap( _multimap grille)
{
	for ( _it_multimap it=grille->begin(); it!=grille->end(); ++it) 
	{
    	cout << it->first << " => " << it->second->toString() << endl;
	}
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------


_map construire_map( int nb_lignes, int nb_cases_par_ligne, int nb_objets_a_creer_par_ligne = 3)
{
	
	_map grille = make_shared<map<string,shared_ptr<Objet>>>();	
	
	random_device rd;
	mt19937 gen(rd());
	
	random_device rd2;
	mt19937 gen2(rd2());
	
	
	uniform_int_distribution<> dis(1, nb_cases_par_ligne);//uniform distribution between 1 and 18
	uniform_int_distribution<> dis2(1, nb_objets_a_creer_par_ligne);//uniform distribution between 1 and 3
	
	int numero_ligne_nombre = 0;
	int numero_colonne_nombre = 0;
	int objet_genere = 0;
	
	string numero_ligne_string = "0";
	string numero_colonne_string = "0";
	
	
	
	
	for(int i = 1 ; i <= nb_lignes ; i++)
	{
		
		for (int n = 1; n <= nb_objets_a_creer_par_ligne ; ++n) 
		{
			numero_colonne_nombre = dis(gen);
			objet_genere = dis2(gen2);
			
			numero_ligne_nombre = i ;
			
			numero_ligne_string = to_string(numero_ligne_nombre);
			numero_colonne_string = to_string(numero_colonne_nombre);
			
			if(objet_genere==type_Arbre)
			{
				shared_ptr<Arbre> arbre = make_shared<Arbre>(numero_ligne_nombre,numero_colonne_nombre);	
				grille->insert(pair<string,shared_ptr<Objet>>(numero_ligne_string+"x"+numero_colonne_string,arbre));
			}
			else if(objet_genere==type_Gaulois)
			{
				shared_ptr<Gaulois> gaulois = make_shared<Gaulois>('M',numero_ligne_nombre,numero_colonne_nombre);	
				grille->insert(pair<string,shared_ptr<Objet>>(numero_ligne_string+"x"+numero_colonne_string,gaulois));
			}
			else if(objet_genere==type_Gauloise)
			{
				shared_ptr<Gaulois> gauloise = make_shared<Gaulois>('F',numero_ligne_nombre, numero_colonne_nombre);
				grille->insert(pair<string,shared_ptr<Objet>>(numero_ligne_string+"x"+numero_colonne_string,gauloise));
			}
			
			
		}
	}
	
	return grille;
	
	
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

bool si_2_gaulois_sont_proches(int numero_ligne_1er_gaulois, int numero_colonne_1er_gaulois, int numero_ligne_2eme_gaulois, int numero_colonne_2eme_gaulois)
{
	bool estProche = false;
	
	if(abs(numero_ligne_1er_gaulois-numero_ligne_2eme_gaulois)<=1 && abs(numero_colonne_1er_gaulois-numero_colonne_2eme_gaulois) <= 1)
	{
		estProche = true; 
	}
	
	return estProche;
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

void gaulois_se_reproduisent(shared_ptr<map<string,shared_ptr<Objet>>> * grille)
{
	//grille->insert(pair<string,string>("1x1","[Gauloise]"));
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------


bool ne_deborde_pas_par_la_gauche(shared_ptr<Gaulois> gaulois_ou_gauloise)
{
	if(LIMITE_GAUCHE <= gaulois_ou_gauloise->getNumeroLigne()-1)
	{
		return true;
	}else
		return false;
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

bool ne_deborde_pas_par_la_droite(shared_ptr<Gaulois> gaulois_ou_gauloise, int nb_lignes)
{
	int LIMITE_DROITE = nb_lignes;
	
	if( LIMITE_DROITE >= gaulois_ou_gauloise->getNumeroLigne()+1)
	{
		return true;
	}else
		return false;
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

bool ne_deborde_pas_par_le_haut(shared_ptr<Gaulois> gaulois_ou_gauloise)
{
	if( LIMITE_HAUT <= gaulois_ou_gauloise->getNumeroColonne()-1)
	{
		return true;
	}else
		return false;
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

bool ne_deborde_pas_par_le_bas(shared_ptr<Gaulois> gaulois_ou_gauloise, int nb_cases_par_ligne)
{
	int LIMITE_BAS = nb_cases_par_ligne;
	
	
	if( LIMITE_BAS >= gaulois_ou_gauloise->getNumeroColonne()+1)
	{
		return true;
	}else
		return false;
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------


//Les objets immobiles comme les arbres ne se deplacent pas donc ils sont à la même place dans l'ancienne grille et dans la nouvelle grille

bool case_a_gauche_n_est_pas_occupee_par_un_arbre (_map ancienne_grille , 
shared_ptr<Gaulois> gaulois_ou_gauloise)
{
	
	_it_map it;
	
	
	_objet objet ;
	
	
	it = ancienne_grille->find(
	
	to_string(gaulois_ou_gauloise->getNumeroLigne()-1)
	+"x"+
	to_string(gaulois_ou_gauloise->getNumeroColonne())
	
	);
	
	bool case_vide = true;
	
	if( it != ancienne_grille->end() )
	{
		objet = it->second;
	
	
		if( objet->getNom() == "Arbre" )
		{
			case_vide = false;			
		}
	}
	
	
	
	return case_vide;
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

bool case_a_droite_n_est_pas_occupee_par_un_arbre (_map  ancienne_grille , 
shared_ptr<Gaulois> gaulois_ou_gauloise)
{
	
	
	_it_map it;
	
	shared_ptr<Objet> objet;

	
	
	it = ancienne_grille->find(
	to_string(gaulois_ou_gauloise->getNumeroLigne()+1)
	+"x"+
	to_string(gaulois_ou_gauloise->getNumeroColonne()) 
	) 
	;
	
	bool case_vide = true;
	
	if( it != ancienne_grille->end() )
	{
		objet = it->second;
	
	
		if( objet->getNom() == "Arbre" )
		{
			case_vide = false;			
		}
	}
	
	return case_vide;
	
	
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

bool case_en_haut_n_est_pas_occupee_par_un_arbre ( _map ancienne_grille , 
shared_ptr<Gaulois> gaulois_ou_gauloise)
{
	
	_it_map it;
	
	_objet objet ;
	
	
	it = ancienne_grille->find(
	to_string(gaulois_ou_gauloise->getNumeroLigne())
	+"x"+
	to_string(gaulois_ou_gauloise->getNumeroColonne()-1) 
	);
	
	bool case_vide = true;
	
	
	if( it != ancienne_grille->end() )
	{
		objet = it->second;
	
	
		if( objet->getNom() == "Arbre" )
		{
			case_vide = false;			
		}
	}
	
	return case_vide;
}


//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

bool case_en_bas_n_est_pas_occupee_par_un_arbre (_map  ancienne_grille , 
shared_ptr<Gaulois> gaulois_ou_gauloise)
{
	
	_it_map it;
	
	_objet objet ;


	it = ancienne_grille->find(
	to_string(gaulois_ou_gauloise->getNumeroLigne())
	+"x"+
	to_string(gaulois_ou_gauloise->getNumeroColonne()+1)
	);
	
	bool case_vide = true;
	
	
	if( it != ancienne_grille->end() )
	{
		objet = it->second;
	
	
		if( objet->getNom() == "Arbre" )
		{
			case_vide = false;			
		}
	}
	
	return case_vide;
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

_multimap mettre_objets_en_collision_dans_une_multimap(
_multimap grille_de_transition, int nb_lignes, int nb_cases_par_ligne)
{
	
	_multimap multimap_contenant_que_les_elements_en_collision
	= make_shared<multimap<string,shared_ptr<Objet>>>();

	string numero_ligne_string = "0";
	string numero_colonne_string = "0";
	string cle = "0x0";
	
	_objet objet ;
	
	for (int i = 1 ; i <= nb_lignes ; i++)
	{
		
		for(int j = 1 ; j <= nb_cases_par_ligne ; j++)
		{
			numero_ligne_string = to_string(i);
			numero_colonne_string = to_string(j);
			
			cle = numero_ligne_string+"x"+numero_colonne_string;
			 
			for (_it_multimap it=grille_de_transition->equal_range(cle).first;
			it!=grille_de_transition->equal_range(cle).second; ++it)
			{
				if( grille_de_transition->count(cle) > 1)
				{
					objet = it->second;
					
					
					multimap_contenant_que_les_elements_en_collision
					->insert(pair<string,shared_ptr<Objet>>(cle,objet));
				}
				
				
				
			}
		}
	}
	
	return multimap_contenant_que_les_elements_en_collision;
	
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

_map appliquer_les_regles_de_priorite_sur_les_collisions
 (_multimap multimap_contenant_que_les_elements_en_collision)
 
 {
	 _map map_ou_priorite_appliquee = make_shared<map<string,shared_ptr<Objet>>>();
	 int compteur = 1 ;
	 
	 string cle_comparaison = "0x0";
	 string cle_objet_parcouru = "0x0";
	 string cle_objets_qui_ne_gardent_pas_la_priorite = "0x0";
	 string cle_objet_qui_garde_sa_priorite = "0x0";
	 
	 string numero_ligne_string = "0";
	 string numero_colonne_string = "0";
	 
	 shared_ptr<Objet> objet ;
	 shared_ptr<Gaulois> gaulois_e ;
	 
	 string numero_ligne_objet_qui_ne_garde_pas_sa_priorite_string = "0";
	 string numero_colonne_objet_qui_ne_garde_pas_sa_priorite_string = "0";
	 
	
	for (_it_multimap it=multimap_contenant_que_les_elements_en_collision->begin();
			it!=multimap_contenant_que_les_elements_en_collision->end(); ++it)
	{
		
		
		objet = it->second;
		
		
		
		numero_ligne_string = to_string(objet->getNumeroLigne());
		numero_colonne_string = to_string(objet->getNumeroColonne());
		
		cle_objet_parcouru = numero_ligne_string + "x" + numero_colonne_string;
		
		
		
		if(cle_comparaison!=cle_objet_parcouru)
		{
			cle_comparaison = cle_objet_parcouru ;
			compteur = 1 ;
			
			cle_objet_qui_garde_sa_priorite = cle_objet_parcouru;
			
			map_ou_priorite_appliquee->insert(pair<string,shared_ptr<Objet>>(
			cle_objet_qui_garde_sa_priorite,objet));
			
		}
		else
		{
			compteur++;
			
			if(compteur>1)
			{
				gaulois_e = dynamic_pointer_cast<Gaulois> (objet);
				
				gaulois_e->retournerAsonAnciennePosition();
				
				objet = gaulois_e ;
				
				numero_ligne_objet_qui_ne_garde_pas_sa_priorite_string = to_string(objet->getNumeroLigne());
				numero_colonne_objet_qui_ne_garde_pas_sa_priorite_string = to_string(objet->getNumeroColonne());
				
				
				cle_objets_qui_ne_gardent_pas_la_priorite = numero_ligne_objet_qui_ne_garde_pas_sa_priorite_string 
				+ "x" + numero_colonne_objet_qui_ne_garde_pas_sa_priorite_string;
				
				map_ou_priorite_appliquee->insert(
				pair<string,shared_ptr<Objet>>(cle_objets_qui_ne_gardent_pas_la_priorite,objet));
				
			}

		}
		
	}
	
	
	
	return map_ou_priorite_appliquee;
 }
 
//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------
 
 
_objet  un_objet_qui_se_deplace ( _objet objet, 
 _map ancienne_grille,
 int nb_lignes, int nb_cases_par_ligne)
 {
	random_device rd;
	
	mt19937 gen(rd());
	
	int deplacement = 0 ;
	
	shared_ptr<Gaulois> gaulois_ou_gauloise;
	 
	uniform_int_distribution<> dis(1, 4);//uniform distribution between 1 and 4 
	 
	gaulois_ou_gauloise = dynamic_pointer_cast<Gaulois> (objet);
	deplacement = dis(gen);
			
			
			
	if(deplacement==gauche)
	{
		
		
		if( ne_deborde_pas_par_la_gauche(gaulois_ou_gauloise) 
			&& case_a_gauche_n_est_pas_occupee_par_un_arbre (ancienne_grille , gaulois_ou_gauloise))
		{
			gaulois_ou_gauloise->seDeplacerA_Gauche();
		}
		else if( ne_deborde_pas_par_la_droite(gaulois_ou_gauloise,nb_lignes) 
			&& case_a_droite_n_est_pas_occupee_par_un_arbre (ancienne_grille , gaulois_ou_gauloise))
		{
			gaulois_ou_gauloise->seDeplacerA_Droite();
			
		}
		else if( ne_deborde_pas_par_le_haut(gaulois_ou_gauloise) 
			&& case_en_haut_n_est_pas_occupee_par_un_arbre (ancienne_grille , gaulois_ou_gauloise) )
		{
			gaulois_ou_gauloise->seDeplacerEnHaut();
			
		}
		else if( ne_deborde_pas_par_le_bas(gaulois_ou_gauloise,nb_cases_par_ligne) 
			&& case_en_bas_n_est_pas_occupee_par_un_arbre (ancienne_grille , gaulois_ou_gauloise))
		{
			gaulois_ou_gauloise->seDeplacerEnBas();
		}
		
		
		
		
	}else if(deplacement==droite)
	{
		
		if( ne_deborde_pas_par_la_droite(gaulois_ou_gauloise,nb_lignes) 
			&& case_a_droite_n_est_pas_occupee_par_un_arbre (ancienne_grille , gaulois_ou_gauloise)  )
		{
			gaulois_ou_gauloise->seDeplacerA_Droite();
			
		} 
		else if( ne_deborde_pas_par_la_gauche(gaulois_ou_gauloise) 
			&& case_a_gauche_n_est_pas_occupee_par_un_arbre(ancienne_grille , gaulois_ou_gauloise)	)	
		{
			gaulois_ou_gauloise->seDeplacerA_Gauche();
		}
		
		else if( ne_deborde_pas_par_le_haut(gaulois_ou_gauloise) 
			&& case_en_haut_n_est_pas_occupee_par_un_arbre(ancienne_grille , gaulois_ou_gauloise) )
		{
			gaulois_ou_gauloise->seDeplacerEnHaut();
			
		}
		else if( ne_deborde_pas_par_le_bas(gaulois_ou_gauloise,nb_cases_par_ligne) 
			 && case_en_bas_n_est_pas_occupee_par_un_arbre (ancienne_grille , gaulois_ou_gauloise)	 	)			
		{
			gaulois_ou_gauloise->seDeplacerEnBas();
		}
		
	}else if(deplacement==haut)
	{
		if( ne_deborde_pas_par_le_haut(gaulois_ou_gauloise) 
			&& case_en_haut_n_est_pas_occupee_par_un_arbre(ancienne_grille , gaulois_ou_gauloise) )
		{
			gaulois_ou_gauloise->seDeplacerEnHaut();
			
		}
		else if( ne_deborde_pas_par_le_bas(gaulois_ou_gauloise,nb_cases_par_ligne) 
			&& case_en_bas_n_est_pas_occupee_par_un_arbre (ancienne_grille , gaulois_ou_gauloise) )
		{
			gaulois_ou_gauloise->seDeplacerEnBas();
		}
		else if( ne_deborde_pas_par_la_droite(gaulois_ou_gauloise,nb_lignes) 
			&& case_a_droite_n_est_pas_occupee_par_un_arbre (ancienne_grille , gaulois_ou_gauloise) )
		{
			gaulois_ou_gauloise->seDeplacerA_Droite();
			
		} 
		else if( ne_deborde_pas_par_la_gauche(gaulois_ou_gauloise) 
			&& case_a_gauche_n_est_pas_occupee_par_un_arbre(ancienne_grille , gaulois_ou_gauloise) )			
		{
			gaulois_ou_gauloise->seDeplacerA_Gauche();
		}
		
	}else if(deplacement==bas)
	{
		if( ne_deborde_pas_par_le_bas(gaulois_ou_gauloise,nb_cases_par_ligne) 
			&& case_en_bas_n_est_pas_occupee_par_un_arbre (ancienne_grille , gaulois_ou_gauloise) )
		{
			gaulois_ou_gauloise->seDeplacerEnBas();
		}
		else if( ne_deborde_pas_par_le_haut(gaulois_ou_gauloise) 
			&& case_en_haut_n_est_pas_occupee_par_un_arbre(ancienne_grille , gaulois_ou_gauloise) )
		{
			gaulois_ou_gauloise->seDeplacerEnHaut();
			
		}
		else if( ne_deborde_pas_par_la_gauche(gaulois_ou_gauloise) 
			&& case_a_gauche_n_est_pas_occupee_par_un_arbre(ancienne_grille , gaulois_ou_gauloise))
		{
			gaulois_ou_gauloise->seDeplacerA_Gauche();
		}
		else if( ne_deborde_pas_par_la_droite(gaulois_ou_gauloise,nb_lignes) 
			&& case_a_droite_n_est_pas_occupee_par_un_arbre (ancienne_grille , gaulois_ou_gauloise)  )
		{
			gaulois_ou_gauloise->seDeplacerA_Droite();
			
		} 
	}
	
	return objet;
 }
 
//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------
 

//Les gaulois se deplacent  bien mais ils s'effacent les arbres et peut être les autres gaulois

_multimap gaulois_se_deplacent( 
_map ancienne_grille, int nb_lignes, int nb_cases_par_ligne)
{
	//Déclaration des variables
	_it_map it;
	
	_map nouvelle_grille;
	
	shared_ptr<Arbre> arbre;
	
	
	shared_ptr<Objet> objet ;
	
	string numero_ligne_string = "0";
	
	string numero_colonne_string = "0";
	
	string cle = "0x0";
	
	
	
	//bool si_un_objet_est_deja_dans_la_case = false;
	
	
	_multimap grille_de_transition
	= make_shared<multimap<string,shared_ptr<Objet>>>();	
	
	
	
	//Créer une nouvelle grille
	nouvelle_grille = make_shared<map<string,shared_ptr<Objet>>>();
	
	
	//
	for (_it_map it=ancienne_grille->begin(); it!=ancienne_grille->end(); ++it)
	{
		objet = it->second;
		
		if(objet->getNom()=="Arbre")
		{
			arbre = dynamic_pointer_cast<Arbre> (objet);
			
			numero_ligne_string = to_string(arbre->getNumeroLigne());
			numero_colonne_string = to_string(arbre->getNumeroColonne());
			
			cle = numero_ligne_string + "x" + numero_colonne_string;
			//nouvelle_grille->insert(pair<string,shared_ptr<Objet>>(numero_ligne_string+"x"+numero_colonne_string,arbre));
			
			grille_de_transition->insert(pair<string,shared_ptr<Objet>>(cle,arbre));
			
		}
		else if(objet->getNom()=="Gaulois"||objet->getNom()=="Gauloise")
		{
			cout << " avant " << endl;
			cout << objet->getNom() << endl;
			objet = un_objet_qui_se_deplace (objet,ancienne_grille,nb_lignes,nb_cases_par_ligne);
			cout << " apres " << endl;
			
			numero_ligne_string = to_string(objet->getNumeroLigne());
			numero_colonne_string = to_string(objet->getNumeroColonne());
			
			cle = numero_ligne_string + "x" + numero_colonne_string;
			
			grille_de_transition->insert(
			pair<string,shared_ptr<Objet>>(cle,objet));
			
		}
	}
	
	return grille_de_transition;
	
	
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------


_multimap mettre_elements_non_en_collision_dans_multimap(
_multimap grille_de_transition, int nb_lignes, int nb_cases_par_ligne)
{
	_multimap multimap_ne_contenant_que_des_elements_non_en_collision
	= make_shared<multimap<string,shared_ptr<Objet>>>();

	string numero_ligne_string = "0";
	string numero_colonne_string = "0";
	string cle = "0x0";
	
	shared_ptr<Objet> objet ;
	
	for (int i = 1 ; i <= nb_lignes ; i++)
	{
		
		for(int j = 1 ; j <= nb_cases_par_ligne ; j++)
		{
			numero_ligne_string = to_string(i);
			numero_colonne_string = to_string(j);
			
			cle = numero_ligne_string+"x"+numero_colonne_string;
			 
			for (_it_multimap it=grille_de_transition->equal_range(cle).first;
			it!=grille_de_transition->equal_range(cle).second; ++it)
			{
				if( grille_de_transition->count(cle) == 1)
				{
					objet = it->second;
					
					
					multimap_ne_contenant_que_des_elements_non_en_collision
					->insert(pair<string,shared_ptr<Objet>>(cle,objet));
				}
				
				
				
			}
		}
	}
	
	return multimap_ne_contenant_que_des_elements_non_en_collision;
}

//-----------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------------------------





