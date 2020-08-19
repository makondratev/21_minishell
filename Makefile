# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azomega <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/27 18:33:07 by azomega           #+#    #+#              #
#    Updated: 2020/08/16 20:40:25 by azomega          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS :=	main.c	\
		ft_get_path.c \
		ft_run.c \
		ft_get_env.c \
		ft_env.c \
		ft_is_env_name_ok.c \
		ft_strget_token.c \
		ft_setenv.c \
		ft_unsetenv.c \
		ft_echo.c \
		ft_update_env.c \
		ft_matrix.c \
		ft_exit.c \
		ft_print_error.c \
		ft_check_rights.c \
		ft_mini_gnl.c \
		ft_parse_line.c \
		ft_strsplit_set_quotes.c \
		ft_strremove_char.c \
		ft_expand_tilda.c \
		ft_expand_dollar.c \
		ft_hm_as_arr.c \
		ft_execute_path.c \
		ft_is_builtin.c \
		ft_strjoin3.c \
		ft_del_env.c \
		ft_cd.c \
		ft_init_env.c

SRC_DIR := ./src

LIB_DIR := ./libft

INC := -I includes/ -I libft/includes/

HEAD = \
          includes/minishell.h \
          includes/errors.h \
          includes/env.h

OBJ_DIR := ./obj

CMP_DIR	:= $(OBJ_DIR)/print

OBJ	:= $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

#CFLAGS	:= -g 
CFLAGS	:= -Wall -Wextra -Werror

LFLAGS	:= -L $(LIB_DIR) -lft

NAME = minishell

.PHONY: all clean lib fclean re

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) | lib
	gcc -o $(NAME) $(OBJ) $(LFLAGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(CMP_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEAD)
	gcc $(CFLAGS) $(INC) -o $@ -c $<

lib:
	make -C $(LIB_DIR)

clean:
	rm -rf $(OBJ_DIR) $(CMP_DIR)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all
