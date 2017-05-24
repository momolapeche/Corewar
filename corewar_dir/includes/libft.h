/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:17:29 by tguttin           #+#    #+#             */
/*   Updated: 2016/12/14 14:42:06 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define ENDL ft_putchar('\n')

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlen(const char *src);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, int n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *src, int c);
char				*ft_strrchr(const char *src, int c);
char				*ft_strstr(const char *src, const char *to_find);
char				*ft_strnstr(const char *src, const char *n, size_t len);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t c);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t c);
char				*ft_strdup(const char *str);
void				*ft_memset(void *tab, int to_put, size_t n);
void				ft_bzero(void *tab, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void	*src, int c, size_t n);
int					ft_memcmp(const void *str, const void *str1, size_t n);
int					ft_atoi(const char *to_turn);
char				*ft_itoa(intmax_t n);
void				ft_putchar(char c);
void				ft_putstr(char *src);
void				ft_strclr(char *str);
void				ft_putendl(const char *str);
void				ft_putnbr(int to_print);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **data);
char				*ft_strnew(size_t size);
void				ft_striter(char *str, void (*fct)(char *));
void				ft_striteri(char *str, void (*fct)(unsigned int, char *));
char				*ft_strmap(const char *str, char (*fct)(char));
char				*ft_strmapi(const char *str, char (*f)(unsigned int, char));
int					ft_strequ(const char *str, const char *str1);
int					ft_strnequ(const char *str, const char *str1, size_t n);
char				*ft_strsub(const char *str, unsigned int start, size_t len);
char				*ft_strjoin(const char *str, const char *str1);
char				*ft_strtrim(const char *str);
void				ft_strdel(char **as);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putendl_fd(const char *str, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_strsplit(const char *str, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t c));
void				ft_lstadd(t_list **alst, t_list *n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_isnull(const char *str);
void				ft_lstaddend(t_list **link, t_list *new);
int					ft_isblank(int c);
char				*ft_strswap(const char *src);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_strlenchar(char *str, char c);
int					ft_wstrlen(wchar_t *s);
char				*ft_itoa_base(int nb, int base);
char				*itoa_base_ull(uintmax_t nbr, int base);
int					ft_pow(int nb, int exposant);
void				ft_printmem(char *str, int amount);
void				ft_printmem_fd(char *str, int amount, int fd);
void				ft_memncat(char *dest, char *src, int d_size, int s_size);
long long			ft_atoll(const char *str);
void				ft_putll(long long n);
void				put_inttab(int *tab, int size);
int					get_next_line(int fd, char **str);

#endif
