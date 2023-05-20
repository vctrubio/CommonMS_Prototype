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

// ./cube DIFF MAP 
int	main(int ac, char **av)
{
	t_img		*game_img_map;
	t_window	*w;
	t_game		*game;
	t_info		*info;

	if (ac < 3)
		return -1;

	char	mapName[250];
	int 	i = 1;
	while (av[++i])
		strcat(mapName, av[i]);

	w = rtn_window();
	_info()->s_time = clock();
	map_exist(av[1][0] - 48, mapName);
	parse_map(mapName);

	game_img_map = rtn_img(_map()->max_x, _map()->max_y);
	game = _game();
	game->img = game_img_map;
	game->w = w;
	w->window = mlx_new_window(w->mlx, game_img_map->width, game_img_map->height, mapName);

	my_map_init();
	mlx_loop_hook(game->w->mlx, &gameloop, NULL);
	key_listener();
	mlx_loop(w->mlx);
	return (1);
}

