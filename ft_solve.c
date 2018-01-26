/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:50:48 by akaseris          #+#    #+#             */
/*   Updated: 2018/01/11 17:53:09 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

char		**ft_solve(t_tet *blocks, char **grid, int pieces, int inc)
{
	if (!ft_solve_opt(blocks, blocks, grid, 0))
	{
		inc++;
		grid = ft_resetgrid(grid, pieces, inc);
		return (ft_solve(blocks, grid, pieces, inc));
	}
	return (grid);
}
