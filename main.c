/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:49:58 by cfavero           #+#    #+#             */
/*   Updated: 2018/01/24 15:55:06 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_error(void)
{
	write(1, "error\n", 6);
	return (0);
}

static void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

static int	ft_usage()
{
	ft_putstr("usage: fillit target_file\n");
	ft_putstr("Accepts ONE argument only.\n");
	return (0);
}

int			main(int ac, char **av)
{
	char		*str;
	char		**grid;
	int			pieces;
	t_tet		*tet_link;

	if (ac != 2)
		return (ft_usage());
	str = ft_source(av[1]);
	if (str == 0)
		return (ft_error());
	pieces = ft_check_pieces(str);
	if (pieces < 1 || pieces > 26 || ft_check_piece(str) != 1)
		return (ft_error());
	str = ft_convert_blocks(str);
	grid = ft_create_grid(pieces, 0);
	tet_link = ft_convert_list(str);
	grid = ft_solve(tet_link, grid, pieces, 0);
	while (*grid)
	{
		ft_putstr(*grid++);
		write(1, "\n", 1);
	}
	return (0);
}
