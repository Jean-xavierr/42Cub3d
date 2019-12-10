#include "../cub3d.h"

int		main(int ac, char **av)
{
	t_info	info_map;
	if (ac < 2)
		ft_error(-1);
	else if (ac > 2)
		ft_error(0);
	else
	{
		ft_init_struct_infomap(&info_map);
		ft_read_management(av[ac - 1], &info_map);
	}
	return (0);
}
