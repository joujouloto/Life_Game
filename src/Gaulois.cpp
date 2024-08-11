#include "Gaulois.h"


#include "constantes.h"



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
void Gaulois::seDeplacer(unsigned pNumero_ligne, unsigned pNumero_colonne)
{
	ancienNumLigne = numero_ligne;
	ancienNumColonne = numero_colonne;
	
	
	numero_ligne = pNumero_ligne;
	numero_colonne = pNumero_colonne;
}



void Gaulois::seDeplacerEnHaut()
{
	seDeplacer(numero_ligne,numero_colonne-1);
}

void Gaulois::seDeplacerEnBas()
{
	seDeplacer(numero_ligne,numero_colonne+1);
}

void Gaulois::seDeplacerA_Gauche()
{
	seDeplacer(numero_ligne-1,numero_colonne);
}

void Gaulois::seDeplacerA_Droite()
{
	seDeplacer(numero_ligne+1,numero_colonne);
}

//Retourne une description textuelle de gaulois
string Gaulois::toString()
{
	return " "+nom+
	"\n"+to_string(getAncienneLigne())+"x"+to_string(getAncienneColonne())+
	" >> "+
	to_string(numero_ligne)+"x"+to_string(numero_colonne)+
	"\nage: "+to_string(age)/*
	"  || sexe: "+sexe+*/
	+"\n";
	
	
			
}

void Gaulois::retournerAsonAnciennePosition()
{
	numero_ligne = ancienNumLigne;
	numero_colonne = ancienNumColonne;
}


void Gaulois::seDeplacerAleatoirement(_map grille)
{
	random_device rd;
	
	mt19937 gen(rd());
	
	int deplacement = 0 ;
	
	
	
	
	 
	uniform_int_distribution<> dis(1, 4);//uniform distribution between 1 and 4 
	 
	
	deplacement = dis(gen);
			
			
			
	if(deplacement==gauche)
	{
		if( ne_deborde_pas_par_la_gauche(this) 
			&& case_a_gauche_n_est_pas_occupee_par_un_arbre (grille , this))
		{
			this->seDeplacerA_Gauche();
		}/*
		else if( ne_deborde_pas_par_la_droite(this,grille->get_nb_lignes_jeu()) 
			&& case_a_droite_n_est_pas_occupee_par_un_arbre (grille , this))
		{
			this->seDeplacerA_Droite();
			
		}
		else if( ne_deborde_pas_par_le_haut(this) 
			&& case_en_haut_n_est_pas_occupee_par_un_arbre (grille , this) )
		{
			this->seDeplacerEnHaut();
			
		}
		else if( ne_deborde_pas_par_le_bas(this,grille->get_nb_colonnes_jeu()) 
			&& case_en_bas_n_est_pas_occupee_par_un_arbre (grille , this))
		{
			this->seDeplacerEnBas();
		}
		
		
		
		*/
	}/*else if(deplacement==droite)
	{
		
		if( ne_deborde_pas_par_la_droite(this,grille->get_nb_lignes_jeu()) 
			&& case_a_droite_n_est_pas_occupee_par_un_arbre (grille , this)  )
		{
			this->seDeplacerA_Droite();
			
		} 
		else if( ne_deborde_pas_par_la_gauche(this) 
			&& case_a_gauche_n_est_pas_occupee_par_un_arbre(grille , this)	)	
		{
			this->seDeplacerA_Gauche();
		}
		
		else if( ne_deborde_pas_par_le_haut(this) 
			&& case_en_haut_n_est_pas_occupee_par_un_arbre(grille , this) )
		{
			this->seDeplacerEnHaut();
			
		}
		else if( ne_deborde_pas_par_le_bas(this,grille->get_nb_colonnes_jeu()) 
			 && case_en_bas_n_est_pas_occupee_par_un_arbre (grille , this)	 	)			
		{
			this->seDeplacerEnBas();
		}
		
	}else if(deplacement==haut)
	{
		if( ne_deborde_pas_par_le_haut(this) 
			&& case_en_haut_n_est_pas_occupee_par_un_arbre(grille , this) )
		{
			this->seDeplacerEnHaut();
			
		}
		else if( ne_deborde_pas_par_le_bas(this,grille->get_nb_colonnes_jeu()) 
			&& case_en_bas_n_est_pas_occupee_par_un_arbre (grille , this) )
		{
			this->seDeplacerEnBas();
		}
		else if( ne_deborde_pas_par_la_droite(this,grille->get_nb_lignes_jeu()) 
			&& case_a_droite_n_est_pas_occupee_par_un_arbre (grille , this) )
		{
			this->seDeplacerA_Droite();
			
		} 
		else if( ne_deborde_pas_par_la_gauche(this) 
			&& case_a_gauche_n_est_pas_occupee_par_un_arbre(grille , this) )			
		{
			this->seDeplacerA_Gauche();
		}
		
	}else if(deplacement==bas)
	{
		if( ne_deborde_pas_par_le_bas(this,grille->get_nb_colonnes_jeu()) 
			&& case_en_bas_n_est_pas_occupee_par_un_arbre (grille , this) )
		{
			this->seDeplacerEnBas();
		}
		else if( ne_deborde_pas_par_le_haut(this) 
			&& case_en_haut_n_est_pas_occupee_par_un_arbre(grille , this) )
		{
			this->seDeplacerEnHaut();
			
		}
		else if( ne_deborde_pas_par_la_gauche(this) 
			&& case_a_gauche_n_est_pas_occupee_par_un_arbre(grille , this))
		{
			this->seDeplacerA_Gauche();
		}
		else if( ne_deborde_pas_par_la_droite(this,grille->get_nb_lignes_jeu()) 
			&& case_a_droite_n_est_pas_occupee_par_un_arbre (grille , this)  )
		{
			this->seDeplacerA_Droite();
			
		} 
	}*/
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




