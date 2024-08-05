/*
	Nom du fichier: Constantes.h


*/

#ifndef CONSTANTES_H
#define CONSTANTES_H

enum type_Objet { type_Arbre, type_Gaulois, type_Gauloise};

enum type_Deplacement { gauche, droite, haut, bas};


bool ne_deborde_pas_par_la_gauche(shared_ptr<Gaulois> gaulois_ou_gauloise);
bool ne_deborde_pas_par_la_droite(shared_ptr<Gaulois> gaulois_ou_gauloise, int nb_lignes);
bool ne_deborde_pas_par_le_haut(shared_ptr<Gaulois> gaulois_ou_gauloise);
bool ne_deborde_pas_par_le_bas(shared_ptr<Gaulois> gaulois_ou_gauloise, int nb_cases_par_ligne);

bool case_a_gauche_n_est_pas_occupee_par_un_arbre (_map ancienne_grille , shared_ptr<Gaulois> gaulois_ou_gauloise);
bool case_a_droite_n_est_pas_occupee_par_un_arbre (_map  ancienne_grille , shared_ptr<Gaulois> gaulois_ou_gauloise);
bool case_en_haut_n_est_pas_occupee_par_un_arbre ( _map ancienne_grille , shared_ptr<Gaulois> gaulois_ou_gauloise);
bool case_en_bas_n_est_pas_occupee_par_un_arbre (_map  ancienne_grille , shared_ptr<Gaulois> gaulois_ou_gauloise);


#endif