/*
	Nom du fichier: Jeu.cpp

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

#include <set>

//-----------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------

/*
	Liste des includes que j'ai crée
*/

#include "Gaulois.h"

#include "Arbre.h"

#include "Jeu.h"

#include "constantes.h"



//-----------------------------------------------------------------------------------------------

using namespace std;

using _map = shared_ptr<map<string,shared_ptr<Objet>>>;
using _multimap = shared_ptr<multimap<string,shared_ptr<Objet>>>;
using _objet = shared_ptr<Objet>;

using _it_map = map<string,shared_ptr<Objet>>::iterator;
using _it_multimap = multimap<string,shared_ptr<Objet>>::iterator;


enum type_Objet { type_Arbre = 1, type_Gaulois = 2, type_Gauloise = 3 };

enum type_Deplacement { gauche = 1, droite = 2, haut = 3, bas = 4};







/*
	Nom de la fonction: Jeu()
	
	Description: instancie un jeu avec des parametres
	
	Paramètres d'entrée: 	p_nb_lignes qui est de type entier qui est le nombre de lignes de la grille(map), 
							p_nb_colonnes qui est le nombre de colonnes de la grille ( une map est un tableau à 2 dimensions avec une clé qui identifie une 
							valeur ici un objet qui peut être un arbre, un gaulois ou une gauloise)
							p_nb_elements_a_mettre_par_ligne
	
	Paramètres de sortie: 	-
	
	Préconditions: 			nb_lignes et nb_cases_par_ligne doivent être positifs 
							nb_objets_a_creer_par_ligne doit être positif et nb_lignes doit être supérieur à nb_objets_a_creer_par_ligne
	
	Postconditions: rien

*/

//-------------------------------------------------------------

Jeu::Jeu(unsigned p_nb_lignes, unsigned p_nb_colonnes, unsigned p_nb_elements_a_mettre_par_ligne)
{
	
	nb_lignes = p_nb_lignes;
	nb_colonnes = p_nb_colonnes;
	nb_elements_a_mettre_par_ligne_au_debut = p_nb_elements_a_mettre_par_ligne;
	
	grille_de_transition = make_shared<multimap<string,shared_ptr<Objet>>>();
	
	multimap_contenant_que_les_elements_en_collision = make_shared<multimap<string,shared_ptr<Objet>>>();
	
	map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite = make_shared<map<string,shared_ptr<Objet>>>();
	
	
	initialiser_map(nb_lignes, nb_colonnes, nb_elements_a_mettre_par_ligne_au_debut);
	
	
	nb_total_d_elements_presents_dans_la_grille = grille->size();
}

/*

*/
void Jeu::initialiser_map(unsigned nb_lignes, unsigned nb_cases_par_ligne, unsigned nb_objets_a_creer_par_ligne)
{
	
	//On crée un pointeur intelligent de map qui a pour clé une chaîne de caracteres
	grille = make_shared<map<string,shared_ptr<Objet>>>();
	
	
	
	
	
	random_device rd;
	mt19937 gen(rd());
	
	random_device rd2;
	mt19937 gen2(rd2());
	
	
	uniform_int_distribution<> dis(1, nb_cases_par_ligne);//uniform distribution between 1 and 18
	uniform_int_distribution<> dis2(1, 3);//uniform distribution between 1 and 3
	
	unsigned numero_ligne_nombre = 0;
	unsigned numero_colonne_nombre = 0;
	unsigned objet_genere = 0;
	
	string numero_ligne_string = "0";
	string numero_colonne_string = "0";
	
	set<unsigned> liste_numeros_colonne_deja_tombes;
	set<unsigned>::iterator it;
	pair<set<unsigned>::iterator,bool> ret_set;
	pair< map<string,shared_ptr<Objet>>::iterator , bool >  ret_map;
	
	shared_ptr<Arbre> arbre;
	shared_ptr<Gaulois> gaulois;
	shared_ptr<Gaulois> gauloise;
	
	
	for(unsigned i = 1 ; i <= nb_lignes ; i++)
	{
		
		for (unsigned n = 1; n <= nb_objets_a_creer_par_ligne ; n++) 
		{
			
			/*
				Boucle necessaire pour ne pas avoir le même numero de colonne
				quand on reboucle sur la même ligne. On boucle nb_objets_a_creer_par_ligne fois
				sur la même ligne
			*/
			do
			{
				numero_colonne_nombre = dis(gen);
				numero_colonne_string = to_string(numero_colonne_nombre);
				ret_set = liste_numeros_colonne_deja_tombes.insert(numero_colonne_nombre);
				
				//cout << numero_colonne_nombre << endl;
				
				
			}while(ret_set.second==false);
			
			/*if(ret_set.second==true)
			{
				cout << numero_colonne_nombre << endl;
			}*/
			
			
			
			objet_genere = dis2(gen2);
			
			
			numero_ligne_nombre = i ;
			
			numero_ligne_string = to_string(numero_ligne_nombre);
			
			
			
			if(objet_genere==type_Arbre)
			{
				arbre = make_shared<Arbre>(numero_ligne_nombre,numero_colonne_nombre);	
				ret_map = grille->insert(pair<string,shared_ptr<Objet>>(numero_ligne_string+"x"+numero_colonne_string,arbre));
			}
			else if(objet_genere==type_Gaulois)
			{
				gaulois = make_shared<Gaulois>('M',numero_ligne_nombre,numero_colonne_nombre);	
				ret_map = grille->insert(pair<string,shared_ptr<Objet>>(numero_ligne_string+"x"+numero_colonne_string,gaulois));
			}
			else if(objet_genere==type_Gauloise)
			{
				gauloise = make_shared<Gaulois>('F',numero_ligne_nombre, numero_colonne_nombre);
				ret_map = grille->insert(pair<string,shared_ptr<Objet>>(numero_ligne_string+"x"+numero_colonne_string,gauloise));
			}
			else
			{
				cout << "else " << endl;
			}
			
			/*
			if(ret_map.second==true)
			{
				cout << "Element ajoute " << ret_map.first->second->toString() << endl;
			}*/
			
			
			
		}
		
		//On efface le contenu de la liste avant d'entrer une nouvelle ligne
		liste_numeros_colonne_deja_tombes.clear();
	}
}

void Jeu::afficher_infos_de_base_du_jeu()
{
	cout << "----------------------------------------------------------------JEU_DE_LA_VIE-----------------------" << endl;
	cout << "Nombre de lignes: "<< this->nb_lignes << endl
	<< " Nombre de colonnes: "<< this->nb_colonnes << endl
	<< " Nombre d'elements initiaux par ligne: "<< this->nb_elements_a_mettre_par_ligne_au_debut << endl
	<< " Nombre total d'elements dans la grille: "<< this->nb_total_d_elements_presents_dans_la_grille << endl;
	;
	
}

void Jeu::afficher_contenu_de_la_grille()
{
	
	cout << "-----------------------------------------------CONTENU_DE_LA_GRILLE---------------------------------" << endl;
	for ( _it_map it=grille->begin(); it!=grille->end(); ++it) 
	{	
		cout << it->first << it->second->toString()<< endl;
	}
	
	
	
}


unsigned Jeu::get_nb_elements_par_ligne(unsigned numero_ligne)
{
	unsigned nb_elements_par_la_ligne = 0;
	
	
	for ( _it_map it=grille->begin(); it!=grille->end(); ++it) 
	{
		if(it->second->getNumeroLigne()==numero_ligne)
		{
			nb_elements_par_la_ligne++;
		}
	}
	
	
	return nb_elements_par_la_ligne;
	
}

unsigned Jeu::get_nb_elements_par_colonne(unsigned numero_colonne)
{
	unsigned nb_elements_par_la_colonne = 0;
	
	
	for ( _it_map it=grille->begin(); it!=grille->end(); ++it) 
	{
		if(it->second->getNumeroColonne()==numero_colonne)
		{
			nb_elements_par_la_colonne++;
		}
	}
	
	
	return nb_elements_par_la_colonne;
}

void Jeu::afficher_nb_elements_par_ligne()
{
	
	
	for(unsigned i = 1 ; i <= this->nb_lignes ; i++)
	{
		cout << "numero de ligne "<< i<< " :" << this->get_nb_elements_par_ligne(i) << endl;
	}
	
	
	
}

void Jeu::afficher_nb_elements_par_colonne()
{
	
	
	for(unsigned j = 1 ; j <= this->nb_colonnes ; j++)
	{
		cout << "numero de colonne " << j << " :"<< this->get_nb_elements_par_colonne(j) << endl;
	}	
}


unsigned Jeu::get_nb_total_elements_presents_dans_la_grille()
{
	return nb_total_d_elements_presents_dans_la_grille;
}


void Jeu::afficher_grille_de_transition()
{
	for ( _it_multimap it=grille_de_transition->begin(); it!=grille_de_transition->end(); ++it) 
	{
    	cout << it->first << " => " << it->second->toString() << endl;
	}
}

void Jeu::afficher_multimap_qui_contient_que_les_elements_en_collision()
{
	for ( _it_multimap it=multimap_contenant_que_les_elements_en_collision->begin(); it!=multimap_contenant_que_les_elements_en_collision->end(); ++it) 
	{
    	cout << it->first << " => " << it->second->toString() << endl;
	}
}

void Jeu::afficher_map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite()
{
	for ( _it_map it=map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->begin(); 
	it!=map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->end(); 
	++it) 
	{
    	cout << it->first << " => " << it->second->toString() << endl;
	}
}


void Jeu::faire_deplacer_objets_dans_grille_de_transition()
{
	//Déclaration des variables
	_it_map it;
	
	shared_ptr<Arbre> arbre;
	
	shared_ptr<Objet> objet ;
	
	string numero_ligne_string = "0";
	
	string numero_colonne_string = "0";
	
	string cle = "0x0";
	
	
	
	//bool si_un_objet_est_deja_dans_la_case = false;
	
	
		
	

	for (_it_map it=grille->begin(); it!=grille->end(); ++it)
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
			
			objet = faire_deplacer_un_gaulois_e_dans_grille(objet);
			
			
			numero_ligne_string = to_string(objet->getNumeroLigne());
			numero_colonne_string = to_string(objet->getNumeroColonne());
			
			cle = numero_ligne_string + "x" + numero_colonne_string;
			
			grille_de_transition->insert(
			pair<string,shared_ptr<Objet>>(cle,objet));
			
		}
	}
}

shared_ptr<Objet> Jeu::faire_deplacer_un_gaulois_e_dans_grille(shared_ptr<Objet> objet)
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
			&& case_a_gauche_n_est_pas_occupee_par_un_arbre (grille , gaulois_ou_gauloise))
		{
			gaulois_ou_gauloise->seDeplacerA_Gauche();
		}
		else if( ne_deborde_pas_par_la_droite(gaulois_ou_gauloise,nb_lignes) 
			&& case_a_droite_n_est_pas_occupee_par_un_arbre (grille , gaulois_ou_gauloise))
		{
			gaulois_ou_gauloise->seDeplacerA_Droite();
			
		}
		else if( ne_deborde_pas_par_le_haut(gaulois_ou_gauloise) 
			&& case_en_haut_n_est_pas_occupee_par_un_arbre (grille , gaulois_ou_gauloise) )
		{
			gaulois_ou_gauloise->seDeplacerEnHaut();
			
		}
		else if( ne_deborde_pas_par_le_bas(gaulois_ou_gauloise,nb_colonnes) 
			&& case_en_bas_n_est_pas_occupee_par_un_arbre (grille , gaulois_ou_gauloise))
		{
			gaulois_ou_gauloise->seDeplacerEnBas();
		}
		
		
		
		
	}else if(deplacement==droite)
	{
		
		if( ne_deborde_pas_par_la_droite(gaulois_ou_gauloise,nb_lignes) 
			&& case_a_droite_n_est_pas_occupee_par_un_arbre (grille , gaulois_ou_gauloise)  )
		{
			gaulois_ou_gauloise->seDeplacerA_Droite();
			
		} 
		else if( ne_deborde_pas_par_la_gauche(gaulois_ou_gauloise) 
			&& case_a_gauche_n_est_pas_occupee_par_un_arbre(grille , gaulois_ou_gauloise)	)	
		{
			gaulois_ou_gauloise->seDeplacerA_Gauche();
		}
		
		else if( ne_deborde_pas_par_le_haut(gaulois_ou_gauloise) 
			&& case_en_haut_n_est_pas_occupee_par_un_arbre(grille , gaulois_ou_gauloise) )
		{
			gaulois_ou_gauloise->seDeplacerEnHaut();
			
		}
		else if( ne_deborde_pas_par_le_bas(gaulois_ou_gauloise,nb_colonnes) 
			 && case_en_bas_n_est_pas_occupee_par_un_arbre (grille , gaulois_ou_gauloise)	 	)			
		{
			gaulois_ou_gauloise->seDeplacerEnBas();
		}
		
	}else if(deplacement==haut)
	{
		if( ne_deborde_pas_par_le_haut(gaulois_ou_gauloise) 
			&& case_en_haut_n_est_pas_occupee_par_un_arbre(grille , gaulois_ou_gauloise) )
		{
			gaulois_ou_gauloise->seDeplacerEnHaut();
			
		}
		else if( ne_deborde_pas_par_le_bas(gaulois_ou_gauloise,nb_colonnes) 
			&& case_en_bas_n_est_pas_occupee_par_un_arbre (grille , gaulois_ou_gauloise) )
		{
			gaulois_ou_gauloise->seDeplacerEnBas();
		}
		else if( ne_deborde_pas_par_la_droite(gaulois_ou_gauloise,nb_lignes) 
			&& case_a_droite_n_est_pas_occupee_par_un_arbre (grille , gaulois_ou_gauloise) )
		{
			gaulois_ou_gauloise->seDeplacerA_Droite();
			
		} 
		else if( ne_deborde_pas_par_la_gauche(gaulois_ou_gauloise) 
			&& case_a_gauche_n_est_pas_occupee_par_un_arbre(grille , gaulois_ou_gauloise) )			
		{
			gaulois_ou_gauloise->seDeplacerA_Gauche();
		}
		
	}else if(deplacement==bas)
	{
		if( ne_deborde_pas_par_le_bas(gaulois_ou_gauloise,nb_colonnes) 
			&& case_en_bas_n_est_pas_occupee_par_un_arbre (grille , gaulois_ou_gauloise) )
		{
			gaulois_ou_gauloise->seDeplacerEnBas();
		}
		else if( ne_deborde_pas_par_le_haut(gaulois_ou_gauloise) 
			&& case_en_haut_n_est_pas_occupee_par_un_arbre(grille , gaulois_ou_gauloise) )
		{
			gaulois_ou_gauloise->seDeplacerEnHaut();
			
		}
		else if( ne_deborde_pas_par_la_gauche(gaulois_ou_gauloise) 
			&& case_a_gauche_n_est_pas_occupee_par_un_arbre(grille , gaulois_ou_gauloise))
		{
			gaulois_ou_gauloise->seDeplacerA_Gauche();
		}
		else if( ne_deborde_pas_par_la_droite(gaulois_ou_gauloise,nb_lignes) 
			&& case_a_droite_n_est_pas_occupee_par_un_arbre (grille , gaulois_ou_gauloise)  )
		{
			gaulois_ou_gauloise->seDeplacerA_Droite();
			
		} 
	}
	
	return objet;
}

void Jeu::mettre_objets_en_collision_dans_une_multimap()
{
	string numero_ligne_string = "0";
	string numero_colonne_string = "0";
	string cle = "0x0";
	
	_objet objet ;
	
	for (unsigned i = 1 ; i <= nb_lignes ; i++)
	{
		
		for(unsigned j = 1 ; j <= nb_colonnes ; j++)
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
}

void Jeu::appliquer_les_regles_de_priorite_sur_les_collisions()
{
	
	 unsigned compteur = 1 ;
	 
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
			
			map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->insert(pair<string,shared_ptr<Objet>>(
			cle_objet_qui_garde_sa_priorite,objet));
			
		}
		else
		{
			compteur++;
			
			if(compteur>1)
			{
				gaulois_e = dynamic_pointer_cast<Gaulois> (objet);
				
				/*
					Attention à la fonction retourner à son ancienne position car l'element qui etait en collision a pour ancienne coordonnee la position 
					où il etait en collision. Or cela doit sa position avant son deplacement en collision
				*/
				
				
				
				gaulois_e->retournerAsonAnciennePosition();
				
				objet = gaulois_e ;
				
				numero_ligne_objet_qui_ne_garde_pas_sa_priorite_string = to_string(objet->getNumeroLigne());
				numero_colonne_objet_qui_ne_garde_pas_sa_priorite_string = to_string(objet->getNumeroColonne());
				
				
				cle_objets_qui_ne_gardent_pas_la_priorite = numero_ligne_objet_qui_ne_garde_pas_sa_priorite_string 
				+ "x" + numero_colonne_objet_qui_ne_garde_pas_sa_priorite_string;
				
				map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->insert(
				pair<string,shared_ptr<Objet>>(cle_objets_qui_ne_gardent_pas_la_priorite,objet));
				
			}

		}
		
	}
}


void Jeu::regrouper_tous_les_elements()
{
	grille->clear();
	
	
	
	string numero_ligne_string = "0";
	string numero_colonne_string = "0";
	string cle = "0x0";
	
	shared_ptr<Objet> objet ;
	
	for (unsigned i = 1 ; i <= nb_lignes ; i++)
	{
		
		for(unsigned j = 1 ; j <= nb_colonnes ; j++)
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
					
					
					grille
					->insert(pair<string,shared_ptr<Objet>>(cle,objet));
				}
				
				
				
			}
		}
	}
	
	
	for( _it_map it = map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->begin();
		it!=map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->end(); 
		++it
	)
	{
		grille->insert(pair<string,shared_ptr<Objet>>(it->first,it->second));
	}
	
	grille_de_transition->clear();
	multimap_contenant_que_les_elements_en_collision->clear();
	map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->clear();
		
}





