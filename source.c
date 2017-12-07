/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:13:48 by cfavero           #+#    #+#             */
/*   Updated: 2017/12/03 21:15:00 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*source(char *file)
{
	int		fd;
	int		size;
	char	*str;

	if (!file)
		return (0);
	if (!(str = (char*)malloc(sizeof(*str) * (BUF_SIZE + 1))))
		return (0);
	if ((fd = open(file, O_RDONLY)) != -1)
	{
		size = read(fd, str, BUF_SIZE);
		str[size] = '\0';
	}
	if (close(fd) == -1)
		return (0);
	return (str);
}
