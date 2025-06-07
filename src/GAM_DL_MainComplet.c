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
#ifdef BUILD_WASM
#include <emscripten.h>
#endif

// Global variables for cross-platform compatibility
t_GAM_Window *global_window = NULL;
static int frame_counter = 0;

void main_loop_iteration(void)
{
	SDL_FRect size;
	SDL_Event event;
	
	// Event handling
	while (SDL_PollEvent(&event))
	{
		if (GAM_DL_EventHandle(&event, global_window))
		{
			global_window->quit = 1;
		}
	}
	
	// Check if we should quit
	if (global_window->quit)
	{
#ifdef BUILD_WASM
		emscripten_cancel_main_loop();
#endif
		return;
	}

	// Clear screen
	SDL_SetRenderDrawColor(global_window->renderer, 0, 0, 0, 255);
	SDL_RenderClear(global_window->renderer);

	// Render background animation
	size.w = 2 * WIDTH;
	size.h = HEIGHT;
	
	if (global_window->background_animated && global_window->background_animated->texture[0])
	{
		SDL_RenderTexture(global_window->renderer, 
						 global_window->background_animated->texture[frame_counter % 3], 
						 NULL, NULL);
	}
	
	// Render character (commented for now)
	/*
	size.w = WIDTH/6;
	size.h = HEIGHT/6;
	if (global_window->caracter && global_window->caracter->texture[global_window->caracter->caracter_state][0])
	{
		SDL_RenderTexture(global_window->renderer, 
						 global_window->caracter->texture[global_window->caracter->caracter_state][frame_counter % 3], 
						 NULL, &global_window->caracter->shape);
	}
	*/
	
	// Render ground
	size.w = 2 * WIDTH;
	size.h = HEIGHT;
	
	if (global_window->ground && global_window->ground->texture)
	{
		SDL_RenderTexture(global_window->renderer, 
						 global_window->ground->texture, 
						 NULL, &global_window->ground->shape);
	}

	// Present frame
	SDL_RenderPresent(global_window->renderer);
	
	// Update frame counter
	frame_counter++;
	if (frame_counter > 1000)
		frame_counter = 0;
}

int GAM_DL_MainComplet(void)
{
	// Initialize window if not already done
	if (!global_window)
	{
		global_window = GAM_DL_CoreWindowPop(WIDTH, HEIGHT);
		if (!global_window)
		{
			fprintf(stderr, "Failed to create window\n");
			return -1;
		}
		
		// Load world data (textures, game objects)
		GAM_DL_CoreLoadWorld(global_window);
	}
	
#ifdef BUILD_WASM
	// For WebAssembly, use emscripten main loop
	emscripten_set_main_loop(main_loop_iteration, 60, 1);
#else
	// For native builds, use traditional game loop
	while (!global_window->quit)
	{
		main_loop_iteration();
		SDL_Delay(16); // ~60 FPS
	}
	
	// Cleanup on exit
	if (global_window->renderer)
	{
		SDL_DestroyRenderer(global_window->renderer);
	}
	if (global_window->window)
	{
		SDL_DestroyWindow(global_window->window);
	}
	free(global_window);
#endif
	
	return 0;
}
