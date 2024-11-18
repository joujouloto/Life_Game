#include <SDL2/SDL.h>

#include "Jeu_v2.h"

#include "main_sdl.h"

#include "Gaulois.h"

#include<chrono>
#include<thread>


void main_sdl()
{
	SDL_Window *win;
    SDL_Renderer *renderer;
	

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout <<  "SDL_Init Error: %s\n" <<  SDL_GetError() << endl;
        return;
    }

    win = SDL_CreateWindow("Jeu de la vie!", 200, 50, 1300, 900, SDL_WINDOW_SHOWN);
    if (win == NULL)
    {
       
		cout <<  "SDL_CreateWindow Error: %s\n" <<  SDL_GetError() << endl;
        return;
    }

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
    if (renderer == NULL)
    {
		cout <<  "SDL_CreateRenderer Error: %s\n" <<  SDL_GetError() << endl;
		
        SDL_DestroyWindow(win);
        SDL_Quit();
        return;
    }
	
	
	Jeu_v2 jeu;
	
	jeu.initialiser_grille();
	
	
	afficher_grille_SDL(renderer,jeu.getGrille());
	
	
	boucle_SDL(renderer,jeu);
	
	
	fermeture_SDL(win,renderer);
	
}

void afficher_grille_SDL(SDL_Renderer *renderer, _grille grille )
{
	shared_ptr<Gaulois> gaulois;
	
	
    SDL_Rect single_rect;
	
	/*int nb_lignes = 14 ;
	int nb_cases_par_ligne = 18;*/
	
	int origine_pos_x = 40;
	int origine_pos_y = 40;
	int espace = 20 ;
	
	single_rect.w = 50;
	single_rect.h = 50;
	
	//Images
		
	SDL_Surface * image_vide = SDL_LoadBMP("../../images/vide.bmp");
	
	SDL_Surface * image_arbre = SDL_LoadBMP("../../images/arbre.bmp");
	
	SDL_Surface * image_gaulois = SDL_LoadBMP("../../images/gaulois.bmp");
	
	SDL_Surface * image_gauloise = SDL_LoadBMP("../../images/gauloise.bmp");
	
	SDL_Surface * image_animal = SDL_LoadBMP("../../images/animal.bmp");
		
		
	//Textures
	SDL_Texture * texture_vide = SDL_CreateTextureFromSurface(renderer, image_vide);
	
	SDL_Texture * texture_arbre = SDL_CreateTextureFromSurface(renderer, image_arbre);
	
	SDL_Texture * texture_gaulois = SDL_CreateTextureFromSurface(renderer, image_gaulois);
	
	SDL_Texture * texture_gauloise = SDL_CreateTextureFromSurface(renderer, image_gauloise);
	
	SDL_Texture * texture_animal = SDL_CreateTextureFromSurface(renderer, image_animal);
	
	//169*221
	
	for (_it_grille it=grille->begin(); it != grille->end(); ++it)
	{
	
		single_rect.x =  origine_pos_x + it->second->getPosition().getAbscisse() * (single_rect.w + espace) ;
		single_rect.y = origine_pos_y + it->second->getPosition().getOrdonnee() * (single_rect.h + espace ) ; 
		
		
		
		
		if(it->second->getType()=="Arbre")
		{
					SDL_RenderCopy(renderer, texture_arbre, NULL, &single_rect);
		}
		else if(it->second->getType()=="Gaulois")	
			{
					
				gaulois = dynamic_pointer_cast<Gaulois> (it->second);
					
				if(gaulois->getSexe()=='M')
				{
					SDL_RenderCopy(renderer, texture_gaulois, NULL, &single_rect);
				}
				else
				{
					SDL_RenderCopy(renderer, texture_gauloise, NULL, &single_rect);
				}
		
		}else if(it->second->getType()=="Animal")
		{
			SDL_RenderCopy(renderer, texture_animal, NULL, &single_rect);
		}
		else
		{
			//SDL_SetRenderDrawColor(renderer, 50, 205, 50, 255);
			//SDL_RenderFillRect(renderer, &single_rect);
			SDL_RenderCopy(renderer, texture_vide, NULL, &single_rect);
		}
	}
	
	SDL_RenderPresent(renderer);
	
}


void fermeture_SDL(SDL_Window *win, SDL_Renderer *renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

void boucle_SDL(SDL_Renderer *renderer, Jeu_v2 jeu)
{
	
	SDL_Event ev;
	
	bool isRunning = true;
	
	
	
	while(isRunning)
	{
		this_thread::sleep_for(chrono::milliseconds(800));
		
		SDL_RenderClear(renderer);
		afficher_grille_SDL(renderer,jeu.getGrille());
		
		
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