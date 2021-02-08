/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 12:12:13 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/05 17:29:16 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

void				ft_bzero(void *s, unsigned int n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memcpy(void *dest, const void *src, unsigned int n);
void				*ft_memmove(void *str1, const void *str2, unsigned int n);
void				*ft_memset(void *str, int c, unsigned int n);
unsigned int		ft_strlen(const char *str);
int					ft_tolower(int ch);
int					ft_toupper(int ch);
unsigned int		ft_strlcpy(char *dest, const char *src, unsigned int size);
int					ft_isascii(char c);
int					ft_atoi(const char *c);
void				*ft_memccpy(void *dest, const void *src, int c,
unsigned int n);
void				*ft_memchr(const void *s, int c,
unsigned int n);
int					ft_memcmp(const void *str1, const void *str2,
unsigned int n);
char				*ft_strchr(char *s, int c);
int					ft_strncmp(const void *str1, const void *str2,
unsigned int n);
char				*ft_strrchr(const char *str, int c);
unsigned int		ft_strlcat(char *dest, const char *src, unsigned int size);
char				*ft_strnstr(const char *str, const char *srch,
unsigned int n);
void				*ft_calloc(unsigned int nitems, unsigned int size);
char				*ft_strdup(const char *src);
char				*ft_substr(char const *s, unsigned int start,
unsigned int len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_abs(int num);
double				ft_fabs(double num);
void				ft_sort_index(double *dis, int *ord, int size);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)
(void *), void (*del)(void *));

#endif
