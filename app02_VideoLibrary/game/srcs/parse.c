#include "../include/header.h"

void	parse_map(char *file)
{
	int		fd;
	int		fdTmp;
	char	*line;
	char	path[100];
	t_list	*lst;

	lst = NULL;
	strcpy(path, "./maps/");
	strcat(path, file);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ;
	else
	{
		while (get_next_line(fd, &line))
			ft_lstadd_back(&lst, ft_lstnew((void *)ft_strdup(line)));
		close(fd);
	}
	return (init_map(lst));
}
