#include "Animal.h"
#include "Objet.h"


#include <string>



using _map = shared_ptr< map < Position,shared_ptr<Objet>  > >;

int Animal::nb_animaux = 0;




Animal::Animal(): Objet("Animal")
{
	
	setType("Animal");
	
	
	nb_animaux++;
	
	id_animal = nb_animaux;
	
	setNom("Animal "+to_string(id_animal));
	
	
	nb_deplacements = 0;
	
	int numero_deplacement = nb_deplacements ;
	
	coordonnees_par_ou_passait_animal.insert( pair<int,Position> (numero_deplacement,Position(0,0)));
	
}

Animal::Animal(int pNumero_ligne, int pNumero_colonne) : Objet("Animal",pNumero_ligne, pNumero_colonne)
{
	
	setType("Animal");
	
	
	nb_animaux++;
	
	id_animal = nb_animaux;
	
	setNom("Animal "+to_string(id_animal));
	
	nb_deplacements = 0;
	
	int numero_deplacement = nb_deplacements ;
	
	coordonnees_par_ou_passait_animal.insert( pair<int,Position> (numero_deplacement,Position(0,0)) );
	
	
	nb_deplacements++;
	
	numero_deplacement = nb_deplacements ;
	
	coordonnees_par_ou_passait_animal.insert(pair<int,Position> ( numero_deplacement,Position(pNumero_ligne,pNumero_colonne)) );
	
}


string Animal::toString()
{

	stringstream ss;
	
	ss << "id_objet:";
	ss << id_objet;
	ss << "\n";
	
	ss << "id_animal:";
	ss << id_animal;
	ss << "\n";
	
	
	ss << nom;
	ss << "\n";
	


	return ss.str();
	
			
}


void Animal::seDeplacer_aleatoirement(_map grille)
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

string Animal::getDeplacements()
{
	stringstream ss;
	Position p;
	
	for (map<int,Position>::iterator it=coordonnees_par_ou_passait_animal.begin(); it != coordonnees_par_ou_passait_animal.end(); ++it)
	{
		p = it->second;
		
		
		ss << ";" << p.toString();
	}
    
	return ss.str();
}


void Animal::seDeplacer(int pNumero_ligne, int pNumero_colonne, _map grille)
{
	Position ancienne_position = this->getPosition();
	Position nouvelle_position = Position(pNumero_ligne,pNumero_colonne);
	
	shared_ptr<Animal> animal = make_shared<Animal>(*this);
	
	
	if ( grille->find(nouvelle_position) == grille->end())
	{
		setPosition(nouvelle_position);
	
		nb_deplacements++;
		
		int numero_deplacement = nb_deplacements ;
		
		coordonnees_par_ou_passait_animal.insert(pair<int,Position> (numero_deplacement,nouvelle_position));
		
		
	
		/*
		
			Mettre condition/test comme quoi la nouvelle position n'est pas occupée
		
		*/
		
		grille->erase(ancienne_position);
		
		
		
		grille->insert( { nouvelle_position, animal} );
	}
	
}

void Animal::seDeplacer(Position nouvelle_position, _map grille)
{
	
	Position ancienne_position = this->getPosition();
	
	shared_ptr<Animal> animal = make_shared<Animal>(*this);
	
	if ( grille->find(nouvelle_position) == grille->end())
	{
		//Grand if
		//-----------------------------------------------------------------------------
		
		setPosition(nouvelle_position);
		
		nb_deplacements++;
		
		int numero_deplacement = nb_deplacements ;
		
		coordonnees_par_ou_passait_animal.insert(pair<int,Position> (numero_deplacement,nouvelle_position));
		
		
		
		/*
			Mettre condition/test comme quoi la nouvelle position n'est pas occupée
		
		*/
		
		
		
		
		grille->erase(ancienne_position);
		
		grille->insert( { nouvelle_position, animal } );
		
		
		//Fin grand if---------------------------------------------------------------------------------
	}
}

void Animal::seDeplacer_a_gauche(_map grille)
{
	
	Position position_a_gauche = this->getPosition().a_gauche();
	this->seDeplacer(position_a_gauche,grille);
}

void Animal::seDeplacer_a_droite(_map grille)
{
	Position position_a_droite = this->getPosition().a_droite();
	this->seDeplacer(position_a_droite,grille);
}

void Animal::seDeplacer_en_haut(_map grille)
{
	Position position_en_haut = this->getPosition().en_haut();
	this->seDeplacer(position_en_haut,grille);
}

void Animal::seDeplacer_en_bas(_map grille)
{
	Position position_en_bas = this->getPosition().en_bas();
	this->seDeplacer(position_en_bas,grille);
}



