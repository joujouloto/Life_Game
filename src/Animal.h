#ifndef _ANIMAL_H

#define _ANIMAL_H


#include <memory>

#include <map>

#include <sstream>

#include <string>


//----------------------------------------------------------------------------


#include "Objet.h"


//----------------------------------------------------------------------------


using _map = shared_ptr< map <Position,shared_ptr<Objet> > >;

using namespace std;


class Animal: public Objet
{
	public:
	Animal();
	Animal(int pNumero_ligne, int pNumero_colonne);
	
	void seDeplacer(int pNumero_ligne, int pNumero_colonne, _map grille);
	
	string toString();
	void setPosition();
	
	
	
	protected:
	static int nb_animaux;
	int id_animal;
	
};







#endif