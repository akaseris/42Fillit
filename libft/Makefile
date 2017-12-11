# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaseris <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:05:02 by akaseris          #+#    #+#              #
#    Updated: 2017/12/11 16:56:18 by akaseris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FT = ft_putchar ft_putstr ft_strcmp ft_strlen ft_strdup ft_strcpy ft_strcat \
		ft_strncat ft_strlcat ft_strstr ft_strncmp ft_atoi ft_toupper \
		ft_tolower ft_putnbr ft_isalpha ft_isdigit ft_isprint ft_itoa \
		ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr \
		ft_memcmp ft_strncpy ft_strchr ft_strrchr ft_strnstr ft_isalnum \
		ft_isascii ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr \
		ft_striter ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ \
		ft_strsub ft_strjoin ft_strtrim ft_strsplit ft_putendl ft_putchar_fd \
		ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew ft_lstdelone \
		ft_lstdel ft_lstadd ft_lstiter  ft_lstmap ft_isprime ft_sqrt \
		ft_sortwordtab ft_advancedsortwordtab ft_swap ft_printwordstables

FLAGS = -Wall -Werror -Wextra

FT_C = $(patsubst %,%.c,$(FT))

FT_O = $(patsubst %,%.o,$(FT))

.PHONY: all clean fclean re

all: $(NAME)

$(FT_O): 
	gcc $(FLAGS) -c $(FT_C)

$(NAME): $(FT_O)
		ar rc $(NAME) $(FT_O)
		ranlib $(NAME)

clean:
	/bin/rm -f $(FT_O)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

