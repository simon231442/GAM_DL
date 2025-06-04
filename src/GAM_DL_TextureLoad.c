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

GAM_Image	*GAM_DL_TextureLoad(GAM_Window *window, const char *filepath)
{
	GAM_Image	*gam_image;
	SDL_Surface	*surface;

	gam_image = malloc(sizeof(GAM_Image));

	surface = SDL_LoadBMP(filePath);
	
	gam_image->texture = SDL_CreateTextureFromSurface(window->renderer, surface);
	gam_image->width = surface->w;
	gam_image->height = surface->h;

	gam_image->shape.x = 0.0f;
    gam_image->shape.y = 0.0f;
    gam_image->shape.w = (float)surface->w;
    gam_image->shape.h = (float)surface->h;

	SDL_DestroySurface(surface);
	
	return(gam_imag);
}
