#include "../include/header.h"

static int generate_difficulty(int difficulty)
{
    int random_num = rand() % 10 + 1;
    return (random_num <= difficulty);
}

void	createMap(int rows, int columns, int difficulty, char *filename)
{

	//validate difficulty from 1-9 and filename must end with .ber

    char** map = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++)
        map[i] = (char*)malloc(columns * sizeof(char));

	srand(time(NULL));
    for (int i = 0; i < rows; i++)
	{
        for (int j = 0; j < columns; j++)
		{
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1)
                map[i][j] = '1';
			else if (i == rows / 2 && j == columns / 2)
                map[i][j] = 'p';
            else
			{
				if (generate_difficulty(difficulty))
                	map[i][j] = '2'; 
				else
                	map[i][j] = '0'; 
            }
        }
    }

	int file = open(filename, O_RDWR | O_CREAT , 0744); 
	if (file < 0)
	{
        printf("ERROR:: Failed to create the file.\n");
        exit(100);
    }
    for (int i = 0; i < rows; i++)
	{
        for (int j = 0; j < columns; j++)
			write(file, &(map[i][j]), 1);
		write(file, "\n", 1);
    }
	close(file);
    for (int i = 0; i < rows; i++)
        free(map[i]);
    free(map);
}
