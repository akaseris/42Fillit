/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:04:04 by akaseris          #+#    #+#             */
/*   Updated: 2017/12/06 19:39:39 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isleft_free(char *str, int col)
{
	int n;

	n = 1;
	while ((str[col] != '\n' || str[col + 1] != '\n') && str[col + 1])
	{
		n = (str[col] == '#') ? 0 : n;
		col = col + 5;
	}
	return (n);
}

static int	ft_isup_free(char *str, int row)
{
	int n;

	n = 1;
	while (str[row] != '\n')
	{
		n = (str[row] == '#') ? 0 : n;
		row++;
	}
	return (n);
}

static char	*ft_move_left(char *str)
{
	int i;
	int n;

	i = 0;
	while (str[i])
	{
		n = ft_isleft_free(str, i);
		if (n)
		{
			while ((str[i] != '\n' || str[i + 1] != '\n') && str[i + 1])
			{
				if (str[i] == '#')
				{
					str[i - 1] = str[i];
					str[i] = '.';
				}
				i++;
			}
			i = i - 19;
		}
		else
			i = (str[i + 1]) ? i + 21 : i++;
	}
	return (str);
}

static char	*ft_move_up(char *str)
{
	int i;
	int n;

	i = 0;
	while (str[i])
	{
		n = ft_isup_free(str, i);
		if (n)
		{
			while ((str[i] != '\n' || str[i + 1] != '\n') && str[i + 1])
			{
				if (str[i] == '#')
				{
					str[i - 5] = str[i];
					str[i] = '.';
				}
				i++;
			}
			i = i - 19;
		}
		else
			i = (str[i + 1]) ? i + 21 : i++;
	}
	return (str);
}

char		*ft_move(char *str)
{
	str = ft_move_left(str);
	str = ft_move_up(str);
	return (str);
}
