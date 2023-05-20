#include "../include/header.h"

t_window	*rtn_window(void)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	window->mlx = mlx_init();
	window->window = NULL;
	return (window);
}

t_game	*rtn_game(void)
{
	t_game	*game;

	game = _game();
	return (game);
}

t_img	*rtn_img2(int x, int y, t_window *w) //not used- just for testing purposes - understand what window to use
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!x)
		x = SDWIDTH;
	if (!y)
		y = SDHEIGHT;
	img->w = w;
	img->width = x * UNIT;
	img->height = y * UNIT;
	printf("create img %d %d|\n", img->width, img->height);
	img->img = mlx_new_image(img->w->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bbp, &img->line_length, &img->endian);
	return (img);
}

t_img	*rtn_img(int x, int y)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!x)
		x = SDWIDTH;
	if (!y)
		y = SDHEIGHT;
	img->w = rtn_window();
	img->width = x * UNIT;
	img->height = y * UNIT;
	img->img = mlx_new_image(img->w->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bbp, &img->line_length, &img->endian);
	return (img);
}

