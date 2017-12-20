/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:40:53 by akaseris          #+#    #+#             */
/*   Updated: 2017/12/20 11:04:41 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_str_grid(char *grid, int total, int i)
{
	int c;

	c = 0;
	while (c < total + i)
	{
		grid[c] = ((c + 1) % (i + 1) == 0 && c) ? '\n' : '.';
		c++;
	}
	grid[c] = '\0';
	return (grid);
}

char		**ft_create_grid(int pieces, int inc)
{
	int		total;
	int		i;
	char	*grid;
	char	**tabgrid;

	total = pieces * 4;
	i = 1;
	while (!(total / i == i && total % i == 0))
	{
		if (i == total / 2)
		{
			total++;
			i = 0;
		}
		i++;
	}
	total = (i + inc) * (i + inc);
	i = i + inc;
	grid = (char*)malloc(sizeof(*grid) * (total + i + 1));
	tabgrid = ft_strsplit(ft_str_grid(grid, total, i), '\n');
	free(grid);
	return (tabgrid);
}
