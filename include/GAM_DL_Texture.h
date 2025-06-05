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
 * │  -> Nom      : GAM_DL_Texture.h                                         │ *
 * │  -> Auteur   : tricaducee, SpartaCod, lolilol                           │ *
 * │  -> Date     : 03/06/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#ifndef GAM_DL_TEXTURE_H
# define GAM_DL_TEXTURE_H

# define PATH_SPRITE_TEST "sprite/colored_spiral.bmp" 

# define PATH_IMAGE_SIMPLE_GROUND
# define OFFSET_IMAGE_SIMPLE_GROUND_y HEIGHT*2/3

# define PATH_IMAGE_ANIMATED0 "sprite/PATH_IMAGE_ANIMATED0.bmp"
# define PATH_IMAGE_ANIMATED1 "sprite/PATH_IMAGE_ANIMATED1.bmp"
# define PATH_IMAGE_ANIMATED2 "sprite/PATH_IMAGE_ANIMATED2.bmp"

# define PATH_IMAGE_CARACTER_WALK_LEFT0 "sprite/PATH_IMAGE_CARACTER_WALK_LEFT0.bmp"
# define PATH_IMAGE_CARACTER_WALK_LEFT1 "sprite/PATH_IMAGE_CARACTER_WALK_LEFT1.bmp"
# define PATH_IMAGE_CARACTER_WALK_LEFT2 "sprite/PATH_IMAGE_CARACTER_WALK_LEFT2.bmp"
# define OFFSET_IMAGE_CARACTER HEIGHT*1/3

# define PATH_IMAGE_CARACTER_WALK_RIGHT0 "sprite/PATH_IMAGE_CARACTER_WALK_RIGHT0.bmp"
# define PATH_IMAGE_CARACTER_WALK_RIGHT1 "sprite/PATH_IMAGE_CARACTER_WALK_RIGHT1.bmp"
# define PATH_IMAGE_CARACTER_WALK_RIGHT2 "sprite/PATH_IMAGE_CARACTER_WALK_RIGHT2.bmp"



typedef	struct s_GAM_ImageSimple
{
	SDL_Texture	*texture;
	int			width;
	int			height;
	SDL_FRect	shape;
}	t_GAM_ImageSimple;

typedef struct s_GAM_ImageAnimated
{
	SDL_Texture	**texture;
	int			width;
	int			height;
	SDL_FRect	shape;
} 	t_GAM_ImageAnimated;

typedef	struct s_GAM_caracter
{
	SDL_Texture	***texture;
	int			width;
	int			height;
	SDL_FRect	shape;
	int			caracter_state;
}	t_GAM_Caracter;

typedef enum e_caracter_state
{
	WALK_LEFT,
	WALK_RIGHT,
};


SDL_Texture	*GAM_DL_TextureLoad(t_GAM_Window *window, const char *filepath);
void 		GAM_DL_CoreLoadWorld(t_GAM_Window *gam_window);

#endif
	
