#include "0_raise.h"

/**
 * file_to_array - Take out file data into an array.
 * @var: Struct with common variables.
 * Return: 0 Success, 1 Failed.
 */
int file_to_array(var_s *var)
{
	FILE *file;
	char *buff = NULL, *token;
	size_t num = 0;
	int i;

	if (var->f_name == NULL)
	{
		fprintf(stderr, "Invalid file name\n");
		return (1);
	}
	file = fopen(var->f_name, "r");
	if (!file)
	{
		fprintf(stderr, "Could not open file\n");
		return (1);
	}
	for (; getline(&buff, &num, file) != -1; var->row++) /* Get Size */
		if (var->row == 0)
		{
			token = strtok(buff, " \n");
			for (; token; var->col++)
				token = strtok(NULL, " \n");
		}
	var->array = malloc(sizeof(coord *) * var->row);
	if (!var->array)
	{
		fprintf(stderr, "Error creating malloc Row\n");
		return (1);
	}
	for (i = 0; i < var->row; i++)
	{
		var->array[i] = malloc(sizeof(coord) * var->col);
		if (!var->array[i])
		{
			fprintf(stderr, "Error creating malloc Column\n");
			return (1);
		}
	}
	free(buff), fclose(file), data_to_array(var);
	return (0);
}

/**
 * data_to_array - Take out file data into an array.
 * @var: Struct with common variables.
 * Return: 0 Success, 1 Failed.
 */
void data_to_array(var_s *var)
{
	FILE *file;
	char *buff = NULL, *token;
	size_t num = 0;
	int i, j;

	file = fopen(var->f_name, "r"); /* Assign coodenates */
	if (!file)
	{
		fprintf(stderr, "Could not open file\n");
		return;
	}
	for (i = 0; getline(&buff, &num, file) != -1; i++)
	{
		token = strtok(buff, " \n");
		for (j = 0; token; j++)
		{
			var->array[i][j].x = (SCREEN_WIDTH / (var->col + 8)) * (i + 1);
			var->array[i][j].y = (SCREEN_HEIGHT / (var->row + 3)) * (j + 1);
			var->array[i][j].z = atof(token);
			token = strtok(NULL, " \n");
		}
	}
	free(buff);
	fclose(file);
}

/**
 * free_array - Free coorditates.
 * @var: Struct with common variables.
 * Return: 0 Success, 1 Failed.
 */
void free_array(var_s *var)
{
	int i;

	for (i = 0; i < var->row; i++)
	{
		free(var->array[i]);
	}
	free(var->array);
}
