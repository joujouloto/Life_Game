#include "Arbre.h"

int Arbre::nb_arbres = 0;

//Constructeurs
Arbre::Arbre(): Objet("Arbre")
{
	setType("Arbre");
	
	nb_arbres++;
	
	setNom("Arbre "+to_string(nb_arbres));
	
	
}


Arbre::Arbre(int pNumero_ligne, int pNumero_colonne) : Objet("Arbre")
{
	numero_ligne = pNumero_ligne;
	numero_colonne = pNumero_colonne;
	
	setType("Arbre");
	
	
	nb_arbres++;
	
	
	setNom("Arbre "+to_string(nb_arbres));
}

void Arbre::setNom(string pNom)
{
		nom = pNom;
}

string Arbre::toString()
{
	return " "+nom/*+
	" || numero_ligne: "+to_string(numero_ligne)+
	" || numero_colonne: "+to_string(numero_colonne)*/
	; 
}