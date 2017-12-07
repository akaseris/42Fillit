/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:16:53 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/07 14:30:24 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

void	print_list(tet_list *lst)
{
	while (lst)
	{
		ft_putstr("x: ");
		ft_putnbr(lst->x);
		ft_putchar('\n');
		ft_putstr("y: ");
		ft_putnbr(lst->y);
		ft_putchar('\n');
		ft_putstr("c: ");
		ft_putchar(lst->c);
		ft_putchar('\n');
		lst = lst->next;
	}
}
