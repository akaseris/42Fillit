/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:19:05 by cfavero           #+#    #+#             */
/*   Updated: 2017/12/06 17:05:19 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
# define BUF_SIZE 4096

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char	*source(char *file);
int		ft_check_pieces(char *s);
int		ft_check_piece(char *s);
char	*ft_convert_blocks(char *str);
char	**ft_strsplit(char const *s, char c);
char	*ft_create_grid(int pieces);
//char	*ft_solve(char **blocks, char *grid);
char	*ft_move(char *str);

# endif
