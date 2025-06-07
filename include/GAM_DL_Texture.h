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

# define PATH_IMAGE_SIMPLE_GROUND "sprite/PATH_IMAGE_SIMPLE_GROUND.bmp"
# define OFFSET_IMAGE_SIMPLE_GROUND_y HEIGHT*2/3

# define PATH_MAP_SQUARE_0 "sprite/MapSquare_0.png"
# define PATH_MAP_SQUARE_1 "sprite/MapSquare_1.png"
# define PATH_MAP_SQUARE_2 "sprite/MapSquare_2.png"
# define PATH_MAP_SQUARE_3 "sprite/MapSquare_3.png"
# define PATH_MAP_SQUARE_4 "sprite/MapSquare_4.png"
# define PATH_MAP_SQUARE_5 "sprite/MapSquare_5.png"

# define PATH_IMAGE_CARACTER "sprite/Player.png"

//start game utils
enum
{
	GRAVITE_BAS,
	GRAVITE_HAUT,
	GRAVITE_G,
	GRAVITE_D
};

typedef struct repeatkey
{
	int key_up;
	int key_down;
	int key_right;
	int	key_left;
}t_rekey;

//end game utils

typedef	struct s_GAM_ImageSimple
{
	SDL_Texture	*texture;
	int			width;
	int			height;
	SDL_FRect	shape;
}	t_GAM_ImageSimple;

typedef struct s_GAM_ImageAnimated
{
	SDL_Texture	*texture[5];
	int			width;
	int			height;
	int			frames; // Number of frames in the animation
	SDL_FRect	shape;
} 	t_GAM_ImageAnimated;

typedef	struct s_GAM_Caracter
{
	SDL_Texture	*texture;
	SDL_FRect	shape;
	
}	t_GAM_Caracter;

typedef enum e_caracter_state
{
	WALK_LEFT,
	WALK_RIGHT,
}	t_caracter_state;


SDL_Texture	*GAM_DL_TextureLoad(t_GAM_Window *window, const char *filepath);
void 		GAM_DL_CoreLoadWorld(t_GAM_Window *gam_window);

#endif
	
