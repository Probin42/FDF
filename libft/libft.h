/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <rweiss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:28:39 by rweiss            #+#    #+#             */
/*   Updated: 2017/04/21 15:48:11 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <ctype.h>
# include <strings.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

int					ft_atoi(const char *str);
void				ft_bzero(void *str, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *a, const void *b, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t nb);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *a, const char *b, size_t n);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
size_t				ft_strlcat(char *dst, const char *src, size_t n);
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
char				*ft_strnjoin(const char *s1, const char *s2, size_t n);
double				ft_clamp(double x, double min, double max);
double				ft_mix(double x, double y, double a);
double				veclenght(t_vec3 *vec);
void				vecnorm(t_vec3 *vec);
double				vecdot(t_vec3 *a, t_vec3 *b);
t_vec3				veccross(t_vec3 *a, t_vec3 *b);
t_vec3				vecsub(t_vec3 *a, t_vec3 *b);
t_vec3				vecopplus(t_vec3 *a, double x);
t_vec3				vecopdiv(t_vec3 *a, double x);
t_vec3				vecdiv(t_vec3 *a, t_vec3 *b);
t_vec3				vecreflect(t_vec3 *i, t_vec3 *n);
t_vec3				vecadd(t_vec3 *a, t_vec3 *b);
t_vec3				vecprod(t_vec3 *a, t_vec3 *b);
t_vec3				vecopx(t_vec3 *a, double x);
void				vecclamp(t_vec3 *vec, double a, double b);
double				vecdistance(t_vec3 *a, t_vec3 *b);
#endif
