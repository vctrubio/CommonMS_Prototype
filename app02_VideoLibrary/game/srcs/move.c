#include "../include/header.h"

void	update_map_pos(int x, int y)
{
	_game()->pos_x = x;
	_game()->pos_y = y;
}

int	check_next_move(int y, int x)
{
	if (_map()->map[y][x] == '0')
		return (1);
	else if (_map()->map[y][x] == '2')
	{
		_info()->count -=1;
		return (2);
	}
	return (0);
}

void	move_player(int y, int x)
{
	int	pos_x;
	int	pos_y;

	pos_x = _game()->pos_x;
	pos_y = _game()->pos_y;
	
	if (check_next_move(pos_y + y, pos_x + x))
	{
		_map()->map[pos_y][pos_x] = '0';
		_map()->map[pos_y +y][pos_x + x] = 'p';
		update_map_pos(pos_x +x, pos_y + y);
	}
	// print_map();
}
