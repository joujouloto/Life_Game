#include "Gaulois.h"


//Constructeurs
Gaulois::Gaulois(): Objet("Gaulois")
{
	age = 1;
	sexe = 'M';
	ancienNumLigne = 0;
	ancienNumColonne = 0;
}


Gaulois::Gaulois(char pSexe): Objet("Gaulois")
{
	
	age = 1;
	sexe = pSexe;
	ancienNumLigne = 0;
	ancienNumColonne = 0;
	
	if(pSexe == 'F')
	{
		nom = "Gauloise";
	}
}


Gaulois::Gaulois(char pSexe, unsigned pNumero_ligne, unsigned pNumero_colonne) : 
Objet("Gaulois",pNumero_ligne,pNumero_colonne)
{
	age = 1 ;
	sexe = pSexe;
	
	ancienNumLigne = 0;
	ancienNumColonne = 0;
	
	if(pSexe == 'F')
	{
		nom = "Gauloise";
	}
}


//Setters
void Gaulois::setPosition(unsigned pNumero_ligne, unsigned pNumero_colonne)
{
	ancienNumLigne = numero_ligne;
	ancienNumColonne = numero_colonne;
	
	
	numero_ligne = pNumero_ligne;
	numero_colonne = pNumero_colonne;
}



void Gaulois::seDeplacerEnHaut()
{
	setPosition(numero_ligne,numero_colonne-1);
}

void Gaulois::seDeplacerEnBas()
{
	setPosition(numero_ligne,numero_colonne+1);
}

void Gaulois::seDeplacerA_Gauche()
{
	setPosition(numero_ligne-1,numero_colonne);
}

void Gaulois::seDeplacerA_Droite()
{
	setPosition(numero_ligne+1,numero_colonne);
}

//Retourne une description textuelle de gaulois
string Gaulois::toString()
{
	return " "+nom+
	"\n courant: "+to_string(numero_ligne)+"x"+to_string(numero_colonne)+/*+
	"  || age: "+to_string(age)+
	"  || sexe: "+sexe+*/
	"\n ancien: "+to_string(ancienNumLigne)+"x"+to_string(ancienNumColonne)
	;
}

void Gaulois::retournerAsonAnciennePosition()
{
	
	
	numero_ligne = ancienNumLigne;
	numero_colonne = ancienNumColonne;
}

//Incrémente l'âge
void Gaulois::vieillir()
{
	age++;
}
