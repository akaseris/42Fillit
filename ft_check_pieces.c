/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 21:30:21 by akaseris          #+#    #+#             */
/*   Updated: 2017/12/03 21:31:09 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_pieces(char *s, int dot, int hash, int n)
{
	int i;
	int pieces;

	i = 0;
	pieces = 0;
	while (s[i])
	{
		dot = 0;
		hash = 0;
		n = 0;
		while (n < 5 && s[i])
		{
			if (!(s[i] == '#' || s[i] == '.' || s[i] == '\n'))
				return (0);
			dot = (s[i] == '.') ? ++dot : dot;
			hash = (s[i] == '#') ? ++hash : hash;
			n = (s[i] == '\n') ? ++n : n;
			if (s[i] == '\n' && n != 5)
				if (!((4 * n) == (dot + hash)))
					return (0);
			i++;
		}
		pieces++;
		if (!(dot == 12 && hash == 4))
			return (0);
	}
	return (pieces);
}

int			ft_check_pieces(char *s)
{
	int dot;
	int hash;
	int n;
	int pieces;

	dot = 0;
	hash = 0;
	n = 0;
	pieces = ft_pieces(s, dot, hash, n);
	return (pieces);
}
