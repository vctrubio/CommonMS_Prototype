#include "../include/header.h"

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
