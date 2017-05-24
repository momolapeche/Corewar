#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opicher <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/08 16:26:49 by opicher           #+#    #+#              #
#    Updated: 2017/04/02 19:55:46 by opicher          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = corewar

FCT = srcs/main.c srcs/analyze_data.c srcs/vm.c srcs/cor_error.c srcs/tools.c \
	srcs/instructions.c srcs/check_args.c srcs/treat_fct_args.c \
	srcs/kill_process.c srcs/instructions_2.c srcs/instructions_3.c \
	srcs/vm_tools.c srcs/vm_tools_2.c srcs/print_arena.c srcs/sdl_fcts.c \
	srcs/sdl_fcts_2.c

SRC = srcs

FCT_O = $(FCT:%.c=%.o)

INC = -I ./includes/ -I ../lib/includes/

LIB = ../lib/

FLAG = -Wall -Wextra -Werror

GREEN = \033[4;32m

RED = \033[31m

NC = \033[0m

LIBS = -L $(LIB)printf/ -lftprintf -L$(LIB)libft/ -lft $(INC)

all : $(NAME)

framework:
	@cp -rf frameworks/Frameworks ~/Library

$(SRC)/%.o : $(SRC)/%.c
	@gcc $(FLAG) -o $@ -c $< $(INC) -I ~/Library/Frameworks/SDL2.framework/Headers -I ~/Library/Frameworks/SDL2_ttf.framework/Headers

$(NAME) : framework $(FCT_O)
	@make -C $(LIB)/printf
	@gcc -o $(NAME) $(FCT_O) $(LIBS) -F ~/Library/Frameworks -framework SDL2 -framework SDL2_ttf
	@echo "$(GREEN)$(NAME) Compiled$(NC)"

clean :
	@rm -f $(FCT_O)
	@make -C $(LIB)printf/ clean
	@echo "$(RED) Function of $(NAME) cleaned$(NC)"

fclean : clean
	@rm -rf ~/Library/Frameworks
	@rm -f $(NAME)
	@make -C $(LIB)printf/ fclean
	@echo "$(RED) Function of $(NAME) fcleaned$(NC)"

re : fclean $(NAME)

project: $(FCT_O)
	gcc $(FCT_O) -o $(NAME) $(LIBS)
