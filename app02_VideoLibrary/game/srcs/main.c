#include "../include/header.h"
/* V3
create map from X
parse image
put image
move image
*/

int	gameloop(void) //infinite gameloop (always running)
{
	t_game	*game;

	game = _game();
	draw_game();
	if (_info()->count <= 0)
		exit (12);
	return (0);
}


int	main(int ac, char **av)
{
	t_img		*game_img_map;
	t_window	*w;
	t_game		*game;
	t_info		*info;

	if (ac != 2)
		return -1;
	w = rtn_window();
	parse_map(NULL);
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

