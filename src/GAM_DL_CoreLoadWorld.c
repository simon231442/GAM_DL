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
	gam_window->background_animated->texture[0] = GAM_DL_TextureLoad(PATH_MAP_SQUARE_0);
	gam_window->background_animated->texture[1] = GAM_DL_TextureLoad(PATH_MAP_SQUARE_1);
	gam_window->background_animated->texture[2] = GAM_DL_TextureLoad(PATH_MAP_SQUARE_2);
	gam_window->background_animated->texture[3] = GAM_DL_TextureLoad(PATH_MAP_SQUARE_3);
	gam_window->background_animated->texture[4] = GAM_DL_TextureLoad(PATH_MAP_SQUARE_4);
	gam_window->background_animated->texture[5] = GAM_DL_TextureLoad(PATH_MAP_SQUARE_5);
	
	gam_window->background_animated->shape.x = 0;
	gam_window->background_animated->shape.y = 0;
	gam_window->background_animated->shape.w = WIDTH;
	gam_window->background_animated->shape.h = HEIGHT;

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