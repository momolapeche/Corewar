#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opicher <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/12 11:37:57 by opicher           #+#    #+#              #
#    Updated: 2017/04/01 21:23:55 by opicher          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = asm

FCT = srcs/main.c \
	srcs/ft_readchamp.c \
	srcs/ft_writechamp.c \
	srcs/ft_writenbr.c \
	srcs/ft_writename.c \
	srcs/ft_writecom.c \
	srcs/ft_trad.c \
	srcs/ft_algotrad.c \
	srcs/ft_isparam.c \
	srcs/ft_checkchamp.c \
	srcs/ft_labelsize.c \
	srcs/ft_strsplit_whitespaces.c \
	srcs/ft_islabel.c \
	srcs/ft_chrlabel.c \
	srcs/strsplit_separator.c \
	srcs/ft_atoi_ll.c \
	srcs/check_champion_body.c \
	srcs/check_champion_header.c \
	srcs/check_opline.c \
	srcs/check_param.c \
	srcs/check_separator.c \
	srcs/ft_small_str.c \
	srcs/ft_tool.c \
	srcs/print_err.c \
	srcs/search_missing_data.c \
	srcs/tab_tool.c \
	srcs/type_first_word.c \
	srcs/save_param.c \
	srcs/check_label.c \
	srcs/check_tag.c \
	srcs/ft_skip_empty_champ.c \
	srcs/ft_free4all.c \
	srcs/check_header_tag.c \
	srcs/ft_writedefbin.c \
	srcs/ft_strsplit_spacescom.c \
	srcs/ft_new_param.c \

SRC = srcs

FCT_O = $(FCT:%.c=%.o)

INC = -I ./includes/ -I ../lib/includes/

LIB = ../lib/printf/

FLAG = -Wall -Wextra -Werror

GREEN = \033[4;32m

RED = \033[31m

NC = \033[0m

all : $(NAME)

$(SRC)/%.o : $(SRC)/%.c
	@gcc $(FLAG) -o $@ $(INC) -c $<

$(NAME) : $(FCT_O)
	@make -C $(LIB)
	@gcc -o $(NAME) $(FCT_O) -L $(LIB) -lftprintf
	@echo "$(GREEN)$(NAME) Compiled$(NC)"

clean :
	@rm -f $(FCT_O)
	@make -C $(LIB) clean
	@echo "$(RED) Function of $(NAME) cleaned$(NC)"

fclean : clean
	@rm -f $(NAME)
	@make -C $(LIB) fclean
	@echo "$(RED) Function of $(NAME) fcleaned$(NC)"

re : fclean $(NAME)
