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
 * │  -> Nom      : GAM_DL_Main.c                                            │ *
 * │  -> Auteur   : lolilol                                                  │ *
 * │  -> Date     : 03/06/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#include "GAM_DL.h"

int	GAM_DL_Main(void)
{
	GAM_Window	*gam_window;
	GAM_Image	*gam_image;
	SDL_Event	event;

	gam_window = GAM_DL_CoreWindowPop(GAM_DL_DEFAULT_WIDTH, GAM_DL_DEFAULT_HEIGHT);
	gam_image = GAM_DL_TextureLoad(gam_window, PATH_SPRITE_TEST);

	while (1)
	{
		while (SDL_PollEvent(&event))
			if (GAM_DL_EventHandle(&event))
				break;
		SDL_SetRenderDrawColor(gam_window->renderer, 0, 0, 0, 255);
		SDL_RenderClear(gam_window->renderer);

		SDL_RenderTexture(gam_window->renderer, gam_image->texture, NULL, &gam_image->shape);
		SDL_RenderPresent(gam_window->renderer);
		SDL_Delay(16);
	}
	SDL_Quit();
	return (0);
}
