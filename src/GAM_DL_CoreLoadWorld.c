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
 * │  -> Nom      : GAM_DL_CoreLoadWorld.c                                   │ *
 * │  -> Auteur   : lolilol                                                  │ *
 * │  -> Date     : 05/06/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#include "GAM_DL.h"

void GAM_DL_CoreLoadWorld(t_GAM_Window *gam_window)
{
    gam_window->ground->texture = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_SIMPLE_GROUND);
    gam_window->ground->shape.x = 0;
    gam_window->ground->shape.y = OFFSET_IMAGE_SIMPLE_GROUND_y;

    gam_window->background_animated->texture[0] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_ANIMATED0);
    gam_window->background_animated->texture[1] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_ANIMATED1);
    gam_window->background_animated->texture[2] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_ANIMATED2);
    gam_window->background_animated->shape.x = 0;
    gam_window->background_animated->shape.y = 0;

    gam_window->caracter->texture[0][0] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_CARACTER_WALK_LEFT0);
    gam_window->caracter->texture[0][1] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_CARACTER_WALK_LEFT1);
    gam_window->caracter->texture[0][2] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_CARACTER_WALK_LEFT2);
    gam_window->caracter->texture[1][0] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_CARACTER_WALK_RIGHT0);
    gam_window->caracter->texture[1][1] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_CARACTER_WALK_RIGHT1);
    gam_window->caracter->texture[1][2] = GAM_DL_TextureLoad(gam_window, PATH_IMAGE_CARACTER_WALK_RIGHT2);
    gam_window->caracter->shape.x = WIDTH / 2 - gam_window->caracter->width / 2;
    gam_window->caracter->shape.y = OFFSET_IMAGE_CARACTER;
}


//todo enum et tableau de pointeur