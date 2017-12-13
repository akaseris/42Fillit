/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:22:34 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/13 15:55:16 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"
#include <stdio.h>

static char **ft_resetgrid(char **grid, int pieces, int inc)
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

char	**ft_solve_opt(tet_list *blocks, char **grid, int pieces, int ign, int inc)
{
	tet_list	*pre;
	tet_list	*tmp;

	tmp = blocks;
	while (blocks)
	{
		if (!ft_putblock(blocks, grid, ign))
		{
			if ((blocks->c) != 'A')
			{
				ign++;
				grid = ft_erase_block(grid, ((blocks->c) - 1));
				ft_printwordstables(grid);
				return (ft_solve_opt(pre, grid, pieces, ign, inc));
			}
			else
			{
				ign = 0;
				inc++;
				grid = ft_resetgrid(grid, pieces, inc);
				return (ft_solve_opt(tmp, grid, pieces, ign, inc)); 
			}
		}
		pre = blocks;
		if (!blocks->next->next->next->next)
			break;
		blocks = blocks->next->next->next->next;
	}
	return (grid);
}
