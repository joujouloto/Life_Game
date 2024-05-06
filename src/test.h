#ifndef TEST_H
#define TEST_H

void tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE);

void tester_que_les_objets_se_deplacent_sans_collision(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE);

void tester_que_les_objets_se_deplacent_bien(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE, unsigned TOURS );

void tester_qu_il_y_a_bien_le_meme_nombre_d_elements_apres_chaque_tour();


void tester_la_SDL(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE);


void tester_le_nombre_de_morts(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE, unsigned TOURS, unsigned age_de_deces_probable);

void tester();





#endif