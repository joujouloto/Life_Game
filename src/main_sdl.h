#ifndef MAIN_SDL_H
#define MAIN_SDL_H

#include "Jeu_v2.h"

#include <SDL2/SDL.h>


void main_sdl();

void afficher_grille_SDL(SDL_Renderer *renderer, _grille grille );

void boucle_SDL(SDL_Renderer *renderer, Jeu_v2 jeu);


void fermeture_SDL(SDL_Window *win, SDL_Renderer *renderer);

#endif