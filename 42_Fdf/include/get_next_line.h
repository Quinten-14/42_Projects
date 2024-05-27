/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:38:31 by qraymaek          #+#    #+#             */
/*   Updated: 2023/11/23 11:37:38 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_left_read(int fd, char *str);
char	*fetch_line(char *left_str);
char	*ft_new_left_str(char *left_str);
char	*ft_strjoin_gnl(char *left_str, char *buff);
char	*ft_strchr_gnl(char *str, int c);
size_t	ft_strlen_gnl(char *str);

#endif
