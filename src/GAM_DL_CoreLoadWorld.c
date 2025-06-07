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
 * │  -> Nom      : GAM_DL_CoreLoadWorld.c                                   │ *
 * │  -> Auteur   : lolilol                                                  │ *
 * │  -> Date     : 05/06/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#include "GAM_DL.h"

void GAM_DL_CoreLoadWorld(void)
{
	gam_window->room->texture[0] = GAM_DL_TextureLoad(PATH_MAP_SQUARE_0);
	gam_window->room->texture[1] = GAM_DL_TextureLoad(PATH_MAP_SQUARE_1);
	gam_window->room->texture[2] = GAM_DL_TextureLoad(PATH_MAP_SQUARE_2);
	gam_window->room->texture[3] = GAM_DL_TextureLoad(PATH_MAP_SQUARE_3);
	gam_window->room->texture[4] = GAM_DL_TextureLoad(PATH_MAP_SQUARE_4);
	gam_window->room->texture[5] = GAM_DL_TextureLoad(PATH_MAP_SQUARE_5);

	
	gam_window->room->shape.x = 0;
	gam_window->room->shape.y = 0;
	gam_window->room->shape.w = WIDTH;
	gam_window->room->shape.h = HEIGHT;

	gam_window->caracter->texture = GAM_DL_TextureLoad(PATH_IMAGE_CARACTER);
	gam_window->caracter->shape.x = 100;
	gam_window->caracter->shape.y = 100;
	gam_window->caracter->shape.w = 64; // Width of the character sprite
	gam_window->caracter->shape.h = 64; // Height of the character sprite

	

	if( !gam_window->ground->texture || !gam_window->background_animated->texture[0] || !gam_window->background_animated->texture[1] || !gam_window->background_animated->texture[2])
	{
		fprintf(stderr, "Error loading textures\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("Textures loaded successfully\n");
	}
}