/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:40:53 by akaseris          #+#    #+#             */
/*   Updated: 2017/12/13 19:08:51 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_grid(int pieces, int inc)
{
	int		total;
	int		i;
	int		c;
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
	c = 0;
	while (c < total + i)
	{
		if ((c + 1) % (i + 1) == 0 && c)
			grid[c] = '\n';
		else
			grid[c] = '.';
		c++;
	}
	grid[c] = '\0';
	tabgrid = ft_strsplit(grid, '\n');
	free(grid);
	return (tabgrid);
}
