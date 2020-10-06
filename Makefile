# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 12:53:57 by alexzudin         #+#    #+#              #
#    Updated: 2020/10/05 14:48:49 by alexzudin        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_CHECKER = main_checker.c readfunc.c parsecommands.c validation.c \
			commands.c readfunc_p2.c visual.c

SRC_SWAP = main_push_swap.c readfunc.c parsecommands.c validation.c \
			commands.c solver.c output.c sort.c sort_p2.c readfunc_p2.c \
			solv_p2.c visual.c

SRC_DIR = src/

PUSH_H =	-I includes/
PUSH_HL =	-I libft/


SRCS_CHECKER=$(addprefix $(SRC_DIR), $(SRC_CHECKER))

SRCS_SWAP=$(addprefix $(SRC_DIR), $(SRC_SWAP))

NAME_CHECKER = checker

NAME_SWAP = push_swap

OBJ_CHECKER = $(SRCS_CHECKER:%.c=%.o)

OBJ_SWAP = $(SRCS_SWAP:%.c=%.o)

all: lib $(NAME_CHECKER) $(NAME_SWAP)

$(NAME_CHECKER): $(OBJ_CHECKER)
	gcc -Wall -Wextra -Werror -ggdb -o checker $(OBJ_CHECKER) ./libft/libft.a

$(NAME_SWAP): $(OBJ_SWAP)
	gcc -Wall -Wextra -Werror -ggdb -o push_swap $(OBJ_SWAP) ./libft/libft.a

lib:
	cd libft && $(MAKE) all

%.o:%.c
	gcc -Wall -Wextra -Werror -ggdb $(PUSH_H) $(PUSH_HL) -c $< -o $@

clean:
	@cd libft && $(MAKE) clean	
	@/bin/rm -f $(OBJ_SWAP) $(OBJ_CHECKER)

fclean: clean
	@cd libft && $(MAKE) fclean
	@/bin/rm -f $(NAME_SWAP) $(NAME_CHECKER)

re: fclean  all 

