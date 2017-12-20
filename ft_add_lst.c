/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:44:19 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/20 13:15:58 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*ft_add_lst(t_tet *list, int x, int y, char c)
{
	t_tet *tmp;

	tmp = (t_tet *)malloc(sizeof(t_tet));
	if (tmp)
	{
		tmp->x = x;
		tmp->y = y;
		tmp->c = c;
		tmp->next = list;
	}
	return (tmp);
}
