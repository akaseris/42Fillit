/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 21:30:21 by akaseris          #+#    #+#             */
/*   Updated: 2017/12/20 10:23:37 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_check_chars(char s, int *dot, int *hash, int *n)
{
	*dot = (s == '.') ? ++*dot : *dot;
	*hash = (s == '#') ? ++*hash : *hash;
	*n = (s == '\n') ? ++*n : *n;
}

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
			ft_check_chars(s[i], &dot, &hash, &n);
			if (s[i] == '\n' && n != 5 && !((4 * n) == (dot + hash)))
				return (0);
			i++;
		}
		pieces++;
		if (!(dot == 12 && hash == 4) || (s[i] == '\0' && s[i - 1] == '\n'
			&& s[i - 2] == '\n'))
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
