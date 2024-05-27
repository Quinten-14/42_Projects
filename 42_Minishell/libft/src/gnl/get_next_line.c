/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:38:07 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 00:03:38 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/get_next_line.h"

char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

char	*fetch_line(char *left_str)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_left_read(int fd, char *str)
{
	char	*buff;
	int		readed_bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readed_bytes = 1;
	while (!ft_strchr_gnl(str, '\n') && readed_bytes != 0)
	{
		readed_bytes = read(fd, buff, BUFFER_SIZE);
		if (readed_bytes == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[readed_bytes] = '\0';
		str = ft_strjoin_gnl(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	left_str = ft_left_read(fd, left_str);
	if (!left_str)
		return (NULL);
	line = fetch_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}
