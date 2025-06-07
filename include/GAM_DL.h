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
 * │  -> Nom      : GAM_DL.h                                                 │ *
 * │  -> Auteur   : tricaducee, SpartaCod, lolilol                           │ *
 * │  -> Date     : 03/06/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#ifndef GAM_DL_H
# define GAM_DL_H
# include <SDL3/SDL.h>
# include <SDL_image.h>
# include <stdlib.h>
# include <stdio.h>

# define GAM_DL_DEFAULT_WIDTH 800
# define GAM_DL_DEFAULT_HEIGHT 600
# define WIDTH GAM_DL_DEFAULT_WIDTH
# define HEIGHT GAM_DL_DEFAULT_HEIGHT

typedef struct s_GAM_Window t_GAM_Window;
typedef	struct s_GAM_ImageSimple t_GAM_ImageSimple;
typedef struct s_GAM_ImageAnimated t_GAM_ImageAnimated;
typedef struct s_GAM_Caracter t_GAM_Caracter;

typedef void (*func_ptr)(void);

typedef struct s_GAM_Window
{
	func_ptr				function[6];
	SDL_Window				*window;
	SDL_Renderer			*renderer;
	t_GAM_ImageSimple		ground;
	t_GAM_ImageAnimated		room;
	t_GAM_Caracter			caracter;
	int						game_state;
	int						quit;
	int						init_game;
	SDL_Event				event;
}	t_GAM_Window;

typedef enum e_GAM_GameState
{
	GAM_MENU,
	GAM_GAME,
	GAM_PAUSE
}	t_GAM_GameState;

//int				GAM_DL_Main(void);
int				GAM_DL_MainComplet(void);
void			GAM_DL_Game(void);
void			GAM_DL_Menu(void);
void			GAM_DL_Pause(void);
t_GAM_Window	*GAM_DL_CoreWindowPop(int width, int height);
void			ActivationGravite(void);

// Global window variable for cross-platform compatibility
extern t_GAM_Window *global_window;

# include "GAM_DL_Texture.h"
# include "GAM_DL_Event.h"

#endif
