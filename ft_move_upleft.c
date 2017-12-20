/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_upleft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:03:38 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/20 13:09:32 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tet	*ft_move_up(t_tet *lst)
{
	t_tet *tmp;

	tmp = lst;
	while (lst && lst->next->next->next)
	{
		while (lst->x != 0 && lst->next->x != 0 &&
	lst->next->next->x != 0 && lst->next->next->next->x != 0)
		{
			lst->x -= 1;
			lst->next->x -= 1;
			lst->next->next->x -= 1;
			lst->next->next->next->x -= 1;
		}
		lst = lst->next->next->next->next;
	}
	return (tmp);
}

static t_tet	*ft_move_left(t_tet *lst)
{
	t_tet *tmp;

	tmp = lst;
	while (lst && lst->next->next->next)
	{
		while (lst->y != 0 && lst->next->y != 0 &&
	lst->next->next->y != 0 && lst->next->next->next->y != 0)
		{
			lst->y -= 1;
			lst->next->y -= 1;
			lst->next->next->y -= 1;
			lst->next->next->next->y -= 1;
		}
		lst = lst->next->next->next->next;
	}
	return (tmp);
}

t_tet			*ft_move_upleft(t_tet *tet_link)
{
	tet_link = ft_move_up(tet_link);
	tet_link = ft_move_left(tet_link);
	return (tet_link);
}
