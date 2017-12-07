/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:00:43 by akaseris          #+#    #+#             */
/*   Updated: 2017/11/25 15:32:32 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long int nb)
{
	int		alloc;

	alloc = (nb < 0) ? 2 : 1;
	nb = (nb < 0) ? -nb : nb;
	while (nb > 9)
	{
		alloc++;
		nb = nb / 10;
	}
	return (alloc);
}

char		*ft_itoa(int n)
{
	char		*buf;
	int			alloc;
	long int	nb;

	nb = (long int)n;
	alloc = count_digits(nb);
	nb = (nb < 0) ? -nb : nb;
	if (!(buf = (char *)malloc(sizeof(char) * alloc + 1)))
		return (NULL);
	buf[alloc--] = '\0';
	while (nb > 9)
	{
		buf[alloc--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	buf[alloc--] = nb + '0';
	if (alloc == 0)
		buf[alloc] = '-';
	return (buf);
}
