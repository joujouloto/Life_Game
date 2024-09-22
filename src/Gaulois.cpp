#include "Gaulois.h"

#include <sstream>

#include <map>


int Gaulois::nb_gaulois = 0;

//Constructeurs
Gaulois::Gaulois(): Objet("Gaulois")
{
	age = 1;
	sexe = 'M';
	ancienNumLigne = 0;
	ancienNumColonne = 0;
	
	nb_gaulois++;
	
	id_gaulois = nb_gaulois;
	
	setNom(nom+" "+to_string(nb_gaulois));
	
	setType("Gaulois");
	
	
	
	nb_deplacements = 0;
	
	int numero_deplacement = nb_deplacements ;
	
	
	coordonnees_par_ou_passait_gaulois.insert( pair<int,Position> (numero_deplacement,Position(0,0)));
	
}


Gaulois::Gaulois(char pSexe): Objet("Gaulois")
{
	
	age = 1;
	sexe = pSexe;
	ancienNumLigne = 0;
	ancienNumColonne = 0;
	
	if(pSexe == 'F')
	{
		nom = "Gauloise";
	}
	
	nb_gaulois++;
	
	id_gaulois = nb_gaulois;
	
	setNom(nom+" "+to_string(nb_gaulois));
	
	setType("Gaulois");
	
	nb_deplacements = 0 ;
	int numero_deplacement = nb_deplacements ;
	
	
	coordonnees_par_ou_passait_gaulois.insert(pair<int,Position> (numero_deplacement,Position(0,0)));
	
	
	
}


Gaulois::Gaulois(char pSexe, unsigned pNumero_ligne, unsigned pNumero_colonne) : 
Objet("Gaulois",pNumero_ligne,pNumero_colonne)
{
	age = 1 ;
	sexe = pSexe;
	
	ancienNumLigne = 0;
	ancienNumColonne = 0;
	
	if(pSexe == 'F')
	{
		nom = "Gauloise";
	}
	
	
	nb_gaulois++;
	
	id_gaulois = nb_gaulois;
	
	setNom(nom+" "+to_string(nb_gaulois));
	
	setType("Gaulois");
	
	nb_deplacements = 0;
	
	int numero_deplacement = nb_deplacements ;
	
	coordonnees_par_ou_passait_gaulois.insert( pair<int,Position> (numero_deplacement,Position(0,0)) );
	
	
	nb_deplacements++;
	
	numero_deplacement = nb_deplacements ;
	
	coordonnees_par_ou_passait_gaulois.insert(pair<int,Position> ( numero_deplacement,Position(pNumero_ligne,pNumero_colonne)) );
	
	
}


//Setters
void Gaulois::seDeplacer(unsigned pNumero_ligne, unsigned pNumero_colonne)
{
	ancienNumLigne = numero_ligne;
	ancienNumColonne = numero_colonne;
	
	
	numero_ligne = pNumero_ligne;
	numero_colonne = pNumero_colonne;
	
	nb_deplacements++;
	
	int numero_deplacement = nb_deplacements ;
	
	coordonnees_par_ou_passait_gaulois.insert(pair<int,Position> (numero_deplacement,Position(pNumero_ligne,pNumero_colonne)));
	
	
	
}

//Retourne une description textuelle de gaulois
string Gaulois::toString()
{

	stringstream ss;
	
	ss << "id_objet:";
	ss << id_objet;
	ss << "\n";
	
	ss << "id_gaulois:";
	ss << id_gaulois;
	ss << "\n";
	
	
	ss << nom;
	ss << "\n";
	
	ss << getAncienneLigne();
	ss << "x";
	ss << getAncienneColonne();
	
	ss << " >> ";
	
	ss << numero_ligne;
	ss << "x";
	ss << numero_colonne;
	ss << "\n";
	
	ss << "age:";
	ss << age;
	ss << "\n";

	return ss.str();
	
			
}

5


void Gaulois::setNom(string pNom)
{
	nom = pNom;
}



//Incrémente l'âge
void Gaulois::vieillir()
{
	age++;
}

unsigned Gaulois::getAncienneLigne()
{
	return ancienNumLigne;
}


unsigned Gaulois::getAncienneColonne()
{
	return ancienNumColonne;
}

unsigned Gaulois::getAge()
{
	return age;
}


int Gaulois::get_nb_gaulois_crees()
{
	return nb_gaulois;
}

string Gaulois::getDeplacements()
{
	stringstream ss;
	Position p;
	
	for (map<int,Position>::iterator it=coordonnees_par_ou_passait_gaulois.begin(); it != coordonnees_par_ou_passait_gaulois.end(); ++it)
	{
		p = it->second;
		
		
		ss << ";" << p.toString();
	}
    
	return ss.str();
}

int Gaulois::getIdGaulois()
{
	return id_gaulois;
}


Position Gaulois::getPosition_actuelle()
{
	map<int,Position>::iterator it = coordonnees_par_ou_passait_gaulois.end();
	
	Position position_actuelle = it->second;
	
	return position_actuelle;
	
	
	
}





