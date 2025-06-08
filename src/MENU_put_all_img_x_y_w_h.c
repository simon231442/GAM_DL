//GENGIS KODE

#include "GAM_DL.h"

void	put_image_x_y_w_h_start(SDL_FRect *image_pointer)
{
	SDL_FRect image;

	image = *image_pointer;
	image.x = (GAM_DL_DEFAULT_WIDTH - 200) / 2;
	image.y = (GAM_DL_DEFAULT_HEIGHT - 200) / 2;
	image.w = 200;
	image.h = 200;
	*image_pointer = image;
}

void	put_image_x_y_w_h_exit(SDL_FRect *exit_pointer)
{
	SDL_FRect exit;

	exit = *exit_pointer;
	exit.x = (GAM_DL_DEFAULT_WIDTH -  150) / 2;
	exit.y = (GAM_DL_DEFAULT_HEIGHT + 600) / 2;
	exit.w = 150;
	exit.h = 150;
  *exit_pointer = exit;
}
