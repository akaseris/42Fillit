/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:10:17 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/20 13:07:59 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

static t_tet	*ft_rev_list(t_tet *a)
{
	t_tet *b;
	t_tet *tmp;

	b = NULL;
	while (a)
	{
		tmp = a->next;
		b = ft_add_lst(b, a->x, a->y, a->c);
		free(a);
		a = tmp;
	}
	return (b);
}

static t_tet	*ft_calcdif(t_tet *a)
{
	t_tet	*tmp;
	t_tet	*tmpdif;
	int		i;

	tmp = a;
	tmpdif = a;
	a = a->next;
	while (a)
	{
		i = 0;
		while (i < 3)
		{
			a->x = a->x - tmpdif->x;
			a->y = a->y - tmpdif->y;
			i++;
			a = a->next;
		}
		if (a)
		{
			tmpdif = a;
			a = a->next;
		}
	}
	return (tmp);
}

t_tet			*ft_convert_list(char *pieces_str)
{
	t_tet	*tet_link;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 1;
	y = 1;
	tet_link = NULL;
	while (pieces_str[i])
	{
		if (pieces_str[i] == '\n')
		{
			x = 0;
			y++;
		}
		y = (pieces_str[i] == '\n' && pieces_str[i + 1] == '\n') ? 0 : y;
		if (pieces_str[i] != '\n' && pieces_str[i] != '.')
			tet_link = ft_add_lst(tet_link, x - 1, y - 1, pieces_str[i]);
		i++;
		x++;
	}
	return (ft_calcdif(ft_rev_list(ft_move_upleft(tet_link))));
}
