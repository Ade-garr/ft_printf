/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:54:24 by ade-garr          #+#    #+#             */
/*   Updated: 2020/01/31 13:15:54 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
int					ft_checkconv(char c);
int					ft_printf(const char *format, ...);
int					ft_conversion(va_list ap, const char *format, int i);
int					ft_conversion_c(va_list ap, const char *format, int i);
int					ft_printconvc(va_list ap, int width);
int					ft_findwidth(va_list ap, const char *format, int i);
int					ft_conversion_s(va_list ap, const char *format, int i);
int					ft_findprecision(va_list ap, const char *format, int i);
int					ft_printconvsgauche(int width, int precision, char *s);
int					ft_printconvsdroite(int width, int precision, char *s);
void				ft_convert_hex(unsigned long p, char *base);
int					ft_conversion_p(va_list ap, const char *format, int i);
int					ft_findlong_j(int j);
void				ft_putnbr(int j);
int					ft_printconvdileft(int width, int precision, int j);
int					ft_conversion_di(va_list ap, const char *format, int i);
int					ft_printconvdiright2(int width, int precision, int j);
int					ft_printconvdiright(int width,
					int precision, int j, int flag_0);
int					ft_conversion_u(va_list ap, const char *format, int i);
int					ft_findlong_uj(unsigned int j);
void				ft_putunbr(unsigned int j);
int					ft_printconvuleft(int width, int precision, unsigned int j);
int					ft_printconvuright(int width, int precision,
					unsigned int j, int flag_0);
int					ft_conversion_x(va_list ap, const char *format,
					int i, int k);
int					ft_findlong_xj(unsigned long j);
int					ft_printconvxleft(int width, int precision,
					unsigned int j, int k);
int					ft_printconvxright1(int width, unsigned int j, int k);
int					ft_printconvxright2(int width, int precision,
					unsigned int j, int k);
int					ft_checkflag_0(const char *format, int i);
int					ft_conversion_percent(va_list ap,
					const char *format, int i);

#endif
