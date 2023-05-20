#include "../include/header.h"

void	print_map(void)
{
	int	i;
	t_map *map;

	map = _map();
	i = -1;
	while (map->map[++i])
		printf("%s\n", map->map[i]);
	printf("map->height %d map->width %d --- (P at %f,%f)\n\n", map->max_y, map->max_x, _game()->pos_y, _game()->pos_x);
}
