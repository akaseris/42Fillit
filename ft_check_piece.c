/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 21:33:20 by akaseris          #+#    #+#             */
/*   Updated: 2017/12/18 13:47:30 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_piece(char *s)
{
	int i;
	int count;
	int n;

	i = 0;
	while (s[i])
	{
		count = 0;
		n = 0;
		while (n < 5 && s[i])
		{
			if (s[i] == '#')
			{
				count = (s[i + 1] == '#') ? ++count : count;
				count = (s[i - 1] == '#') ? ++count : count;
				count = (s[i - 5] == '#' && n != 0) ? ++count : count;
				count = (s[i + 5] == '#' && n < 3) ? ++count : count;
			}
			n = (s[i] == '\n') ? ++n : n;
			i++;
		}
		if (count != 6 && count != 8)
			return (0);
	}
	return (1);
}
