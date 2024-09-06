# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 10:26:42 by bruda-si          #+#    #+#              #
#    Updated: 2024/09/06 14:19:33 by bruda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	push_swap

INC				=	inc/
SRC_DIR			=	src/
OBJ_DIR			=	obj/
LIBFT			=	./libft/libft.a

CC				=	cc
CFLAGS			=	-Werror -Wextra -Wall -g -I
RM				=	rm -f

COMMAND_DIR		=	$(SRC_DIR)commands/rev_rotate.c \
					$(SRC_DIR)commands/push.c \
					$(SRC_DIR)commands/rotate.c \
					$(SRC_DIR)commands/sort_stack.c \
					$(SRC_DIR)commands/sort_three.c \
					$(SRC_DIR)commands/swap.c 
					
PUSH_SWAP_DIR 	=	$(SRC_DIR)push_swap/push_swap.c \
					$(SRC_DIR)push_swap/handle_errors.c \
					$(SRC_DIR)push_swap/init_a_to_b.c \
					$(SRC_DIR)push_swap/init_b_to_a.c \
					$(SRC_DIR)push_swap/stack_init.c \
					$(SRC_DIR)push_swap/stack_utils.c
					
SRCS			=	$(COMMAND_DIR) $(PUSH_SWAP_DIR)

OBJ				=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
			
start:
					make all 
					
$(LIBFT):
					make -C ./libft

all:				$(NAME) 

$(NAME):			$(OBJ) $(LIBFT)
					$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					mkdir -p $(@D)
					$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean:				clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re:					fclean all

.PHONY:				start all clean fclean re