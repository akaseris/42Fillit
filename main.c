/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:49:58 by cfavero           #+#    #+#             */
/*   Updated: 2017/12/07 14:51:16 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char		*str;
	char		*grid;
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
// these functions convert the string to list and then move up-left
	tet_link = convert_list(str);
	tet_link = move_upleft(tet_link);

	grid = ft_create_grid(pieces);
	printf("%s", str);
// this shits out the coordinates (the list) on the screen
	print_list(tet_link);
	return (0);
}
