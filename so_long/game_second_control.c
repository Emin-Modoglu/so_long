/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_second_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:47:50 by emmodogl          #+#    #+#             */
/*   Updated: 2023/10/13 11:43:36 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_movement(t_so_long *data, int x, int y)
{
	if (data->map[data->player_y + y][data->player_x + x] == '1')
		return ;
	if (data->map[data->player_y + y][data->player_x + x] == 'E'
		&& data->count_c == 0)
	{
		ft_printf("TOTAL STEP ->%d\n_@#ROOT_SUCESS#@_\n", data->count_step + 1);
		game_end(data);
	}
	if (data->map[data->player_y + y][data->player_x + x] == 'C')
		data->count_c--;
	data->count_step++;
	if (data->map[data->player_y][data->player_x] != 'E')
		data->map[data->player_y][data->player_x] = '0';
	data->player_y += y;
	data->player_x += x;
	open_win(data, -1, -1);
}

void	charackter_show(t_so_long *data, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (c == 'w' || c == 's' || c == 'a' || c == 'd')
		data->playerimg = mlx_xpm_file_to_image(data->mlx_ptr,
				"textures/player.xpm", &a, &b);
	if (!data->playerimg)
		return (ft_printf("Character Show Images\n"), game_end(data));
}

void	game_over(int a, t_so_long *data)
{
	if (a == 1)
		ft_printf("Game Over!!\n");
	game_end(data);
}

int	movement(int key, t_so_long *data)
{
	if (key == ESC)
		game_over(1, data);
	else if (key == W)
	{
		charackter_show(data, 'w');
		player_movement(data, 0, -1);
	}
	else if (key == S)
	{
		charackter_show(data, 's');
		player_movement(data, 0, 1);
	}
	else if (key == A)
	{
		charackter_show(data, 'a');
		player_movement(data, -1, 0);
	}
	else if (key == D)
	{
		charackter_show(data, 'd');
		player_movement(data, 1, 0);
	}
	return (1);
}
