#include "../cub3d.h"

int		main(int ac, char **av)
{
	if (ac < 2)
		ft_error(-1);
	else if (ac > 2)
		ft_error(0);
	else
		ft_read_management(av[ac - 1]);
	return (0);
}
