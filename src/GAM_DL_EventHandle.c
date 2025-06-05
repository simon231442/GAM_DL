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
 * │  -> Nom      : GAM_DL_EventHandle.c                                     │ *
 * │  -> Auteur   : lolilol                                                  │ *
 * │  -> Date     : 04/06/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#include "GAM_DL.h"

int	GAM_DL_EventHandle(SDL_Event *event, t_GAM_Window *window)
{
	if (event->type == SDL_EVENT_QUIT)
		return (1);
	if (event->type == SDL_EVENT_KEY_DOWN && event->key.key == SDLK_ESCAPE)
		return (1);
	if (event->type == SDL_EVENT_KEY_DOWN && event->key.key == SDLK_RIGHT)
	{
		window->background_animated->shape.x -= 3;
		window->ground->shape.x -= 10;
		window->caracter->caracter_state = WALK_RIGHT;
	}
	if (event->type == SDL_EVENT_KEY_DOWN && event->key.key == SDLK_LEFT)
	{
		window->background_animated->shape.x += 3;
		window->ground->shape.x += 10;
		window->caracter->caracter_state = WALK_LEFT;
	}
	return (0);
}
