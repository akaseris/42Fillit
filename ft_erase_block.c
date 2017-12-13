/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:09:00 by akaseris          #+#    #+#             */
/*   Updated: 2017/12/13 12:15:38 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_erase_block(char **grid, char c)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 4;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == c)
			{
				grid[i][j] = '.';
				count--;
			}
			if (!count)
				break ;
			j++;
		}
		if (!count)
			break ;
		i++;
	}
	return (grid);
}
