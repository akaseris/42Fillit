/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:19:05 by cfavero           #+#    #+#             */
/*   Updated: 2017/12/20 13:03:14 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define BUF_SIZE 1000

typedef struct		s_list2
{
	int				x;
	int				y;
	char			c;
	struct s_list2	*next;
}					t_tet;

char				*ft_source(char *file);
int					ft_check_pieces(char *s);
int					ft_check_piece(char *s);
char				*ft_convert_blocks(char *str);
char				**ft_strsplit(char const *s, char c);
char				**ft_create_grid(int pieces, int inc);
t_tet				*ft_add_lst(t_tet *list, int x, int y, char c);
t_tet				*ft_move_upleft(t_tet *tet_link);
t_tet				*ft_convert_list(char *pieces_str);
int					ft_putblock(t_tet *blocks, char **grid, int ign);
char				**ft_solve(t_tet *blocks, char **grid, int pieces,
	int inc);
char				**ft_erase_block(char **grid, char c);
int					ft_solve_opt(t_tet *blocks, t_tet *initial, char **grid,
	int ign);

#endif
