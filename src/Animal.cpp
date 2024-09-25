#include "Animal.h"


#include <string>

int Animal::nb_animaux = 0;

Animal::Animal(): Objet("Animal")
{
	
	setType("Animal");
	
	
	nb_animaux++;
	
	id_animal = nb_animaux;
	
	setNom("Animal "+to_string(id_animal));
	
}

Animal::Animal(int pNumero_ligne, int pNumero_colonne) : Objet("Animal",pNumero_ligne, pNumero_colonne)
{
	
	setType("Animal");
	
	
	nb_animaux++;
	
	id_animal = nb_animaux;
	
	setNom("Animal "+to_string(id_animal));
	
}


void Animal::seDeplacer(int pNumero_ligne, int pNumero_colonne, _map grille)
{
	Position ancienne_position = this->getPosition();
	Position nouvelle_position = Position(pNumero_ligne,pNumero_colonne);
	
	shared_ptr<Animal> animal = make_shared<Animal>(*this);
	
	grille->erase(ancienne_position);
	
	grille->insert( { nouvelle_position, animal} );
	
	setPosition(nouvelle_position);
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





