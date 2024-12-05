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

    win = SDL_CreateWindow("Jeu de la vie!", 200, 50, 1300, 800, SDL_WINDOW_SHOWN);
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
	
	SDL_Event ev;
	
	bool isRunning = true;
	
	
	
	while(isRunning)
	{
		
		this_thread::sleep_for(chrono::milliseconds(800));
		//------------------------------------------------
		
		
		
		jeu.faire_deplacer_elements();
		
		jeu.faire_manger_gaulois();
		
		jeu.faire_vieillir_population_gauloise();
		
		
		//------------------------------------------------
		afficher_grille_SDL(renderer,jeu.getGrille());
		SDL_RenderClear(renderer);
		
		
		while( SDL_PollEvent( &ev ) != 0 ) 
		{
			switch (ev.type) 
			{
				case SDL_QUIT:
				isRunning = false;
					
			}
		
		}
	}
	
	fermeture_SDL(win,renderer);
	
}

void afficher_grille_SDL(SDL_Renderer *renderer, _grille grille )
{
	shared_ptr<Gaulois> gaulois;
	Position position ;
	
	
    SDL_Rect single_rect;
	
	/*int nb_lignes = 14 ;
	int nb_cases_par_ligne = 18;*/
	
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
	
	
	
	int pos_x = 40;
	int pos_y = 40;
	int espace = 20 ;
	
	
	 for( set < shared_ptr<Objet> > ::iterator it = grille->begin(); it !=grille->end() ; it++ )
	 {
		 single_rect.x =  (pos_x + espace) * (*it)->getPosition().getAbscisse() ;
		 single_rect.y = (pos_y + espace) * (*it)->getPosition().getOrdonnee();
		 
		 
		 
		if((*it)->getType()=="Arbre")
		{
					SDL_RenderCopy(renderer, texture_arbre, NULL, &single_rect);
		}
		else if((*it)->getType()=="Gaulois")	
			{
				
				
				gaulois = dynamic_pointer_cast<Gaulois> (*it);
					
					
				cout << gaulois->getPosition().toString() << endl;
					
				if(gaulois->getSexe()=='M')
				{
					SDL_RenderCopy(renderer, texture_gaulois, NULL, &single_rect);
				}
				else
				{
					SDL_RenderCopy(renderer, texture_gauloise, NULL, &single_rect);
				}
		
		}else if((*it)->getType()=="Animal")
		{
			cout << (*it)->getPosition().toString() << endl;
			
			SDL_RenderCopy(renderer, texture_animal, NULL, &single_rect);
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

