#include "Objet.h"




//Constructeurs
Objet::Objet()
{
	nom = "Objet";
	numero_ligne = 0;
	numero_colonne = 0;
	
	type = "Objet";
}

Objet::Objet(string pNom)
{
	nom = pNom;
	numero_ligne = 0;
	numero_colonne = 0;
	
	type = "Objet";
}

Objet::Objet(unsigned pNumero_ligne, unsigned pNumero_colonne)
{
	nom = "Objet";
	numero_ligne = pNumero_ligne;
	numero_colonne = pNumero_colonne;
	
	type = "Objet";
}

Objet::Objet(string pNom, unsigned pNumero_ligne, unsigned pNumero_colonne)
{
	nom = pNom;
	numero_ligne = pNumero_ligne;
	numero_colonne = pNumero_colonne;
	
	type = "Objet";
}


//Getters
string Objet::getNom()
{
	return nom;
}

unsigned Objet::getNumeroLigne()
{
	return numero_ligne;
}

unsigned Objet::getNumeroColonne()
{
	return numero_colonne;
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


string Objet::getPosition()
{
	return to_string(numero_ligne)+"x"+to_string(numero_colonne);
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









