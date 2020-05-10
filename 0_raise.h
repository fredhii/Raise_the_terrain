#ifndef _RAISE_H_
#define _RAISE_H_

/* ============================================ */
/* LIBRARIES */
/* ============================================ */
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ============================================ */
/* STRUCTURES */
/* ============================================ */

/**
 * struct coordinates - Store graph coordinates
 * @x: x axis value
 * @y: y axis value
 * @z: z axis value
 *
 * Description: Grid 3D coordinates
 */
typedef struct coordinates
{
	float x;
	float y;
	float z;
} coord;

/**
 * struct variables - Global varibales
 * @window: Windows program
 * @renderer: Render program
 * @f_name: File name with coordinates
 * @array: Struct containing graph coordinates
 * @col: Graph width
 * @row: Graph height
 *
 * Description: Structure containing common variables
 * in project
 *
 */
typedef struct variables
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	char *f_name;
	coord **array;
	int col;
	int row;

} var_s;


/* ============================================ */
/* WINDOW SIZE */
/* ============================================ */
#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 1024
#endif
#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 600
#endif

/* ============================================ */
/* 2_data_hand.c */
/* ============================================ */
int file_to_array(var_s *var);
void data_to_array(var_s *var);
void free_array(var_s *var);

/* ============================================ */
/* 3_sdl_hand.c */
/* ============================================ */
int init_vars(var_s *var, char *av);
int handle_events(var_s *var);
void draw_grid(var_s *var);
void rotate_grid(var_s *var, int Angle);


#endif
