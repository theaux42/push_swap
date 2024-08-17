# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/15 15:59:30 by tbabou            #+#    #+#              #
#    Updated: 2024/08/17 15:09:55 by tbabou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap
INC				= includes/
SRC_DIR				= src/
OBJ_DIR				= obj/

CC				= gcc -g
CFLAGS				= -Wall -Werror -Wextra -I
RM				= rm -f

COMMANDS_DIR			=	$(SRC_DIR)commands/push.c \
						$(SRC_DIR)commands/rev_rotate.c \
						$(SRC_DIR)commands/rotate.c \
						$(SRC_DIR)commands/sort_stacks.c \
						$(SRC_DIR)commands/sort_three.c \
						$(SRC_DIR)commands/swap.c \

PUSH_SWAP_DIR			=	$(SRC_DIR)push_swap/error.c \
						$(SRC_DIR)push_swap/a_2_b.c \
						$(SRC_DIR)push_swap/b_2_a.c \
						$(SRC_DIR)push_swap/push_swap.c \
						$(SRC_DIR)push_swap/split.c \
						$(SRC_DIR)push_swap/stack_init.c \
						$(SRC_DIR)push_swap/tools.c

			
SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)


OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all: 				$(NAME)

$(NAME): 			$(OBJ)
				@$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: 			$(SRC_DIR)%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@


clean:
					@$(RM) -r $(OBJ_DIR)

fclean: 			clean
				@$(RM) $(NAME)

re: 				fclean
				make all

.PHONY: 			start all clean fclean re