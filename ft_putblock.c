/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putblock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:12:24 by akaseris          #+#    #+#             */
/*   Updated: 2017/12/10 21:51:54 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

static void		ft_fillgrid(char **grid, tet_list *a, int i, int j)
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
}

static tet_list	*ft_isblockfit(tet_list *blocks, char **grid, int i, int j)
{
	char		c;
	int			len;
	tet_list	*tmp;

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
	if (blocks && blocks->c != c)
		ft_fillgrid(grid, tmp, i, j);
	return (blocks);
}

int				ft_putblock(tet_list *blocks, char **grid)
{
	int			i;
	int			j;
	char		c;
	tet_list	*tmp;

	c = blocks->c;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == '.')
			{
				tmp = blocks;
				blocks = ft_isblockfit(blocks, grid, i, j);
				if (!blocks || blocks->c != c)
					return (1);
				blocks = tmp;
			}
			j++;
		}
		i++;
	}
	return (0);
}
