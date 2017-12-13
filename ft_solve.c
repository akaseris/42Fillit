/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:50:48 by akaseris          #+#    #+#             */
/*   Updated: 2017/12/13 14:57:55 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"
#include <stdio.h>

static char	**ft_resetgrid(char **grid, int pieces, int inc)
{
	int i;

	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	return (ft_create_grid(pieces, inc));
}

char	**ft_solve(tet_list *blocks, char **grid, int pieces, int inc)
{
	tet_list *tmp;

	tmp = blocks;
	while (blocks)
	{
		if(!ft_putblock(blocks, grid, 0))
		{
			inc++;
			grid = ft_resetgrid(grid, pieces, inc);
			return (ft_solve(tmp, grid, pieces, inc));
		}
		if (!blocks->next->next->next->next)
			break;
		blocks = blocks->next->next->next->next;
	}
//	if(!ft_putblock(blocks, grid, 0))
//	{
//		inc++;
//		grid = ft_resetgrid(grid, pieces, inc);
//		return (ft_solve(tmp, grid, pieces, inc));
//	}
	return (grid);
}
