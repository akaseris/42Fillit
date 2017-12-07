/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:44:19 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/07 14:38:51 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

tet_list	*add_lst(tet_list *list, int x, int y, char c)
{
	tet_list *tmp;

	tmp = (tet_list *)malloc(sizeof(tet_list));
	if (tmp)
	{
		tmp->x = x;
		tmp->y = y;
		tmp->c = c;
		tmp->next = list;
	}
	return (tmp);
}
