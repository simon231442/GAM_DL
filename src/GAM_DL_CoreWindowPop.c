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
 * │  -> Nom      : GAM_DL_CoreWindowPop.c                                   │ *
 * │  -> Auteur   : lolilol                                                  │ *
 * │  -> Date     : 03/06/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#include "GAM_DL.h"


t_GAM_Window *GAM_DL_CoreWindowPop(int width, int height)
{
	t_GAM_Window	*gam_window;

	gam_window = malloc(sizeof(t_GAM_Window));
	if (!gam_window)
		return (NULL);

	gam_window->window = SDL_CreateWindow("GAM_DL Window",
											width, height,
											SDL_WINDOW_OPENGL);
	if (!gam_window->window)
		return (free(gam_window), NULL);
	gam_window->renderer = SDL_CreateRenderer(gam_window->window,
												"opengl");
	if (!gam_window->renderer)
		return (SDL_DestroyWindow(gam_window->window), free(gam_window), NULL);
	return (gam_window);
}
