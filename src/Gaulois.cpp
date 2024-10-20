#include "Gaulois.h"

#include <sstream>

#include <map>


using _map = shared_ptr<map<Position,shared_ptr<Objet>>>;

enum sexe_gaulois { homme = 'M' , femme = 'F'};

int Gaulois::nb_gaulois = 0;

//Constructeurs
Gaulois::Gaulois(): Objet("Gaulois")
{
	age = 1;
	sexe = 'M';
	
	
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


Gaulois::Gaulois(char pSexe, int pNumero_ligne, int pNumero_colonne) : 
Objet("Gaulois",pNumero_ligne,pNumero_colonne)
{
	age = 1 ;
	sexe = pSexe;
	
	
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


/*
	Verifier que l'on donne pas une position d'un autre gaulois

*/



//Setters
void Gaulois::seDeplacer(int pNumero_ligne, int pNumero_colonne, _map grille)
{
	Position ancienne_position = this->getPosition();
	Position nouvelle_position = Position(pNumero_ligne,pNumero_colonne);
	
	
	if ( grille->find(nouvelle_position) == grille->end())
	{
		setPosition(nouvelle_position);
	
		nb_deplacements++;
		
		int numero_deplacement = nb_deplacements ;
		
		coordonnees_par_ou_passait_gaulois.insert(pair<int,Position> (numero_deplacement,nouvelle_position));
		
		shared_ptr<Gaulois> gaulois = make_shared<Gaulois>(*this);
		
	
		/*
		
			Mettre condition/test comme quoi la nouvelle position n'est pas occupée
		
		*/
		
		grille->erase(ancienne_position);
		
		
		
		grille->insert( { nouvelle_position, gaulois} );
	}
	
}

void Gaulois::seDeplacer(Position nouvelle_position, _map grille)
{
	
	Position ancienne_position = this->getPosition();
	
	
	if ( grille->find(nouvelle_position) == grille->end())
	{
		//Grand if
		//-----------------------------------------------------------------------------
		
		setPosition(nouvelle_position);
		
		nb_deplacements++;
		
		int numero_deplacement = nb_deplacements ;
		
		coordonnees_par_ou_passait_gaulois.insert(pair<int,Position> (numero_deplacement,nouvelle_position));
		
		shared_ptr<Gaulois> gaulois = make_shared<Gaulois>(*this);
		
		
		/*
			Mettre condition/test comme quoi la nouvelle position n'est pas occupée
		
		*/
		
		
		
		
		grille->erase(ancienne_position);
		
		grille->insert( { nouvelle_position, gaulois} );
		
		//Fin grand if---------------------------------------------------------------------------------
	}
	
	
	
	
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
	
	ss << this->getDeplacements();
	ss << "\n";
	
	ss << "age:";
	ss << age;
	ss << "\n";

	return ss.str();
	
			
}

//Incrémente l'âge
void Gaulois::vieillir()
{
	age++;
}


int Gaulois::getAge()
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







