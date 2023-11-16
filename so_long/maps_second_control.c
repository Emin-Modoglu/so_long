/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_second_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:00:14 by emmodogl          #+#    #+#             */
/*   Updated: 2023/10/13 11:48:47 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	explore_map(char **map, t_control *control, int y, int x)
{
	if (x == -1 || y == -1
		|| !map[y] || !map[y][x] || map[y][x] == '#' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
		control->exit_accesible = 1;
	else if (map[y][x] == 'C')
		control->coin_accesible++;
	map[y][x] = '#';
	explore_map(map, control, y + 1, x);
	explore_map(map, control, y - 1, x);
	explore_map(map, control, y, x + 1);
	explore_map(map, control, y, x - 1);
}

void	maps_path_control(t_so_long *s, char **map)
{
	t_control	control;

	control.exit_accesible = 0;
	control.coin_accesible = 0;
	explore_map(map, &control, s->player_y, s->player_x);
	ft_malloc_error(map);
	if (!control.exit_accesible)
	{
		ft_malloc_error(s->map);
		ft_printf("Error\nI can't reach the door\n");
		exit(1);
	}
	if (control.coin_accesible != s->count_c)
	{
		ft_malloc_error(s->map);
		ft_printf("Error\nWhole coins cannot collect\n");
		exit(1);
	}
}
