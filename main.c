/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:49:58 by cfavero           #+#    #+#             */
/*   Updated: 2017/12/06 19:46:11 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*str;
	char	*grid;
	int		pieces;

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
	//creting list from str
	grid = ft_create_grid(pieces);
	printf("%s", str);
	return (0);
}
