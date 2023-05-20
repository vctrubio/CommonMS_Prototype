#include "../include/header.h"

void	mpp(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x > img->width)
		return ;
	if (y > img->height)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bbp / 8));
	*(unsigned int*)dst = color;
}