//GENGIS KODE

#include "GAM_DL.h"

//CREER STRUCTURE BOUTTON
t_button create_button(SDL_Renderer *renderer, const char *normal_path, const char *hover_path, SDL_FRect rect)
{
	t_button btn;
	SDL_Surface *surface;

	//TEXTURE NORMALE
	surface = IMG_Load(normal_path);
	if (surface == NULL)
	{
		printf("ERREUR : une image n a pas loader %s\n", normal_path);
		exit(1);
	}
	btn.texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_DestroySurface(surface);

	//TEXTURE SURVLOL
	surface = IMG_Load(hover_path);
	if (!surface)
	{
		printf("ERREUR : Image a pas charger : %s\n", hover_path);
		exit(1);
	}
	btn.hover_texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_DestroySurface(surface);

	btn.rect = rect;
	return (btn);
}
