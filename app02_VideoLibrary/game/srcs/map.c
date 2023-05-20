#include "../include/header.h"

void	my_map_loop(void)
{
	t_map	*map;
	t_img	*img;
	int	y;
	int	x;

	img = _game()->img;
	y = -1;
	map = _map();
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == '1')
				fill_img_square(img, x, y, MYRED);
			else if (map->map[y][x] == 'p')
				fill_img_square(img, x, y, MYGREEN);
			else if (map->map[y][x] == '2')
				fill_img_square(img, x, y, MYREDISH);
			else if (map->map[y][x] == '0')
				fill_img_square(img, x, y, MYWHITE);
		}
	}
}


void	my_map_init(void)
{
	t_map	*map;
	t_img	*img;
	int	y;
	int	x;

	img = _game()->img;
	y = -1;
	map = _map();
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == '1')
				fill_img_square(img, x, y, MYRED);
			else if (map->map[y][x] == 'p')
			{
				fill_img_square(img, x, y, MYGREEN);
				update_map_pos(x, y);
			}
			else if (map->map[y][x] == '2')
			{
				_info()->count += 1;
				fill_img_square(img, x, y, MYREDISH);
			}
		}
	}
	draw_gridline();
}

