/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:10:17 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/18 17:35:03 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

static tet_list	*ft_rev_list(tet_list *a)
{
	tet_list *b;
	tet_list *tmp;

	b = NULL;
	while (a)
	{
		tmp = a->next;
		b = add_lst(b, a->x, a->y, a->c);
		free(a);
		a = tmp;
	}
	return (b);
}

static tet_list *ft_calcdif(tet_list *a)
{
	tet_list	*tmp;
	tet_list	*tmpdif;
	int			i;

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

tet_list	*convert_list(char *pieces_str)
{
	tet_list	*tet_link;
	int			i;
	int			x;
	int			y;

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
		if (pieces_str[i] == '\n' && pieces_str[i + 1] == '\n')
			y = 0;
		if (pieces_str[i] != '\n' && pieces_str[i] != '.')
		{
			tet_link = add_lst(tet_link, x - 1, y - 1, pieces_str[i]);
		}
		i++;
		x++;
	}
	tet_link = move_upleft(tet_link);
	tet_link = ft_rev_list(tet_link);
	tet_link = ft_calcdif(tet_link);
	return (tet_link);
}
