# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 16:42:14 by jocuni-p          #+#    #+#              #
#    Updated: 2024/07/16 15:53:09 by jocuni-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*****************VAR DEFINITIONS*******************

NAME	:=	philo

INC_DIR := inc/
SRC_DIR := src/
OBJ_DIR := obj/
SRC		:=	main.c \
			arg_init.c \
			arg_parsing.c \
			check_finish.c \
			cleaner.c \
			ft_exit.c \
			get_time.c \
			getters.c \
			pass_time.c \
			philo_eating.c \
			philo_init.c \
			philo_print.c \
			philo_start.c \
			setters.c \
			thread.c
			
OBJ		:=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEP 	:=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.d))
INCLUDE	:=	-I $(INC_DIR)
RM		:=	rm -rf
CC		:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra -pthread


#************************RULES**************************

all	: $(NAME)

-include $(DEP)

$(NAME) : $(OBJ) Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c $(INC_DIR)/*.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -MMD -c $< -o $@

clean	:
	$(RM) $(OBJ_DIR) $(DEP)

fclean	: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY	: all clean fclean re
