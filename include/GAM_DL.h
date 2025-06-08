#ifndef GAM_DL_H
#define GAM_DL_H
#include <SDL3/SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#define GAM_DL_DEFAULT_WIDTH 800
#define GAM_DL_DEFAULT_HEIGHT 600
#define WIDTH GAM_DL_DEFAULT_WIDTH
#define HEIGHT GAM_DL_DEFAULT_HEIGHT
typedef struct s_GAM_Window t_GAM_Window;
typedef    struct s_GAM_ImageSimple t_GAM_ImageSimple;
typedef struct s_GAM_ImageAnimated t_GAM_ImageAnimated;
typedef struct s_GAM_Caracter t_GAM_Caracter;

typedef void (func_ptr)(void);

//structures pour boutton
typedef    struct s_texte
{
    SDL_Texturetexture;
    SDL_FRect rect;
} t_texte;

typedef struct s_button
{
    SDL_Texture texture;
    SDL_Texturehover_texture;
    SDL_FRect    rect;
    //t_texte            *text;
} t_button;

typedef struct s_GAM_Window
{
    func_ptr                function[6];
    SDL_Window                *window;
    SDL_Renderer            *renderer;
    t_GAM_ImageSimple        ground;
    t_GAM_ImageAnimated        room;
    t_GAM_Caracter            caracter;
    int                        game_state;
    int                        quit;
    int                        init_game;
    SDL_Event                event;
}    t_GAM_Window;

typedef enum e_GAM_GameState
{
    GAM_MENU,
    GAM_GAME,
    GAM_PAUSE
}    t_GAM_GameState;
//int                GAM_DL_Main(void);
int                GAM_DL_MainComplet(void);
void            GAM_DL_Game(void);
void            GAM_DL_Menu(void);
void            GAM_DL_Pause(void);
t_GAM_Window    GAM_DL_CoreWindowPop(int width, int height);
void            ActivationGravite(void);

// Global window variable for cross-platform compatibility
extern t_GAM_Windowg_gam_window;

//MENU FEDOR
//texture
t_texte create_texture_texte(SDL_Renderer render, chartexte, int taille_texte);
//dimension
void    put_image_x_y_w_h_exit(SDL_FRect exit_pointer);
void    put_image_x_y_w_h_start(SDL_FRectimage_pointer);
void    put_image_x_y_w_h_text(SDL_FRect text_pointer);
//create button
t_button create_button(SDL_Rendererrenderer, const char normal_path, const charhover_path, SDL_FRect rect);
//fermer fenetre
int    close_window(SDL_Window *window, SDL_Event event);
//si souris dessus
int en_survol(SDL_FRect img);
//start press
int    start_press(SDL_Event event, SDL_FRect start_img);
//exit press
int exit_press(SDL_Event event, SDL_FRect exit_img)

#include "GAM_DL_Texture.h"
#include "GAM_DL_Event.h"
#endif