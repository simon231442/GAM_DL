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

void GAM_DL_CoreLoadWorld(t_GAM_Window *gam_window)
{
	// Allouer les structures principales
	gam_window->ground = malloc(sizeof(t_GAM_ImageSimple));
	gam_window->background_animated = malloc(sizeof(t_GAM_ImageAnimated));
	//gam_window->caracter = malloc(sizeof(t_GAM_Caracter));
	
	// Allouer les tableaux de textures

	gam_window->background_animated->texture = malloc(3 * sizeof(SDL_Texture*));
	/*gam_window->caracter->texture = malloc(2 * sizeof(SDL_Texture**));
	gam_window->caracter->texture[0] = malloc(3 * sizeof(SDL_Texture*));
	gam_window->caracter->texture[1] = malloc(3 * sizeof(SDL_Texture*));
*/
	gam_window->ground->texture = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_SIMPLE_GROUND);

	gam_window->ground->shape.x = 0;
	gam_window->ground->shape.y = OFFSET_IMAGE_SIMPLE_GROUND_y;

	gam_window->ground->shape.w = WIDTH;
	gam_window->ground->shape.h = HEIGHT / 3;
	printf("hello\n");
	gam_window->background_animated->texture[0] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_ANIMATED0);
	gam_window->background_animated->texture[1] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_ANIMATED1);
	gam_window->background_animated->texture[2] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_ANIMATED2);
	
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
/*
	gam_window->caracter->texture[0][0] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_CARACTER_WALK_LEFT0);
	gam_window->caracter->texture[0][1] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_CARACTER_WALK_LEFT1);
	gam_window->caracter->texture[0][2] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_CARACTER_WALK_LEFT2);
	gam_window->caracter->texture[1][0] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_CARACTER_WALK_RIGHT0);
	gam_window->caracter->texture[1][1] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_CARACTER_WALK_RIGHT1);
	gam_window->caracter->texture[1][2] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_CARACTER_WALK_RIGHT2);
	gam_window->caracter->shape.x = WIDTH / 2 - gam_window->caracter->width / 2;
	gam_window->caracter->shape.y = OFFSET_IMAGE_CARACTER;
	gam_window->caracter->shape.w = WIDTH / 10;
	gam_window->caracter->shape.h = HEIGHT / 3;
	gam_window->caracter->caracter_state = WALK_RIGHT;
*/
}



//todo enum et tableau de pointeur