/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_first_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:53:58 by emmodogl          #+#    #+#             */
/*   Updated: 2023/10/13 11:42:28 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_win(t_so_long *s, int x, int y)
{
	ft_printf("STEP by STEP: %d\n", s->count_step);
	while (s->map[++y])
	{
		x = -1;
		while (s->map[y][++x])
		{
			mlx_put_image_to_window(s->mlx_ptr,
				s->mlx_win, s->background, x * P, y * P);
			if (s->map[y][x] == '1')
				mlx_put_image_to_window(s->mlx_ptr, s->mlx_win,
					s->wall, x * P, y * P);
			if (s->map[y][x] == '0')
				mlx_put_image_to_window(s->mlx_ptr,
					s->mlx_win, s->background, x * P, y * P);
			if (s->map[y][x] == 'E')
				mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->door,
					x * P, y * P);
			if (s->map[y][x] == 'C')
				mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->coin,
					x * P, y * P);
		}
	}
	mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->playerimg,
		s->player_x * P, s->player_y * P);
}

int	close_window(t_so_long *data)
{
	ft_printf("Game Over!!");
	game_end(data);
	return (0);
}

void	game_init_control(t_so_long *data)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, (data->map_width - 1) * P,
			(data->map_height - 1) * P, "Window");
	data->playerimg = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/player.xpm", &a, &b);
	data->background = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/background.xpm", &a, &b);
	data->coin = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/coin.xpm", &a, &b);
	data->door = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/exit.xpm", &a, &b);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/wall.xpm", &a, &b);
	if (!data->mlx_ptr || !data->mlx_win || !data->playerimg
		|| !data->background || !data->coin || !data->door || !data->wall)
		return (ft_printf("Images Add Error\n"), game_end(data));
	open_win(data, -1, -1);
	mlx_hook(data->mlx_win, 2, 0, movement, data);
	mlx_hook(data->mlx_win, 17, 0, close_window, data);
	mlx_loop(data->mlx_ptr);
}
