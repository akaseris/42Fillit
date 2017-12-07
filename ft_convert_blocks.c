/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_blocks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:58:44 by akaseris          #+#    #+#             */
/*   Updated: 2017/12/07 15:01:09 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_convert_blocks(char *str)
{
	int		i;
	char	count;

	i = 0;
	count = 'A';
	while (str[i])
	{
		if (str[i] == '#')
			str[i] = count;
		if (str[i] == '\n' && str[i + 1] == '\n')
			count++;
		i++;
	}
	return (str);
}
