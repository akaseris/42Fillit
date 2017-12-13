/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:49:58 by cfavero           #+#    #+#             */
/*   Updated: 2017/12/13 15:01:37 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char		*str;
	char		**grid;
	int			pieces;
	tet_list	*tet_link;

	if (ac != 2)
		return (0);
	str = source(av[1]);
	if (str == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	pieces = ft_check_pieces(str);
	if (pieces < 1 || pieces > 26 || ft_check_piece(str) != 1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	str = ft_move(str);
	str = ft_convert_blocks(str);
	grid = ft_create_grid(pieces, 0);
	tet_link = convert_list(str);
	tet_link = move_upleft(tet_link);
	grid = ft_solve_opt(tet_link, grid, pieces, 0, 0);
	while (*grid)
		printf("%s\n", *grid++);
//	tet_link = ft_switch_list(tet_link->next->next->next->next->next->next->next->next, tet_link->next->next->next->next, tet_link);
//	print_list(tet_link);
	return (0);
}
