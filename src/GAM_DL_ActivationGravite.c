#include "GAM_DL.h"

int	CollisionBas(SDL_FRect *perso, SDL_FRect *room)
{
    float persoLeft = perso->x;
    float persoRight = perso->x + perso->w;
	float persoTop = perso->y;

    float roomLeft = room->x;
    float roomRight = room->x + room->w;
	float roomTop = room->y;

    if (persoRight > roomRight) // A à gauche de B
    { 
		perso->x = roomRight - perso->w;
		return 0;
	}
    if (persoLeft < roomLeft) // A à droite de B
	{
		perso->x = roomLeft;
        return 0;
	}
    if (persoTop < roomTop) // A au-dessus de B
	{
		perso->y = roomTop;
        return 0;
	}

    return 1; // Collision détectée
}

int	CollisionHaut(SDL_FRect *perso, SDL_FRect *room)
{
    float persoLeft = perso->x;
    float persoRight = perso->x + perso->w;
	float persoBottom = perso->y + perso->h;

    float roomLeft = room->x;
    float roomRight = room->x + room->w;
	float roomBottom = room->y + room->h;


    if (persoRight > roomRight) // A à gauche de B
	{
		perso->x = roomRight - perso->w;
        return 0;
	}

    if (persoLeft < roomLeft) // A à droite de B
    {
		perso->x = roomLeft;
		return 0;
	}

	if (persoBottom > roomBottom) // A au-dessus de B
	{
		perso->y = roomBottom - perso->h;
		return 0;
	}

    return 1; // Collision détectée
}

int	CollisionDroite(SDL_FRect *perso, SDL_FRect *room)
{
    float persoTop = perso->y;
    float persoBottom = perso->y + perso->h;
	float persoLeft = perso->x;

    float roomTop = room->y;
    float roomBottom = room->y + room->h;
	float roomLeft = room->x;


    if (persoTop < roomTop) // A à gauche de B
	{
		perso->y = roomTop;
        return 0;
	}

    if (persoBottom > roomBottom) // A à droite de B
    {
		perso->y = roomBottom - perso->h;
		return 0;
	}

	if (persoLeft < roomLeft) // A au-dessus de B
	{
		perso->x = roomLeft;
		return 0;
	}

    return 1; // Collision détectée
}

int	CollisionGauche(SDL_FRect *perso, SDL_FRect *room)
{
    float persoTop = perso->y;
    float persoBottom = perso->y + perso->h;
	float persoRight = perso->x + perso->w;

    float roomTop = room->y;
    float roomBottom = room->y + room->h;
	float roomRight = room->x + room->w;


    if (persoTop < roomTop) // A à gauche de B
    {
		perso->y = roomTop;
		return 0;
	}

    if (persoBottom > roomBottom) // A à droite de B
	{
		perso->y = roomBottom - perso->h;
		return 0;
	}

	if (persoRight > roomRight) // A au-dessus de B
	{
		perso->x = roomRight - perso->w;
		return 0;
	}

    return 1; // Collision détectée
}


int	changementGraviteFace(const bool *keys, SDL_Scancode sc, int *enGravite, int *doublepress, int direction, int *etat_gravite)
{
	if (keys[sc] && *doublepress == 0)
		*doublepress = 1;
	if (!keys[sc] && *doublepress == 1)
		*doublepress = 2;
	if (keys[sc] && *doublepress == 2)
	{
		*etat_gravite = direction;
		*enGravite = 1;
		*doublepress = 0;
		return 1;
	}
	return 0;
}

void appliquerGraviteBas(const bool *keys, SDL_FRect *shapePerso, SDL_FRect *shapeRoom, float *vx, float *vy, float saut, int *enGravite, float gravite, int *enSaut, float *sol_y, t_rekey *rekey, int *etat_gravite)
{

	if (!*enGravite)
	{
		//printf("essaie de changer la gravite\n");

	    if (changementGraviteFace(keys, SDL_SCANCODE_UP, enGravite, &rekey->key_up, GRAVITE_HAUT, etat_gravite))
			return ;
		if (keys[SDL_SCANCODE_RIGHT] && *enSaut == 1)
		{
			*etat_gravite = GRAVITE_D;
			*enGravite = 1;
			return ;
		}
		if (keys[SDL_SCANCODE_LEFT] && *enSaut == 1)
		{
			*etat_gravite = GRAVITE_G;
			*enGravite = 1;
			return ;
		}
	}

    *sol_y = shapeRoom->y + shapeRoom->h - shapePerso->h;
    SDL_FRect temp = *shapePerso;

	if (!*enSaut && !*enGravite)
	{
    	if (keys[SDL_SCANCODE_LEFT])
		{
    	    temp.x -= 1;
			if (CollisionBas(&temp, shapeRoom))
    	        shapePerso->x = temp.x;
		}
    	if (keys[SDL_SCANCODE_RIGHT])
		{
    	    temp.x += 1;
			if (CollisionBas(&temp, shapeRoom))
    	        shapePerso->x = temp.x;
		}
    	if (keys[SDL_SCANCODE_UP])
    	{
    	    *vy -= saut;
    	    *enSaut = 1;
    	}
	}

    if (*enSaut)
    {
        *vy += gravite;              // gravité accélère la descente
        temp = *shapePerso;
        temp.x += *vx;
        if (CollisionBas(&temp, shapeRoom))
            shapePerso->x = temp.x;

        temp.y += *vy;
		if (CollisionBas(&temp, shapeRoom))
            shapePerso->y = temp.y;

        if (shapePerso->y >= *sol_y)
        {
            shapePerso->y = *sol_y;  // le remet exactement au sol
            *vy = 0;
            *vx = 0;
            *enSaut = 0;
            *enGravite = 0;
			rekey->key_left = 0;
			rekey->key_right = 0;
			rekey->key_up = 0;
        }
    }
}


void appliquerGraviteHaut(const bool *keys, SDL_FRect *shapePerso, SDL_FRect *shapeRoom, float *vx, float *vy, float saut, int *enGravite, float gravite, int *enSaut, float *sol_y, t_rekey *rekey, int *etat_gravite)
{
	if (!*enGravite)
	{
	    if (changementGraviteFace(keys, SDL_SCANCODE_DOWN, enGravite, &rekey->key_down, GRAVITE_BAS, etat_gravite))
			return ;
		if (keys[SDL_SCANCODE_RIGHT] && *enSaut == 1)
		{
			*etat_gravite = GRAVITE_D;
			*enGravite = 1;
			return ;
		}
		if (keys[SDL_SCANCODE_LEFT] && *enSaut == 1)
		{
			*etat_gravite = GRAVITE_G;
			*enGravite = 1;
			return ;
		}
	}

    *sol_y = shapeRoom->y;
    SDL_FRect temp = *shapePerso;


	if (!*enSaut && !*enGravite)
	{
    	if (keys[SDL_SCANCODE_LEFT])
		{
    	    temp.x -= 1;
			if (CollisionHaut(&temp, shapeRoom))
    	        shapePerso->x = temp.x;
		}
    	if (keys[SDL_SCANCODE_RIGHT])
		{
    	    temp.x += 1;
			if (CollisionHaut(&temp, shapeRoom))
    	        shapePerso->x = temp.x;
		}
    	if (keys[SDL_SCANCODE_DOWN] && *enSaut == 0)
    	{
    	    *vy += saut;
    	    *enSaut = 1;
    	}
	}

    if (*enSaut)
    {
        *vy -= gravite;              // gravité "vers le haut"
        temp = *shapePerso;

        temp.x += *vx;
        if (CollisionHaut(&temp, shapeRoom))
            shapePerso->x = temp.x;

        temp.y += *vy;
        if (CollisionHaut(&temp, shapeRoom))
            shapePerso->y = temp.y;

        if (shapePerso->y <= *sol_y)
        {
            shapePerso->y = *sol_y;  // le remet exactement au "plafond"
            *vy = 0;
			*vx = 0;
            *enSaut = 0;
            *enGravite = 0;
			rekey->key_right = 0;
			rekey->key_left = 0;
			rekey->key_down = 0;
        }
    }
}

void appliquerGraviteDroite(const bool *keys, SDL_FRect *shapePerso, SDL_FRect *shapeRoom, float *vx, float *vy, float saut, int *enGravite, float gravite, int *enSaut, float *sol_x, t_rekey *rekey, int *etat_gravite)
{
	if (!*enGravite)
	{
	    if (changementGraviteFace(keys, SDL_SCANCODE_LEFT, enGravite, &rekey->key_left, GRAVITE_G, etat_gravite))
			return ;
		if (keys[SDL_SCANCODE_UP] && *enSaut == 1)
		{
			*etat_gravite = GRAVITE_HAUT;
			*enGravite = 1;
			return ;
		}
		if (keys[SDL_SCANCODE_DOWN] && *enSaut == 1)
		{
			*etat_gravite = GRAVITE_BAS;
			*enGravite = 1;
			return ;
		}
	}

    *sol_x = shapeRoom->x + shapeRoom->w - shapePerso->w;
    SDL_FRect temp = *shapePerso;

	if (!*enSaut && !*enGravite)
	{
    	if (keys[SDL_SCANCODE_UP])
		{
    	    temp.y -= 1;
			if (CollisionDroite(&temp, shapeRoom))
    	        shapePerso->y = temp.y;
		}
    	if (keys[SDL_SCANCODE_DOWN])
		{
    	    temp.y += 1;
			if (CollisionDroite(&temp, shapeRoom))
    	        shapePerso->y = temp.y;
		}


	    if (keys[SDL_SCANCODE_LEFT] && *enSaut == 0)
	    {
	        *vx -= saut;
	        *enSaut = 1;
	    }
	}

    if (*enSaut)
    {
        *vx += gravite;
        temp = *shapePerso;

        temp.x += *vx;
        if (CollisionDroite(&temp, shapeRoom))
            shapePerso->x = temp.x;
		

		temp.y += *vy;
        if (CollisionDroite(&temp, shapeRoom))
            shapePerso->y = temp.y;

        if (shapePerso->x >= *sol_x)
        {
            shapePerso->x = *sol_x;
            *vx = 0;
            *vy = 0;
            *enSaut = 0;
            *enGravite = 0;
            rekey->key_left = 0;
            rekey->key_up = 0;
            rekey->key_down = 0;
        }
    }
}

void appliquerGraviteGauche(const bool *keys, SDL_FRect *shapePerso, SDL_FRect *shapeRoom, float *vx, float *vy, float saut, int *enGravite, float gravite, int *enSaut, float *sol_x, t_rekey *rekey, int *etat_gravite)
{
	if (!*enGravite)
	{
	    if (changementGraviteFace(keys, SDL_SCANCODE_RIGHT, enGravite, &rekey->key_right, GRAVITE_D, etat_gravite))
			return ;
		if (keys[SDL_SCANCODE_UP] && *enSaut == 1)
		{
			*etat_gravite = GRAVITE_HAUT;
			*enGravite = 1;
			return ;
		}
		if (keys[SDL_SCANCODE_DOWN] && *enSaut == 1)
		{
			*etat_gravite = GRAVITE_BAS;
			*enGravite = 1;
			return ;
		}
	}
    *sol_x = shapeRoom->x;
	SDL_FRect temp = *shapePerso;


	if (!*enSaut && !*enGravite)
	{
    	if (keys[SDL_SCANCODE_UP])
		{
    	    temp.y -= 1;
			if (CollisionGauche(&temp, shapeRoom))
    	        shapePerso->y = temp.y;
		}
    	if (keys[SDL_SCANCODE_DOWN])
		{
    	    temp.y += 1;
			if (CollisionGauche(&temp, shapeRoom))
    	        shapePerso->y = temp.y;
		}

    	if (keys[SDL_SCANCODE_RIGHT] && *enSaut == 0)
    	{
    	    *vx += saut;
    	    *enSaut = 1;
    	}
	}

    if (*enSaut)
    {
        *vx -= gravite;

        temp = *shapePerso;

        temp.x += *vx;
        if (CollisionGauche(&temp, shapeRoom))
            shapePerso->x = temp.x;

		temp.y += *vy;
		if (CollisionGauche(&temp, shapeRoom))
			shapePerso->y = temp.y;

        if (shapePerso->x <= *sol_x)
        {
            shapePerso->x = *sol_x;
            *vx = 0;
            *vy = 0;
            *enSaut = 0;
            *enGravite = 0;
            rekey->key_right = 0;
            rekey->key_up = 0;
            rekey->key_down = 0;
        }
    }
}

void    ActivationGravite(void)
{

    if (gam_window->init)
    {
        static SDL_FRect shapeRoom = gam_window->room->shape;
	    static float	vy = 0;
	    static float	vx = 0;
	    static float	gravite = 0.0012;
	    static float	sol_y = 0;
	    static float	sol_x = 0;
	    static float	saut = 0.6;
	    static int		enSaut = 0;
	    static int		etat_gravite = GRAVITE_BAS;
	    static int		enGravite = 0;
	    static t_rekey repeatkey;

	    repeatkey.key_up = 0;
	    repeatkey.key_down = 0;
	    repeatkey.key_right = 0;
	    repeatkey.key_left = 0;
        game_window->init = 0;
    }

    //if (/*changement de room*/)
    //
    //     shapeRoom = gam_window->room->shape;

    const bool* keys = SDL_GetKeyboardState(NULL);

    if (etat_gravite == GRAVITE_BAS)
	    appliquerGraviteBas(keys, &gam_window->caracter.shape, &shapeRoom, &vx, &vy, saut, &enGravite, gravite, &enSaut, &sol_y, &repeatkey, &etat_gravite);

	if (etat_gravite == GRAVITE_HAUT)
	    appliquerGraviteHaut(keys, &gam_window->caracter.shape, &shapeRoom, &vx, &vy, saut, &enGravite, gravite, &enSaut, &sol_y, &repeatkey, &etat_gravite);

	if (etat_gravite == GRAVITE_G)
		appliquerGraviteGauche(keys, &gam_window->caracter.shape, &shapeRoom, &vx, &vy, saut, &enGravite, gravite, &enSaut, &sol_x, &repeatkey, &etat_gravite);

	if (etat_gravite == GRAVITE_D)
		appliquerGraviteDroite(keys, &gam_window->caracter.shape, &shapeRoom, &vx, &vy, saut, &enGravite, gravite, &enSaut, &sol_x, &repeatkey, &etat_gravite);

}