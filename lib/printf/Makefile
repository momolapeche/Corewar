#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opicher <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/08 14:38:34 by opicher           #+#    #+#              #
#    Updated: 2017/03/31 16:28:14 by tguttin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

FCT = ft_printf.c ft_ptf_idenval.c ft_ptf_idenval2.c ft_ptf_err.c ft_ptf_flag.c\
	ft_ptf_setlarg.c ft_ptf_setprec.c ft_ptf_utf8.c ft_ptf_indic_cplt.c \
	ft_ptf_curflag_init.c ft_ptf_isindic.c ft_ptf_isflag.c ft_ptf_ismodif.c \
	ft_ptf_freecur.c ft_ptf_checkvalid.c ft_ptf_color.c ft_ptf_extended.c

FCT_O = $(FCT:.c=.o)

INC = ../includes/

LIB = ../libft/

#FLAG = -Wall -Wextra -Werror
FLAG = -Wall -Wextra

GREEN = \033[4;32m

RED = \033[31m

NC = \033[0m

all : $(NAME)

%.o : %.c
	@gcc $(FLAG) -o $@ -c $< -I $(INC)

perso: main.c $(FCT_O)
	@make -C $(LIB) fclean
	@make -C $(LIB)
	@gcc -o persotest main.c $(FCT_O) -L ./libft/ -lft -I $(INC)

$(NAME) : $(FCT_O)
	@make -C $(LIB)
	@ar rc $(NAME) $(FCT_O) ../libft/*.o
	@echo "$(GREEN)Printf lib fonction compiled. OK$(NC)"

clean :
	@rm -f $(FCT_O)
	@make -C $(LIB) clean
	@echo "$(RED) Lib cleaned $(NC)"

fclean : clean
	@rm -f $(NAME)
	@make -C $(LIB) fclean
	@echo "$(RED) Lib fcleaned $(NC)"

re : fclean $(NAME)
