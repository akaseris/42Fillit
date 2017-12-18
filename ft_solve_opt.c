/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:22:34 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/18 17:28:32 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"
#include <stdio.h>

static int	ft_countdots(char **grid, char c)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == '.')
				count++;
			else if (grid[i][j] == c)
				return (count);
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_solve_opt(tet_list *blocks, tet_list *initial, char **grid, int ign)
{
	tet_list	*tmp;

	while (blocks)
	{
		tmp = initial;
		while (blocks->c != 'A' && tmp->c != (blocks->c) - 1)
			tmp = tmp->next;
		if (!ft_putblock(blocks, grid, ign))
		{
			if (blocks->c == 'A')
				return (0);
			ign = ft_countdots(grid, (blocks->c) - 1) + 1;
			grid = ft_erase_block(grid, ((blocks->c) - 1));
			blocks = tmp;
			continue ;
		}
		ign = 0;
		if (!blocks->next->next->next->next)
			break;
		blocks = blocks->next->next->next->next;
	}
	return (1);
}
