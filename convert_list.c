/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:10:17 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/07 14:27:25 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

tet_list	*convert_list(char *pieces_str)
{
	tet_list *tet_link;
	int i;
	int x;
	int y;

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
	return (tet_link);
}
