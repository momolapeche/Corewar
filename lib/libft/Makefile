# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opicher <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 16:06:33 by opicher           #+#    #+#              #
#    Updated: 2017/03/31 16:27:51 by tguttin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FCT = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
ft_isprint.c ft_isspace.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c\
ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_pow.c\
ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c\
ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c\
ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c\
ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c\
ft_toupper.c ft_lstlen.c ft_strcuto.c ft_strlento.c ft_strcpyto.c ft_lstadd_back.c\
ft_itoa_base.c ft_atoi_base.c ft_intlen.c ft_strjoinndel.c get_next_line.c\
ft_realloc.c ft_motdec.c ft_putwchar.c ft_itoa_ubase.c ft_ftoa.c ft_lstchr.c\
ft_stristr.c

FCT_O = $(FCT:.c=.o)

NAME = libft.a

INCL = ../includes/

GREEN = \033[4;32m

RED = \033[31m

NC = \033[0m

all: $(NAME)

%.o : %.c
	@gcc -Wall -Wextra -o $@ -c $< -I $(INCL)
#	@gcc -Wall -Werror -Wextra -o $@ -c $< -I $(INCL)

$(NAME): $(FCT_O)
	@ar rc $(NAME) $(FCT_O)
	@echo "$(GREEN)Basic Libft fonction compiled. OK$(NC)"

clean:
	@rm -f $(FCT_O)

fclean: clean
	@rm -f $(NAME)

re : fclean $(NAME)
