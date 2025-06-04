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

#define GAM_DL_DEFAULT_WIDTH 800
#define GAM_DL_DEFAULT_HEIGHT 600

typedef struct s_GAM_Window t_GAM_Window;
typedef struct s_GAM_Image t_GAM_Image;

typedef struct s_GAM_Window
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}	t_GAM_Window;

t_GAM_Window	*GAM_DL_CoreWindowPop(int width, int height);

# include "GAM_DL_Texture.h"
# include "GAM_DL_Event.h"

#endif
