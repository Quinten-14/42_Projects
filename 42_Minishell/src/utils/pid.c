/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:26:09 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:26:10 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

static char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			++j;
		}
		++i;
	}
	return (0);
}

char	*get_process_id(void)
{
	char	buffer[256];
	int		fd;
	char	*pidstr;
	char	*end;

	fd = open("/proc/self/status", O_RDONLY);
	if (fd == -1)
		return (perror("Error opening /proc/self/status"), "268601");
	read(fd, buffer, sizeof(buffer));
	close(fd);
	pidstr = ft_strstr(buffer, "Pid:");
	if (pidstr != NULL)
	{
		pidstr += 5;
		while (*pidstr == ' ')
			pidstr++;
		end = pidstr;
		while (*end != '\n')
			end++;
		*end = '\0';
		return (ft_strdup(pidstr));
	}
	return ("268601");
}
