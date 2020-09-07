# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 12:53:57 by alexzudin         #+#    #+#              #
#    Updated: 2020/09/03 15:05:08 by alexzudin        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main_checker.c readfunc.c parsecommands.c validation.c commands.c

SRC_DIR = src/

PRINTF_H =	-I includes/
PRINTF_HL =	-I libft/


SRCS=$(addprefix $(SRC_DIR), $(SRC))

NAME = libftprintf.a

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) 
	cd libft && $(MAKE) all
	gcc -Wall -Wextra -Werror -ggdb -o checker $(OBJ) ./libft/libft.a

%.o:%.c
	gcc -Wall -Wextra -Werror -ggdb $(PRINTF_H) $(PRINTF_HL) -c $< -o $@

clean:
	@cd libft && $(MAKE) clean	
	@/bin/rm -f $(OBJ)
	@/bin/rm -f checker

fclean: clean
	@cd libft && $(MAKE) fclean
	@/bin/rm -f $(NAME)

re: fclean  all 

