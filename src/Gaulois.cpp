#include "Gaulois.h"

#include <sstream>

#include <set>

#include <memory>



enum sexe_gaulois { homme = 'M' , femme = 'F'};

int Gaulois::nb_gaulois = 0;

//Constructeurs
Gaulois::Gaulois(): Objet("Gaulois")
{
	age = 1;
	sexe = 'M';
	nb_animaux_manges = 0;
	
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
	nb_animaux_manges = 0;
	
	age = 1;
	sexe = pSexe;
	
	if(pSexe == 'F')
	{
		nom = "Gauloise";
		
	}
	
	setType("Gaulois");
	
	
	nb_gaulois++;
	
	id_gaulois = nb_gaulois;
	
	setNom(nom+" "+to_string(nb_gaulois));
	
	
	
	nb_deplacements = 0 ;
	int numero_deplacement = nb_deplacements ;
	
	
	coordonnees_par_ou_passait_gaulois.insert(pair<int,Position> (numero_deplacement,Position(0,0)));
	
	
	
}


Gaulois::Gaulois(char pSexe, int pNumero_ligne, int pNumero_colonne) : 
Objet("Gaulois",pNumero_ligne,pNumero_colonne)
{
	age = 1 ;
	sexe = pSexe;
	
	nb_animaux_manges = 0;
	
	
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

char Gaulois::getSexe()
{
	return sexe;
}




/*
	Verifier que l'on donne pas une position d'un autre gaulois

*/



//Setters




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
	
	ss << "animaux manges:";
	ss << this->getAnimauxManges();
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



int Gaulois::getIdGaulois()
{
	return id_gaulois;
}



void Gaulois::seDeplacer_aleatoirement(_map grille)
{
	random_device rd;
	mt19937 gen(rd());
	
	uniform_int_distribution<> dis(1, 4);//uniform distribution between 1 and 4
	
	int deplacement = dis(gen);
	
	
	if(deplacement == gauche)
	{
		this->seDeplacer_a_gauche(grille);
	}
	
	else if(deplacement == droite)
	{
		this->seDeplacer_a_droite(grille);
		
	}
	
	else if( deplacement == haut )
	{
		this->seDeplacer_en_haut(grille);
		
	}
	
	else if( deplacement== bas )
	{
		this->seDeplacer_en_bas(grille);
	}
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

string Gaulois::getAnimauxManges()
{
	stringstream ss;
	shared_ptr<Animal> animal;
	
	
	for(map< int, shared_ptr<Animal> >::iterator it=animaux_manges.begin(); it!=animaux_manges.end(); it++)
	{
		animal=it->second;
		
		ss << ";" << animal->getNom();
	}
	
	
	return ss.str();
}

int Gaulois::getNbAnimauxManges()
{
	return nb_animaux_manges;
}


void Gaulois::seDeplacer(int pNumero_ligne, int pNumero_colonne, _map grille)
{
	Position nouvelle_position = Position(pNumero_ligne,pNumero_colonne);
	
	this->seDeplacer(nouvelle_position,grille);
	
}

void Gaulois::seDeplacer(Position nouvelle_position, _map grille)
{
	
	set<Position,shared_ptr<Objet>>::iterator it;
	
		
	if(!estOccupe(nouvelle_position, grille))
	{
		setPosition(nouvelle_position);
	
		nb_deplacements++;
		
		int numero_deplacement = nb_deplacements ;
		
		coordonnees_par_ou_passait_gaulois.insert(pair<int,Position> (numero_deplacement,nouvelle_position));
	}
	
	
	
}

void Gaulois::seDeplacer_a_gauche(_map grille)
{
	
	Position position_a_gauche = this->getPosition().a_gauche();
	this->seDeplacer(position_a_gauche,grille);
}

void Gaulois::seDeplacer_a_droite(_map grille)
{
	Position position_a_droite = this->getPosition().a_droite();
	this->seDeplacer(position_a_droite,grille);
}

void Gaulois::seDeplacer_en_haut(_map grille)
{
	Position position_en_haut = this->getPosition().en_haut();
	this->seDeplacer(position_en_haut,grille);
}

void Gaulois::seDeplacer_en_bas(_map grille)
{
	Position position_en_bas = this->getPosition().en_bas();
	this->seDeplacer(position_en_bas,grille);
}


bool Gaulois::estOccupe(Position position, _map grille)
{
	
	bool estOccupe = false;
	
	for( set < shared_ptr<Objet> > ::iterator it = grille->begin(); it !=grille->end() && !estOccupe ; it++ )
	{
		if( (*it)->getPosition() == position && this->getIdObjet() != (*it)->getIdObjet() )
		{
			estOccupe = true;
		}
	}
	
	return estOccupe;
	
}



void Gaulois::manger(_map grille)
{
	Position position_animal;
	shared_ptr<Objet> objet;
	shared_ptr<Animal> animal;
	
	bool a_mange = false;
	
	for( set < shared_ptr<Objet> > ::iterator it = grille->begin(); it !=grille->end() && !a_mange ; it++ )
	{
		position_animal = (*it)->getPosition();
		
		objet = *it;
		
		if( ( getPosition().a_droite() ==  position_animal || getPosition().a_gauche() == position_animal || getPosition().en_haut() == position_animal
	
		|| getPosition().en_bas() == position_animal) &&  objet->getType() == "Animal" )
		
		{
			animal = dynamic_pointer_cast<Animal> (objet);
			
			grille->erase(animal);
			a_mange = true;
			
			
			nb_animaux_manges++;
			animaux_manges.insert(pair<int,shared_ptr<Animal>> (nb_animaux_manges,animal) );
			
			
			
		}
	}
}



