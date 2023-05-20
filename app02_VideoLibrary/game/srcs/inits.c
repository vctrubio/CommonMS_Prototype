#include "../include/header.h"

void	init_keys(void) //Not using it atm... Maybe later
{
	_key()->W = 0;
	_key()->A = 0;
	_key()->S = 0;
	_key()->D = 0;
	_key()->Q = 0;
	_key()->E = 0;
	_key()->ESC = 0;
}

void	init_map(t_list *lst)
{
	t_map	*map;
	int		i;
	
	map = _map();
	map->max_y = ft_lstsize(lst);
	map->max_x = ft_strlen(lst->content); //assuming its even
	map->map = ft_calloc(map->max_y + 1, sizeof(char *));
	i = 0;
	while (lst)
	{
		map->map[i++] = (char*)lst->content;
		lst = lst->next;
	}
	map->map[i] = NULL;
}
