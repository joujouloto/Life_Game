/*
	Nom du fichier: Constantes.h


*/

#ifndef CONSTANTES_H
#define CONSTANTES_H

enum type_Objet { type_Arbre = 1, type_Gaulois = 2, type_Gauloise = 3 };

enum type_Deplacement { gauche = 1, droite = 2, haut = 3, bas = 4};

enum sexe_gaulois { homme = 'M' , femme = 'F'};

bool ne_deborde_pas_par_la_gauche(shared_ptr<Gaulois> gaulois_ou_gauloise);
bool ne_deborde_pas_par_la_droite(shared_ptr<Gaulois> gaulois_ou_gauloise, int nb_lignes);
bool ne_deborde_pas_par_le_haut(shared_ptr<Gaulois> gaulois_ou_gauloise);
bool ne_deborde_pas_par_le_bas(shared_ptr<Gaulois> gaulois_ou_gauloise, int nb_cases_par_ligne);

bool case_a_gauche_n_est_pas_occupee_par_un_arbre (_map ancienne_grille , shared_ptr<Gaulois> gaulois_ou_gauloise);
bool case_a_droite_n_est_pas_occupee_par_un_arbre (_map  ancienne_grille , shared_ptr<Gaulois> gaulois_ou_gauloise);
bool case_en_haut_n_est_pas_occupee_par_un_arbre ( _map ancienne_grille , shared_ptr<Gaulois> gaulois_ou_gauloise);
bool case_en_bas_n_est_pas_occupee_par_un_arbre (_map  ancienne_grille , shared_ptr<Gaulois> gaulois_ou_gauloise);


#endif