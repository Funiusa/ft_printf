# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/13 15:27:02 by tevelyne          #+#    #+#              #
#    Updated: 2021/01/15 20:29:07 by tevelyne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEAD = ft_printf.h

LIBFT = libft/libft.a

SRC =	ft_printf.c put_utilitis.c modifiers.c\
 	types.c type_sc.c print_t_cs.c parser.c\
 	print_t_diux.c print_t_dui_flagmin.c print_t_p.c

SOURCE_DIR = libft/libft.a

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -f

.c.o:
	$(CC) $(FLAGS) -I $(HEAD) -c $< -o $(<:.c=.o)
all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

include $(wildcard $(D_FILES))

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
