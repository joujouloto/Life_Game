#include "Arbre.h"

#include <sstream>


int Arbre::nb_arbres = 0;

//Constructeurs
Arbre::Arbre(): Objet("Arbre")
{
	setType("Arbre");
	
	nb_arbres++;
	
	setNom("Arbre "+to_string(nb_arbres));
	
	age=1;
	
	
}


Arbre::Arbre(int pNumero_ligne, int pNumero_colonne) : Objet("Arbre")
{
	numero_ligne = pNumero_ligne;
	numero_colonne = pNumero_colonne;
	
	setType("Arbre");
	
	
	nb_arbres++;
	
	
	setNom("Arbre "+to_string(nb_arbres));
	
	age=1;
}

void Arbre::setNom(string pNom)
{
		nom = pNom;
}

string Arbre::toString()
{
	stringstream ss;
	
	ss << nom;
	ss << "\n";
	ss << to_string(numero_ligne);
	ss << "x";
	ss << to_string(numero_colonne);
	ss << "\nage:";
	ss << age;
	ss << "\n";

	return ss.str();
	
	
	
	
}