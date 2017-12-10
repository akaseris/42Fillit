/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:50:48 by akaseris          #+#    #+#             */
/*   Updated: 2017/12/10 22:03:06 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
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

tet_list	*ft_solve(tet_list *blocks, char **grid, int pieces, int inc)
{
	tet_list	*tmp;

	tmp = blocks;
	while (blocks->next->next->next->next)
	{
		if(!ft_putblock(blocks, grid))
		{
			inc++;
			grid = ft_resetgrid(grid, pieces, inc);
			printf("%s\n", grid[1]);
			return (ft_solve(tmp, grid, pieces, inc));
		}
		blocks = blocks->next->next->next->next;
	}
	if(!ft_putblock(blocks, grid))
	{
		inc++;
		grid = ft_resetgrid(grid, pieces, inc);
		printf("%d\n", inc);
		print_list(tmp);
		return (ft_solve(tmp, grid, pieces, inc));
	}
	return (blocks);
}
