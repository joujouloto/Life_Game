#include <iostream>
#include <SDL2/SDL.h>


#include "fonctions.h"

#include<chrono>
#include<thread>

using namespace std;


//affichage
shared_ptr<map<string,shared_ptr<Objet>>> initialisation_jeu(SDL_Renderer *renderer, shared_ptr<map<string,shared_ptr<Objet>>> grille, int nb_lignes, int nb_cases_par_ligne)
{
    SDL_Rect single_rect;
	
	/*int nb_lignes = 14 ;
	int nb_cases_par_ligne = 18;*/
	
	int pos_x = 40;
	int pos_y = 40;
	int espace = 20 ;
	
	single_rect.w = 50;
	single_rect.h = 50;
	
	single_rect.x = pos_x + espace ;
	single_rect.y = pos_y;
	
	//Images
		
	SDL_Surface * image_vide = SDL_LoadBMP("images/vide.bmp");
	
	SDL_Surface * image_arbre = SDL_LoadBMP("images/arbre.bmp");
	
	SDL_Surface * image_gaulois = SDL_LoadBMP("images/gaulois.bmp");
	
	SDL_Surface * image_gauloise = SDL_LoadBMP("images/gauloise.bmp");
		
		
	//Textures
	SDL_Texture * texture_vide = SDL_CreateTextureFromSurface(renderer, image_vide);
	
	SDL_Texture * texture_arbre = SDL_CreateTextureFromSurface(renderer, image_arbre);
	
	SDL_Texture * texture_gaulois = SDL_CreateTextureFromSurface(renderer, image_gaulois);
	
	SDL_Texture * texture_gauloise = SDL_CreateTextureFromSurface(renderer, image_gauloise);
	
	//169*221
	
	
	string numero_ligne_string = "0";
	string numero_colonne_string = "0";
	
	grille = construire_map(nb_lignes, nb_cases_par_ligne);
	
	map<string,shared_ptr<Objet>>::iterator it;
	
	
	for(int i = 1 ; i <= nb_lignes ; i++)
	{
		
		for( int j = 1 ; j <= nb_cases_par_ligne ; j++)
		{
			single_rect.x +=  pos_x + espace ;
			
			numero_ligne_string = to_string(i);
			numero_colonne_string = to_string(j);
			
			it = grille->find(numero_ligne_string+"x"+numero_colonne_string);
			
			if(it!=grille->end())
			{
				if(it->second->getNom()=="Arbre")
				{
					SDL_RenderCopy(renderer, texture_arbre, NULL, &single_rect);
				}
				else if(it->second->getNom()=="Gaulois")
				{
					SDL_RenderCopy(renderer, texture_gaulois, NULL, &single_rect);
				}
				else if(it->second->getNom()=="Gauloise")
				{
					SDL_RenderCopy(renderer, texture_gauloise, NULL, &single_rect);
				}
				
			}else
			{
				//SDL_SetRenderDrawColor(renderer, 50, 205, 50, 255);
				//SDL_RenderFillRect(renderer, &single_rect);
				SDL_RenderCopy(renderer, texture_vide, NULL, &single_rect);
			}
			
		}
		
		single_rect.y += pos_y + espace;
		single_rect.x =  pos_x + espace ;
	}
	
	SDL_RenderPresent(renderer);
	
	return grille;
	
	
}

shared_ptr<map<string,shared_ptr<Objet>>> faire_tourner_le_jeu(SDL_Renderer *renderer, shared_ptr<map<string,shared_ptr<Objet>>> grille, int nb_lignes, int nb_cases_par_ligne)
{
	SDL_RenderClear(renderer);
	
	
	SDL_Rect single_rect;
	
	/*int nb_lignes = 14 ;
	int nb_cases_par_ligne = 18;*/
	
	int pos_x = 40;
	int pos_y = 40;
	int espace = 20 ;
	
	single_rect.w = 50;
	single_rect.h = 50;
	
	single_rect.x = pos_x + espace ;
	single_rect.y = pos_y;
	
	//Images
		
	SDL_Surface * image_vide = SDL_LoadBMP("images/vide.bmp");
	
	SDL_Surface * image_arbre = SDL_LoadBMP("images/arbre.bmp");
	
	SDL_Surface * image_gaulois = SDL_LoadBMP("images/gaulois.bmp");
	
	SDL_Surface * image_gauloise = SDL_LoadBMP("images/gauloise.bmp");
		
		
	//Textures
	SDL_Texture * texture_vide = SDL_CreateTextureFromSurface(renderer, image_vide);
	
	SDL_Texture * texture_arbre = SDL_CreateTextureFromSurface(renderer, image_arbre);
	
	SDL_Texture * texture_gaulois = SDL_CreateTextureFromSurface(renderer, image_gaulois);
	
	SDL_Texture * texture_gauloise = SDL_CreateTextureFromSurface(renderer, image_gauloise);
	
	string numero_ligne_string = "0";
	string numero_colonne_string = "0";
	
	//grille = gaulois_se_deplacent( grille, nb_lignes, nb_cases_par_ligne);
	
	map<string,shared_ptr<Objet>>::iterator it;
	
	
	
	for(int i = 1 ; i <= nb_lignes ; i++)
	{
		
		for( int j = 1 ; j <= nb_cases_par_ligne ; j++)
		{
			single_rect.x +=  pos_x + espace ;
			
			numero_ligne_string = to_string(i);
			numero_colonne_string = to_string(j);
			
			it =  grille->find(numero_ligne_string+"x"+numero_colonne_string);
			
			
			if(it!=grille->end())
			{
				if(it->second->getNom()=="Arbre")
				{
					SDL_RenderCopy(renderer, texture_arbre, NULL, &single_rect);
				}
				else if(it->second->getNom()=="Gaulois")
				{
					SDL_RenderCopy(renderer, texture_gaulois, NULL, &single_rect);
				}
				else if(it->second->getNom()=="Gauloise")
				{
					SDL_RenderCopy(renderer, texture_gauloise, NULL, &single_rect);
				}
				
			}else
			{
				//SDL_SetRenderDrawColor(renderer, 50, 205, 50, 255);
				//SDL_RenderFillRect(renderer, &single_rect);
				SDL_RenderCopy(renderer, texture_vide, NULL, &single_rect);
			}
			
		}
		
		
		single_rect.y += pos_y + espace;
		single_rect.x =  pos_x + espace ;
	}
	
	SDL_RenderPresent(renderer);
	
	return grille;
}



void boucle_SDL(SDL_Renderer *renderer, shared_ptr<map<string,shared_ptr<Objet>>> grille, int nb_lignes, int nb_cases_par_ligne)
{
	
	SDL_Event ev;
	
	bool isRunning = true;
	
	
	
	while(isRunning)
	{
		this_thread::sleep_for(chrono::milliseconds(1500));
		grille = faire_tourner_le_jeu(renderer, grille, nb_lignes, nb_cases_par_ligne);
		
		
		while( SDL_PollEvent( &ev ) != 0 ) 
		{
			switch (ev.type) 
			{
				case SDL_QUIT:
				isRunning = false;
					
			}
		
		}
	}
}

void fermeture_SDL(SDL_Window *win, SDL_Renderer *renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
}



int initialisation_SDL(int nb_lignes, int nb_cases_par_ligne)
{
	SDL_Window *win;
    SDL_Renderer *renderer;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    win = SDL_CreateWindow("Jeu de la vie!", 200, 50, 1300, 900, SDL_WINDOW_SHOWN);
    if (win == NULL)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return EXIT_FAILURE;
    }
	
	shared_ptr<map<string,shared_ptr<Objet>>> grille ;
	
	grille = initialisation_jeu(renderer, grille, nb_lignes, nb_cases_par_ligne);
	
	boucle_SDL(renderer,grille, nb_lignes, nb_cases_par_ligne);
	fermeture_SDL(win,renderer);
	
	return EXIT_SUCCESS;
	
}








