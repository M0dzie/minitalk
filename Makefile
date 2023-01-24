# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 18:51:59 by thmeyer           #+#    #+#              #
#    Updated: 2023/01/24 09:24:41 by thmeyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOCOLOR= \033[0m
BGREEN = \033[1;32m

NAME_C = client
NAME_S = server
HEADER = minitalk.h

CC = cc
C_FLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = 

OBJS = $(SRCS:%.c=$(DIR_OBJS)%.o)

DIR_OBJS = Objs/
DIR_PRINTF = ft_printf/

PRINTF_A = $(DIR_PRINTF)libftprintf.a

all: directory rsc $(NAME)

$(NAME): $(PRINTF_A) $(OBJS)
	$(CC) $(C_FLAGS) -o $(NAME) $(OBJS)

rsc:
	@$(MAKE) -C $(DIR_PRINTF)

$(DIR_OBJS)%.o: %.c Makefile $(HEADER)
	$(CC) $(C_FLAGS) -o $@ -c $< 

clean:
	@$(MAKE) clean -C $(DIR_PRINTF)
	$(RM) $(OBJS)
	$(RM) $(DIR_OBJS)
	@echo "$(BGREEN)Clean done$(NOCOLOR)"
    
fclean: 
	@$(MAKE) fclean -C $(DIR_PRINTF)
	@$(MAKE) clean
	$(RM) $(NAME)
	@echo "$(BGREEN)Fclean done$(NOCOLOR)"

re: 
	@$(MAKE) fclean
	@$(MAKE) all

directory:
	@mkdir -p $(DIR_OBJS)

.PHONY: all clean fclean re