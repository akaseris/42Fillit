/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_upleft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:03:38 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/07 14:44:59 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static tet_list	*move_up(tet_list *lst)
{
	tet_list *tmp;

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

static tet_list	*move_left(tet_list *lst)
{
	tet_list *tmp;

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

tet_list		*move_upleft(tet_list *tet_link)
{
	tet_link = move_up(tet_link);
	tet_link = move_left(tet_link);
	return (tet_link);
}
