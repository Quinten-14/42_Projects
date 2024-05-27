/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:13:15 by qraymaek          #+#    #+#             */
/*   Updated: 2023/11/23 11:34:40 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/get_next_line.h"
#include "../include/libft.h"

t_map	init_map_struct(void)
{
	t_map	map;

	map.width = 0;
	map.height = 0;
	return (map);
}

int	open_map(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		return (0);
	}
	return (fd);
}

void	free_values(char **values)
{
	int	i;

	i = 0;
	while (values[i] != NULL)
	{
		free(values[i]);
		i++;
	}
	free(values);
}

// line = get_next_line should be somewhere else
t_map	get_sizes(char *file)
{
	int		fd;
	char	*line;
	t_map	map;
	char	**values;

	map = init_map_struct();
	fd = open_map(file);
	while (fd != 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map.height++;
		if (map.width == 0)
		{
			values = ft_split(line, ' ');
			while (values[map.width])
				map.width++;
			free_values(values);
		}
		free(line);
	}
	close(fd);
	return (map);
}
