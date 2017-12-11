/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:19:05 by cfavero           #+#    #+#             */
/*   Updated: 2017/12/11 17:08:15 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define BUF_SIZE 4096

typedef	struct		s_list2
{
	int				x;
	int				y;
	char			c;
	struct s_list2	*next;
}					tet_list;

char		*source(char *file);
int			ft_check_pieces(char *s);
int			ft_check_piece(char *s);
char		*ft_convert_blocks(char *str);
char		**ft_strsplit(char const *s, char c);
char		**ft_create_grid(int pieces, int inc);
char		*ft_move(char *str);
tet_list	*add_lst(tet_list *list, int x, int y, char c);
void		print_list(tet_list *lst);
tet_list	*move_upleft(tet_list *tet_link);
tet_list	*convert_list(char *pieces_str);
int			ft_putblock(tet_list *blocks, char **grid);
char		**ft_solve(tet_list *blocks, char **grid, int pieces, int inc);

#endif
