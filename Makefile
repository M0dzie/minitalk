# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 18:51:59 by thmeyer           #+#    #+#              #
#    Updated: 2023/01/24 17:34:27 by thmeyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOCOLOR= \033[0m
BGREEN = \033[1;32m

NAME_C = $(DIR_CLT)client
NAME_S = $(DIR_SRV)server

CC = cc
C_FLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS_S = server.c
SRCS_C = client.c

OBJS_S = $(SRCS_S:%.c=$(DIR_SRV)%.o)
OBJS_C = $(SRCS_C:%.c=$(DIR_CLT)%.o)

DIR_OBJS = Objs/
DIR_PRINTF = ft_printf/
DIR_CLT = client/
DIR_SRV = server/

PRINTF_A = $(DIR_PRINTF)libftprintf.a

all: directory rsc $(NAME_S) $(NAME_C)

$(NAME_S): $(PRINTF_A) $(OBJS_S)
	$(CC) $(C_FLAGS) -o $(NAME_S) $(OBJS_S) $(PRINTF_A)

$(DIR_SRV)%.o: %.c Makefile
	$(CC) $(C_FLAGS) -o $@ -c $< 

$(NAME_C): $(PRINTF_A) $(OBJS_C)
	$(CC) $(C_FLAGS) -o $(NAME_C) $(OBJS_C) $(PRINTF_A)
	
$(DIR_CLT)%.o: %.c Makefile
	$(CC) $(C_FLAGS) -o $@ -c $< 

rsc:
	@$(MAKE) -C $(DIR_PRINTF)

clean:
	@$(MAKE) clean -C $(DIR_PRINTF)
	$(RM) $(OBJS_S)
	$(RM) $(OBJS_C)
	$(RM) $(DIR_OBJS)
	@echo "$(BGREEN)Clean done$(NOCOLOR)"
    
fclean: 
	@$(MAKE) fclean -C $(DIR_PRINTF)
	@$(MAKE) clean
	$(RM) $(NAME_S)
	$(RM) $(NAME_C)
	@echo "$(BGREEN)Fclean done$(NOCOLOR)"

re: 
	@$(MAKE) fclean
	@$(MAKE) all

directory:
	@mkdir -p $(DIR_OBJS)

.PHONY: all clean fclean re