#include "Gaulois.h"

#include <sstream>

#include "constantes.h"

int Gaulois::nb_gaulois = 0;

//Constructeurs
Gaulois::Gaulois(): Objet("Gaulois")
{
	age = 1;
	sexe = 'M';
	ancienNumLigne = 0;
	ancienNumColonne = 0;
	
	nb_gaulois++;
	
	
	
	setNom(nom+" "+to_string(nb_gaulois));
	
	setType("Gaulois");
	
	
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
	
	nb_gaulois++;
	
	setNom(nom+" "+to_string(nb_gaulois));
	
	setType("Gaulois");
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
	
	
	nb_gaulois++;
	
	setNom(nom+" "+to_string(nb_gaulois));
	
	setType("Gaulois");
}


//Setters
void Gaulois::seDeplacer(unsigned pNumero_ligne, unsigned pNumero_colonne)
{
	ancienNumLigne = numero_ligne;
	ancienNumColonne = numero_colonne;
	
	
	numero_ligne = pNumero_ligne;
	numero_colonne = pNumero_colonne;
}



void Gaulois::seDeplacerEnHaut(_map grille)
{
	if( ne_deborde_pas_par_le_haut(this) 
			&& case_en_haut_n_est_pas_occupee_par_un_arbre(grille , this) )
	{
		seDeplacer(numero_ligne,numero_colonne-1);
	}
}

void Gaulois::seDeplacerEnBas(_map grille, int NB_COLONNES)
{
	if( ne_deborde_pas_par_le_bas(this,NB_COLONNES) 
		&& case_en_bas_n_est_pas_occupee_par_un_arbre (grille , this) )
	{
		seDeplacer(numero_ligne,numero_colonne+1);
	}
	
}

void Gaulois::seDeplacerA_Gauche(_map grille)
{
	
	if( ne_deborde_pas_par_la_gauche(this) 
			&& case_a_gauche_n_est_pas_occupee_par_un_arbre (grille , this))
	{
		seDeplacer(numero_ligne-1,numero_colonne);
	}
	
	
	
	
	
}

void Gaulois::seDeplacerA_Droite(_map grille, int NB_LIGNES)
{
	
	
	if( ne_deborde_pas_par_la_droite(this,NB_LIGNES) 
			&& case_a_droite_n_est_pas_occupee_par_un_arbre (grille , this)  )
	{
		seDeplacer(numero_ligne+1,numero_colonne);
	}
	
	
}

//Retourne une description textuelle de gaulois
string Gaulois::toString()
{

	stringstream ss;
	
	ss << nom;
	ss << "\n";
	ss << getAncienneLigne();
	ss << "x";
	ss << getAncienneColonne();
	ss << " >> ";
	ss << numero_ligne;
	ss << "x";
	ss << numero_colonne;
	ss << " ";
	ss << "\nage:";
	ss << age;

	return ss.str();
	
	/*
	return " "+nom+"\n"+
	" "+to_string(getAncienneLigne())+"x"+to_string(getAncienneColonne())+
	" >> "+
	to_string(numero_ligne)+"x"+to_string(numero_colonne)+
	" age: "+to_string(age)/*
	"  || sexe: "+sexe+*/
	;
	
	
			
}

void Gaulois::retournerAsonAnciennePosition()
{
	numero_ligne = ancienNumLigne;
	numero_colonne = ancienNumColonne;
}


void Gaulois::seDeplacerAleatoirement(_map grille, int NB_LIGNES, int NB_COLONNES)
{
	random_device rd;
	
	mt19937 gen(rd());
	
	int deplacement = 0 ;
	
	 
	uniform_int_distribution<> dis(1, 4);//uniform distribution between 1 and 4 
	 
	
	deplacement = dis(gen);
			
			
			
	if(deplacement==gauche)
	{
		
		this->seDeplacerA_Gauche(grille);
		

	}else if(deplacement==droite)
	{

		this->seDeplacerA_Droite(grille, NB_LIGNES);
		
	}else if(deplacement==haut)
	{
		this->seDeplacerEnHaut(grille);
		
	}else if(deplacement==bas)
	{
		this->seDeplacerEnBas(grille, NB_COLONNES);	
	}
}

void Gaulois::setNom(string pNom)
{
	nom = pNom;
}



//Incrémente l'âge
void Gaulois::vieillir()
{
	age++;
}

unsigned Gaulois::getAncienneLigne()
{
	return ancienNumLigne;
}


unsigned Gaulois::getAncienneColonne()
{
	return ancienNumColonne;
}

unsigned Gaulois::getAge()
{
	return age;
}




