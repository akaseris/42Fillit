/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:22:34 by jszabo            #+#    #+#             */
/*   Updated: 2018/01/11 17:55:09 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int			ft_solve_opt(t_tet *blocks, t_tet *initial, char **grid,
	int ign)
{
	t_tet	*tmp;

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
			break ;
		blocks = blocks->next->next->next->next;
	}
	return (1);
}
