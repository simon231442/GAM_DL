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
 * │  -> Nom      : main.c                                                   │ *
 * │  -> Auteur   : lolilol                                                  │ *
 * │  -> Date     : 04/06/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#include "GAM_DL.h"
t_GAM_Window	*g_gam_window;

void	set_global(void)
{
	g_gam_window = GAM_DL_CoreWindowPop(WIDTH, HEIGHT);

	g_gam_window->function[0] = GAM_DL_Menu;
    g_gam_window->function[1] = GAM_DL_Game;
    g_gam_window->function[2] = GAM_DL_Pause;
	g_gam_window->quit = 0;

	GAM_DL_CoreLoadWorld();
}
#ifdef __ENSCRIPTON__

void MainLoop(void)
{
    fonction[GAME_GLOBAL_WINDOW->game_state]();
	if (g_gam_window->quit)
		emscripten_cancel_main_loop();
}

int main(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	set_global();
	emscripten_set_main_loop(MainLoop, 60, 1);
	
	SDL_Quit();
	return 0;
}

#else
int	main(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	set_global();
	while (!g_gam_window)
	{
		g_gam_window->function[g_gam_window->game_state]();
		SDL_Delay(16);
	}
	SDL_Quit();
	return 0;
}
#endif