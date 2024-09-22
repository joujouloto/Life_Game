#include "Objet.h"


int Objet::nb_objets = 0;

//Constructeurs
Objet::Objet()
{
	nom = "Objet";
	position = Position(0,0);
	
	type = "Objet";
	
	nb_objets++;
	
	id_objet = nb_objets;
	
	
}

Objet::Objet(string pNom)
{
	nom = pNom;
	position = Position(0,0);
	
	type = "Objet";
	
	nb_objets++;
	
	id_objet = nb_objets;
}

Objet::Objet(unsigned pNumero_ligne, unsigned pNumero_colonne)
{
	nom = "Objet";
	
	
	type = "Objet";
	
	position = Position(pNumero_ligne,pNumero_colonne);
	
	nb_objets++;
	
	id_objet = nb_objets;
}

Objet::Objet(string pNom, unsigned pNumero_ligne, unsigned pNumero_colonne)
{
	nom = pNom;
	
	position = Position(pNumero_ligne,pNumero_colonne);
	
	type = "Objet";
	
	nb_objets++;
	
	id_objet = nb_objets;
	
	
	
}


//Getters
string Objet::getNom()
{
	return nom;
}

string Objet::getType()
{
	return type;
}
	
//Retourne une description de l'objet
/*string Objet:: toString()
{
	return "Nom: "+nom+
	" || numero_ligne: "+to_string(numero_ligne)+	
	" || numero_colonne: "+to_string(numero_colonne);
}*/


Position Objet::getPosition()
{
	return position;
}

int Objet::getNbObjets()
{
	return nb_objets;
}

int Objet::getIdObjet()
{
	return id_objet;
}

//Setters

void Objet::setType(string pType)
{
	type = pType;
}



//Destructeur
Objet::~Objet()
{
	
}









