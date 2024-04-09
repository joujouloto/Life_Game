#include "Arbre.h"



//Constructeurs
Arbre::Arbre(): Objet("Arbre")
{
	
}


Arbre::Arbre(int pNumero_ligne, int pNumero_colonne) : Objet("Arbre")
{
	numero_ligne = pNumero_ligne;
	numero_colonne = pNumero_colonne;
}

string Arbre::toString()
{
	return "Nom: "+nom+
	" || numero_ligne: "+to_string(numero_ligne)+
	" || numero_colonne: "+to_string(numero_colonne)
	; 
}