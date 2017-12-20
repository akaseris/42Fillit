/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putblock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:12:24 by akaseris          #+#    #+#             */
/*   Updated: 2017/12/20 13:10:44 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_fillgrid(char **grid, t_tet *a, int i, int j)
{
	int k;

	k = 0;
	grid[i][j] = a->c;
	a = a->next;
	while (k < 3)
	{
		grid[i + a->y][j + a->x] = a->c;
		k++;
		a = a->next;
	}
	return (grid);
}

static t_tet	*ft_isblockfit(t_tet *blocks, char **grid, int i, int j)
{
	char	c;
	int		len;
	t_tet	*tmp;

	c = blocks->c;
	tmp = blocks;
	blocks = blocks->next;
	len = 0;
	while (grid[len])
		len++;
	while (blocks && blocks->c == c)
	{
		if ((i + blocks->y > len - 1) || (j + blocks->x > len - 1)
				|| grid[i + blocks->y][j + blocks->x] != '.')
			break ;
		blocks = blocks->next;
	}
	if (!blocks || blocks->c != c)
		grid = ft_fillgrid(grid, tmp, i, j);
	return (blocks);
}

int				ft_putblock(t_tet *blocks, char **grid, int ign)
{
	int		i;
	int		j;
	t_tet	*tmp;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == '.')
			{
				tmp = blocks;
				blocks = (!ign) ? ft_isblockfit(blocks, grid, i, j) : blocks;
				if (!ign && (!blocks || blocks->c != tmp->c))
					return (1);
				ign = (ign) ? ign - 1 : ign;
				blocks = tmp;
			}
			j++;
		}
		i++;
	}
	return (0);
}
