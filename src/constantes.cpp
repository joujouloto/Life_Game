/*
	Nom du fichier: constantes.cpp


*/

#include <memory>

#include <map>

#include "Gaulois.h"

#define LIMITE_GAUCHE 1
#define LIMITE_HAUT 1


using _map = shared_ptr<map<string,shared_ptr<Objet>>>;
using _multimap = shared_ptr<multimap<string,shared_ptr<Objet>>>;
using _objet = shared_ptr<Objet>;

using _it_map = map<string,shared_ptr<Objet>>::iterator;
using _it_multimap = multimap<string,shared_ptr<Objet>>::iterator;

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

enum type_Objet { type_Arbre = 1, type_Gaulois = 2, type_Gauloise = 3 };

enum type_Deplacement { gauche = 1, droite = 2, haut = 3, bas = 4};

enum sexe_gaulois { homme = 'M' , femme = 'F'};


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