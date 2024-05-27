/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:06:10 by wmarien           #+#    #+#             */
/*   Updated: 2024/05/08 14:58:57 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

/*********************/
/*                   */
/*       MACROS      */
/*                   */
/*********************/

//fetch this library if it gets called
# define LIBFT_H

//set buffer size if not defined
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

/*********************/
/*                   */
/*     LIBRARIES     */
/*                   */
/*********************/

//write
# include <unistd.h>

//malloc, free
# include <stdlib.h>

/*********************/
/*                   */
/*     STRUCTURES    */
/*                   */
/*********************/

//singly linked list
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*********************/
/*                   */
/*     FUNCTIONS     */
/*                   */
/*********************/

/************/
/*   void   */
/************/

//reset memory values to 0
void	ft_bzero(void *s, size_t n);

//perform a function on each character within a string
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

//create a singly linked list entry at the end
void	ft_lstadd_back(t_list **lst, t_list *new);

//create a singly linked list entry at the front
void	ft_lstadd_front(t_list **lst, t_list *new);

//perform a delete function on each entry in a singly linked list
void	ft_lstclear(t_list **lst, void (*del)(void*));

//delete a singly linked list entry
void	ft_lstdelone(t_list *lst, void (*del)(void*));

//perform a function on each entry in a singly linked list
void	ft_lstiter(t_list *lst, void (*f)(void*));

//write a character to a file descriptor
void	ft_putchar_fd(char c, int fd);

//write a string to a file descriptor followed by a newline
void	ft_putendl_fd(char *s, int fd);

//write an integer to a file descriptor
void	ft_putnbr_fd(int n, int fd);

//write a string to a file descriptor
void	ft_putstr_fd(char *s, int fd);

//free the memory of a 2d array
void	free_arr(void **arr);

//free the memory of an int array
void	free_int_arr(int **arr, size_t size);

/***************/
/*   pointer   */
/***************/

//allocate memory and initialize values to 0
void	*ft_calloc(size_t nmeb, size_t size);

//set the values of a memory area
void	*ft_memset(void *s, int c, size_t n);

//copy a memory area
void	*ft_memcpy(void *dst, const void *src, size_t n);

//move a memory area (safer, yet slower, version of ft_memcpy)
void	*ft_memmove(void *dst, const void *src, size_t n);

//search for a value within a memory area
void	*ft_memchr(const void *s, int c, size_t n);

/***************/
/*   integer   */
/***************/

//check if given character is alphabetical
int		ft_isalpha(int c);

//check if given character is a digit
int		ft_isdigit(int c);

//check if given string contains only digits
int		strisdigit(char *str);

//check if given character is alphanumeric
int		ft_isalnum(int c);

//check if given character is a valid ASCII character
int		ft_isascii(int c);

//check if given character is printable
int		ft_isprint(int c);

//check if given character is any form of whitespace
int		ft_isspace(char c);

//convert lowercase letters to uppercase
int		ft_toupper(int c);

//convert uppercase letters to lowercase
int		ft_tolower(int c);

//calculate the difference between memory areas
int		ft_memcmp(const void *s1, const void *s2, size_t n);

//compare two strings, but smarter
int		ft_strcmp(const char *s1, const char *s2);

//compare two strings
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//convert a string to an integer
int		ft_atoi(const char *nptr);

//calculate the absolute value of an integer
int		ft_abs(int nb);

//calculate the number of entries in a singly linked list
int		ft_lstsize(t_list *lst);

//file name validation
int		extension_checker(char *file_name, char *extension);

// Fetch character position in a map
int		get_c_pos(char **map, char c, int *my, int *mx);

/**************/
/*   size_t   */
/**************/

//calculate the length of a string
size_t	ft_strlen(const char *s);

//copy a string
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

//append one string to another
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/********************************/
/*   character array (string)   */
/********************************/

//convert an integer to a string
char	*ft_itoa(int n);

//search for a character within a string
char	*ft_strchr(const char *s, int c);

//search for a character within a string (gnl)
char	*ft_strchr_gnl(char *s, int c);

//duplicate a string
char	*ft_strdup(const char *s);

//join two strings together into one and free the input
char	*strjoin(const char *s1, const char *s2);

//join two strings together into one
char	*ft_strjoin(const char *s1, const char *s2);

//join two strings together into one (gnl)
char	*ft_strjoin_gnl(char *line, char *buff);

//perform a function on each character within a string
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

//search for a string within a string
char	*ft_strnstr(const char *big, const char *little, size_t len);

//reverse search for a character within a string
char	*ft_strrchr(const char *s, int c);

//search for and remove a set of characters at the head and tail of a string
char	*ft_strtrim(const char *s1, const char *set);

//replace a string within another string with yet another string (stringception)
char	*ft_substr(const char *s, unsigned int start, size_t len);

//parse a file descriptor and return the next line
char	*get_next_line(int fd);

/************************************************************/
/*   array of character arrays (2d array or string array)   */
/************************************************************/

//split a string on a delimiter into a 2d array
char	**ft_split(const char *s, char c);

//copy a 2d array
char	**cpy_arr(char **arr);

//join two strings into an array
char	**mk_arr(char *s1, char *s2);

//resize the memory of a 2d array
char	**resize_arr(char **arr, size_t y);

/*****************/
/*   structure   */
/*****************/

//fetch the last entry in a singly linked list
t_list	*ft_lstlast(t_list *lst);

//perform a function on each entry of a singly linked list
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//create a singly linked list
t_list	*ft_lstnew(void	*content);

#endif
