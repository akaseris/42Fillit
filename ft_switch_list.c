/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:45:57 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/12 12:33:10 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

tet_list	*ft_switch_list(tet_list *cur, tet_list *pre, tet_list *ori)
{
	int			i;
	int			x;
	int			y;
	char		c;

	i = 0;
	while (i < 4)
	{
		x = cur->x;
		y = cur->y;
		c = cur->c;
		cur->x = pre->x;
		cur->y = pre->y;
		cur->c = pre->c;
		pre->x = x;
		pre->y = y;
		pre->c = c;
		pre = pre->next;
		cur = cur->next;
		i++;
	}
	return (ori);
}
