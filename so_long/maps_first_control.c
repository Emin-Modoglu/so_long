/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_first_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:55:15 by emmodogl          #+#    #+#             */
/*   Updated: 2023/10/13 11:18:01 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	maps_object_control(t_so_long *data)
{
	if (data->count_p != 1 || data->count_c == 0 || data->count_e != 1)
		return (ft_printf("missing character on map\n"), free_map(data));
	if (data->map_height == data->map_width)
		return (ft_printf("Not a rectangular map!!!\n"), free_map(data));
}

void	maps_player_control(t_so_long *data, int x, int y)
{
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == '1' || data->map[y][x] == '0'
				|| data->map[y][x] == 'C' || data->map[y][x] == 'E'
				|| data->map[y][x] == 'P')
			{
				if (data->map[y][x] == 'P')
				{
					data->player_y = y;
					data->player_x = x;
					data->count_p++;
				}
				if (data->map[y][x] == 'C')
					data->count_c++;
				if (data->map[y][x] == 'E')
					data->count_e++;
			}
			else
				return (ft_printf("Player--error\n"), free_map(data));
		}
	}
	maps_object_control(data);
}

void	maps_wall_control(t_so_long *data, int x, int y)
{
	if (data->map[++y])
		while (data->map[y][++x])
			if (data->map[y][x] != '1')
				return (ft_printf("Error -->Wall 1\n"), free_map(data));
	x = -1;
	while (data->map[data->map_height - 2][++x])
		if (data->map[data->map_height - 2][x] != '1')
			return (ft_printf("Error -->Wall 2\n"), free_map(data));
	while (y <= data->map_height - 2 && data->map[y][0])
	{
		if (data->map[y][0] != '1')
			return (ft_printf("Error -->Wall 3\n"), free_map(data));
		y++;
	}
	y = -1;
	while (++y <= data->map_height - 2 && data->map[y][data->map_width - 2])
		if (data->map[y][data->map_width - 2] != '1')
			return (ft_printf("Error --> Wall 4\n"), free_map(data));
	maps_player_control(data, -1, -1);
}

void	maps_split_control(t_so_long *data, char *str)
{
	data->map = ft_split(str, '\n');
	if (!data->map)
		return (ft_printf("Not opened map"), free(str), exit(1));
	maps_wall_control(data, -1, -1);
	maps_path_control(data, ft_split(str, '\n'));
	free(str);
}

void	maps_read_control(t_so_long *data, char *str)
{
	int		fd;
	char	*line;
	char	*tmp_map;
	char	*tmp_tmp_map;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_printf("OPEN FILE error\n"), exit(1));
	line = get_next_line(fd);
	if (!line)
		return (ft_printf("Empty Map error\n"), close(fd), exit(1));
	data->map_width = ft_strlen(line);
	data->map_height = 1;
	tmp_map = ft_strdup("");
	while (line)
	{
		data->map_height++;
		tmp_tmp_map = ft_strjoin(tmp_map, line);
		free(line);
		free(tmp_map);
		tmp_map = tmp_tmp_map;
		line = get_next_line(fd);
	}
	close(fd);
	maps_split_control(data, tmp_map);
}
