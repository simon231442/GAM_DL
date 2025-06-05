/*                                                                             *
 *                 ██████╗  █████╗ ███╗   ███╗     ██████╗ ██╗                 *
 *                ██╔════╝ ██╔══██╗████╗ ████║     ██╔══██╗██║                 *
 *                ██║  ███╗███████║██╔████╔██║     ██║  ██║██║                 *
 *                ██║   ██║██╔══██║██║╚██╔╝██║     ██║  ██║██║                 *
 *                ╚██████╔╝██║  ██║██║ ╚═╝ ██║     ██████╔╝███████╗            *
 *                 ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝     ╚═════╝ ╚══════╝            *
 *                                                                             *
 * ╭─────────────────────────────────────────────────────────────────────────╮ *
 * │  ** LEGENDARY ULTRA-MEGA AWESOME LIBRARY SDL3 C FOR RENDERS, MUSICS **  │ *
 * ├─────────────────────────────────────────────────────────────────────────┤ *
 * │  -> Nom      : GAM_DL_TextureLoad.c                                     │ *
 * │  -> Auteur   : lolilol                                                  │ *
 * │  -> Date     : 03/06/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#include "GAM_DL.h"

SDL_Texture	*GAM_DL_TextureLoad(t_GAM_Window *window, const char *filepath)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = SDL_LoadBMP(filepath);
	if (!surface)
		return (NULL);

	texture = SDL_CreateTextureFromSurface(window->renderer, surface);
	if (!texture)
	{
		SDL_FreeSurface(surface);
		return (NULL);
	}

	SDL_FreeSurface(surface);
	return (texture);
}


/*
t_GAM_Image	*GAM_DL_TextureLoad(t_GAM_Window *window, const char *filepath)
{
	t_GAM_Image	*gam_image;
	SDL_Surface	*surface;

	gam_image = malloc(sizeof(t_GAM_Image));
	if (!gam_image)
		return (NULL);	

	surface = SDL_LoadBMP(filepath);
	if (!surface)
		return (free(gam_image), NULL);
	
	gam_image->texture = SDL_CreateTextureFromSurface(window->renderer, surface);
	if (!gam_image->texture)
		return (SDL_DestroySurface(surface), free(gam_image), NULL);
	
	gam_image->width = surface->w;
	gam_image->height = surface->h;

	gam_image->shape.x = 0.0f;
    gam_image->shape.y = 0.0f;
    gam_image->shape.w = (float)surface->w;
    gam_image->shape.h = (float)surface->h;

	SDL_DestroySurface(surface);
	
	return(gam_image);
}
*/