#include "../include/header.h"

int	gameloop(void)
{
	t_game	*game;

	game = _game();
	if (_info()->count <= 0)
	{
		time_t 	now = clock();
		double 	exec = (double)(now - _info()->s_time) / CLOCKS_PER_SEC * 60;
		int		rtnScore = 250 - (int)(exec);
		if (rtnScore < 0)
			rtnScore = 1;
		printf("Execution time: %d \n", rtnScore);
		exit (rtnScore);
	}
	draw_game();
	return (0);
}

bool	map_exist(int difficulty, char *name)
{
	int fd;
	char path[255];

	strcpy(path, "./maps/");
	strcat(path, name);
	fd = open(path, O_RDONLY);
	if ((fd = open(path, O_RDONLY)) < 0)
	{
		printf("creating file - %s\n" ,path);
		createMap(9, 9, difficulty, path);
	}
	close(fd);
	return true;
}


// ./cube NAME DIFF MAP
int	main(int ac, char **av)
{
	t_img		*game_img_map;
	t_window	*w;
	t_game		*game;
	t_info		*info;

	if (ac != 4)
		return -1;
	_info()->s_time = clock();
	w = rtn_window();

	map_exist(av[2][0] - 48, av[3]);
	parse_map(av[3]);

	game_img_map = rtn_img(_map()->max_x, _map()->max_y);
	game = _game();
	game->img = game_img_map;
	game->w = w;
	w->window = mlx_new_window(w->mlx, game_img_map->width, game_img_map->height, av[1]);

	my_map_init();
	mlx_loop_hook(game->w->mlx, &gameloop, NULL);
	key_listener();
	mlx_loop(w->mlx);
	return (1);
}

