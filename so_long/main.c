/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:28:34 by emmodogl          #+#    #+#             */
/*   Updated: 2023/10/13 10:37:32 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	maps_name_control(t_so_long *data, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] == 'r' && str[len -2] == 'e'
		&& str[len - 3] == 'b' && str[len - 4] == '.')
		maps_read_control(data, str);
	else
	{
		ft_printf("Wrong map name");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_so_long	data;

	data.count_c = 0;
	data.count_e = 0;
	data.count_p = 0;
	data.count_step = 0;
	if (argc == 2)
	{
		maps_name_control(&data, argv[1]);
		game_init_control(&data);
	}
	else
		ft_printf("Wrong Arguments!!");
	return (0);
}
