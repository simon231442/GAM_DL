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
 * │  -> Nom      : GAM_DL_MainComplet.c                                     │ *
 * │  -> Auteur   : lolilol                                                  │ *
 * │  -> Date     : 05/06/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#include "GAM_DL.h"

int	GAM_DL_MainComplet(void)
{
	t_GAM_Window		*gam_window;
	int 				quit = 0;
	SDL_Event			event;
	SDL_FRect			size;
	int					i = 0;

	gam_window = GAM_DL_CoreWindowPop(GAM_DL_DEFAULT_WIDTH, GAM_DL_DEFAULT_HEIGHT);
	GAM_DL_CoreLoadWorld(gam_window);

	while (!quit)
	{
		while (SDL_PollEvent(&event))
			if (GAM_DL_EventHandle(&event, gam_window))
				quit = 1;

		SDL_SetRenderDrawColor(gam_window->renderer, 0, 0, 0, 255);
		SDL_RenderClear(gam_window->renderer);

		size.w = 2 * WIDTH;
		size.h = HEIGHT;

		SDL_RenderTexture(gam_window->renderer, gam_window->background_animated->texture[i % 3] , &size, &gam_window->ground->shape);
		size.w = WIDTH/6;
		size.h = HEIGHT/6;
		SDL_RenderTexture(gam_window->renderer, gam_window->caracter->texture[gam_window->caracter->caracter_state][i % 3], &size, &gam_window->caracter->shape);

		size.w = 2 * WIDTH;
		size.h = HEIGHT;
		
		SDL_RenderTexture(gam_window->renderer, gam_window->ground->texture, &size, &gam_window->ground->shape);

		SDL_RenderPresent(gam_window->renderer);
		SDL_Delay(16);
		i++;
	}
	SDL_DestroyRenderer(gam_window->renderer);
	SDL_DestroyWindow(gam_window->window);
	return 0;
}
