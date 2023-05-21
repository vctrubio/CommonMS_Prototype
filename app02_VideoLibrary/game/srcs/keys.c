#include "../include/header.h"

int	test_key_code(int keycode)
{
	if (keycode == K_ESC || keycode ==  KEY_ESC)
		exit(1);
	if (keycode == K_D || keycode == KEY_RIGHT)
		move_player(0, 1);
	if (keycode == (K_A || keycode == KEY_LEFT))
		move_player(0, -1);
	if (keycode == (K_S || keycode == KEY_DOWN)) 
		move_player(1, 0);
	if (keycode == (K_W || keycode == KEY_UP))
		move_player(-1, 0);
	return (keycode);
}

void	key_listener(void)
{
	t_game	*g;

	g = _game();
	mlx_hook(g->w->window, 2, 0, test_key_code, NULL);
	mlx_hook(g->w->window, 3, 0, test_key_code, NULL);
}
