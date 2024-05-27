/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:16:02 by qraymaek          #+#    #+#             */
/*   Updated: 2023/11/24 23:50:37 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalnum(int i);
int					ft_isalpha(int i);
int					ft_isdigit(int i);
int					ft_isascii(int i);
int					ft_isprint(int i);
int					ft_toupper(int i);
int					ft_tolower(int i);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlen(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int i);
char				*ft_strrchr(const char *s, int i);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
long				ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_putchar_printf(char c, size_t *counter);
void				ft_putstring_printf(char *str, size_t *counter);
size_t				ft_len(unsigned long long n, char *base);
char				*ft_outputhex_printf(unsigned long long n, char *base);
void				ft_putpointer_printf(void *ptr, size_t *counter);
void				ft_putnumber_printf(int number, size_t *counter);
void				ft_putunsignedint_printf(unsigned int number,
						size_t *counter);
void				ft_puthex_printf(unsigned int number, size_t *counter,
						char *base);
void				ft_formatter(va_list va, char *str, size_t *counter);
int					ft_printf(const char *str, ...);
int					is_bit_set(unsigned int nbr, int pos);
unsigned int		clear_bit(unsigned int nbr, int pos);
unsigned int		set_bit(unsigned int nbr, int pos);
unsigned int		toggle_bit(unsigned int nbr, int pos);

#endif
