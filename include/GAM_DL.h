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
# include <stdlib.h>

# define GAM_DL_DEFAULT_WIDTH 800
# define GAM_DL_DEFAULT_HEIGHT 600

# define WIDTH GAM_DL_DEFAULT_WIDTH
# define HEIGHT GAM_DL_DEFAULT_HEIGHT

typedef struct s_GAM_Window t_GAM_Window;
typedef	struct s_GAM_ImageSimple t_GAM_ImageSimple;
typedef struct s_GAM_ImageAnimated t_GAM_ImageAnimated;
typedef struct s_GAM_caracter t_GAM_caracter;

typedef struct s_GAM_Window
{
	SDL_Window				*window;
	SDL_Renderer			*renderer;
	t_GAM_ImageSimple		*ground;
	t_GAM_ImageAnimated		*background_animated;
	t_GAM_caracter			*caracter;
}	t_GAM_Window;

//int				GAM_DL_Main(void);
int				GAM_DL_MainComplet(void);
t_GAM_Window	*GAM_DL_CoreWindowPop(int width, int height);

# include "GAM_DL_Texture.h"
# include "GAM_DL_Event.h"

#endif
