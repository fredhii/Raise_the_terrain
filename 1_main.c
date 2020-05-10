#include "0_raise.h"

/**
 * main - Visulize a 3D grid.
 * @ac: Number of arguments.
 * @av: Pointer to arguments
 * Return: 0 Success, 1 Failed.
 */
int main(int ac, char **av)
{
	var_s var;

	if (ac != 2)
	{
		fprintf(stderr, "Usage <file> <coordinates file>\n");
		return (1);
	}
	if (init_vars(&var, av[1]) != 0)
		return (1);

	if (file_to_array(&var) != 0)
		return (1);

	while ("Running...")
	{
		SDL_SetRenderDrawColor(var.renderer, 0, 0, 0, 0);
		SDL_RenderClear(var.renderer);
		if (handle_events(&var) == 1)
			break;

		SDL_SetRenderDrawColor(var.renderer, 0, 255, 255, 255);

		draw_grid(&var);

		SDL_RenderPresent(var.renderer);
	}

	free_array(&var);
	SDL_DestroyRenderer(var.renderer);
	SDL_DestroyWindow(var.window);
	SDL_Quit();

	return (0);
}
