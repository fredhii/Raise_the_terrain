#include "0_raise.h"

/**
 * init_vars - Initialize General User Interface.
 * @var: Variables to initialize.
 * @av: Coordinates file name
 * Return: 0 Success, 1 Failed.
 */
int init_vars(var_s *var, char *av)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "SDL_Init() Error: %s\n", SDL_GetError());
		return (1);
	}
	var->window = SDL_CreateWindow("Raise the Terrain \\0/",
				       SDL_WINDOWPOS_CENTERED,
				       SDL_WINDOWPOS_CENTERED,
				       SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (var->window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow() Error: %s\n",
			SDL_GetError());
		SDL_Quit();
		return (1);
	}
	var->renderer = SDL_CreateRenderer(var->window, -1,
					   SDL_RENDERER_ACCELERATED |
					   SDL_RENDERER_PRESENTVSYNC);
	if (var->renderer == NULL)
	{
		fprintf(stderr, "SDL_CreateRenderer() Error: %s\n",
			SDL_GetError());
		SDL_DestroyWindow(var->window);
		SDL_Quit();
		return (1);
	}

	var->f_name = av;
	var->array = NULL;
	var->row = 0;
	var->col = 0;

	return (0);
}

/**
 * handle_events - Handle user inputs.
 * @var: Struct with common variables
 * Return: 0 Success, 1 Failed.
 */
int handle_events(var_s *var)
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			return (1);
		case SDL_KEYDOWN:
			switch (e.key.keysym.scancode)
			{
			case 0x29:
				return (1);
			case SDL_SCANCODE_W:
			case SDL_SCANCODE_UP:
				rotate_grid(var, 2);
				break;
			case SDL_SCANCODE_S:
			case SDL_SCANCODE_DOWN:
				rotate_grid(var, -2);
				break;
			case SDL_SCANCODE_A:
			case SDL_SCANCODE_LEFT:
				rotate_grid(var, 1);
				break;
			case SDL_SCANCODE_D:
			case SDL_SCANCODE_RIGHT:
				rotate_grid(var, -1);
				break;
			default:
				break;
			}
		}
	}
	return (0);
}

/**
 * draw_grid - Draw grid using coordinates.
 * @var: Struct with common variables
 */
void draw_grid(var_s *var)
{
	int i, j;
	float x, y, z;
	float xx, yy, XX, YY;
	float x_incl = 0.8, y_incl = 0.7;
	float Cx, Cy;

	Cx = SCREEN_WIDTH / 2.2;
	Cy = SCREEN_HEIGHT / 3.2;
	for (i = 0; i < var->row; i++)
	{
		for (j = 0; j < var->col; j++)
		{
			x = var->array[i][j].x;
			y = var->array[i][j].y;
			z = var->array[i][j].z;
			xx = (x_incl * (x - y)) + Cx;
			yy = ((1 - y_incl) * (x + y) - z) + Cy;

			if (i < var->row - 1)
			{
				/* Take out next X coordinate */
				x = var->array[i + 1][j].x;
				y = var->array[i + 1][j].y;
				z = var->array[i + 1][j].z;
				YY = ((1 - y_incl) * (x + y) - z) + Cy;
				XX = (x_incl * (x - y)) + Cx;
				SDL_RenderDrawLine(var->renderer, xx, yy, XX, YY);
			}
			if (j < var->col - 1)
			{
				/* Take out next Y coordinate */
				x = var->array[i][j + 1].x;
				y = var->array[i][j + 1].y;
				z = var->array[i][j + 1].z;
				YY = ((1 - y_incl) * (x + y) - z) + Cy;
				XX = (x_incl * (x - y)) + Cx;
				SDL_RenderDrawLine(var->renderer, xx, yy, XX, YY);
			}
		}
	}
}

/**
 * rotate_grid - Rotate grid using coordinates.
 * @var: Struct with common variables
 * @Angle: Axis to move grid
 */
void rotate_grid(var_s *var, int Angle)
{
	int i, j;
	float x, y, z, Cx, Cy;
	float a, Rx, Ry, Rz;
	int axis = 0;

	if (Angle == 2)
		axis = 1, a = 1 * M_PI / 180;
	else if (Angle == -2)
		axis = 1, a = -1 * M_PI / 180;
	else
		a = Angle * M_PI / 180;
	Cx = SCREEN_WIDTH / 4;
	Cy = SCREEN_HEIGHT / 3;

	for (i = 0; i < var->row; i++)
		for (j = 0; j < var->col; j++)
		{
			if (axis == 0) /* Move left or right */
			{
				x = var->array[i][j].x;
				y = var->array[i][j].y;
				Rx = (x - Cx) * cos(a) - (y - Cy) * sin(a) + Cx;
				Ry = (x - Cx) * sin(a) + (y - Cy) * cos(a) + Cy;
				var->array[i][j].x = Rx;
				var->array[i][j].y = Ry;
			}
			else /* Move up or down */
			{
				y = var->array[i][j].y;
				z = var->array[i][j].z;
				Ry = y * cos(a) - z * sin(a);
				Rz = y * sin(a) + z * cos(a);
				var->array[i][j].y = Ry;
				var->array[i][j].z = Rz;
			}
		}
}
