#include "../include/header.h"

t_game	*_game(void)
{
	static t_game game;

	return (&game);
}

t_window	*_window(void)
{
	static t_window	w;

	return (&w);
}

t_key	*_key(void)
{
	static t_key	k;

	return(&k);
}

t_map	*_map(void)
{
	static t_map	m;

	return (&m);
}

t_info	*_info(void)
{
	static t_info	i;

	return (&i);
}
