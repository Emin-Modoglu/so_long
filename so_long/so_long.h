/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:38:58 by emmodogl          #+#    #+#             */
/*   Updated: 2023/10/13 11:58:10 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>

# define W		13
# define S		1
# define A		0
# define D		2
# define ESC	53
# define P		64

typedef struct s_so_long
{
	char	**map;
	int		map_width;
	int		map_height;
	int		count_p;
	int		count_c;
	int		count_e;
	int		count_step;
	int		player_x;
	int		player_y;
	void	*mlx_win;
	void	*mlx_ptr;
	void	*playerimg;
	void	*wall;
	void	*background;
	void	*coin;
	void	*door;
}	t_so_long;

typedef struct s_control
{
	int	exit_accesible;
	int	coin_accesible;
}	t_control;

void	maps_name_control(t_so_long *data, char *str);
void	maps_read_control(t_so_long *data, char *str);
void	maps_wall_control(t_so_long *data, int x, int y);
void	maps_player_control(t_so_long *data, int x, int y);
void	maps_path_control(t_so_long *data, char **str);
void	maps_split_control(t_so_long *data, char *str);
void	maps_object_control(t_so_long *data);

void	game_init_control(t_so_long *data);
void	player_movement(t_so_long *data, int x, int y);
void	charackter_show(t_so_long *data, char c);
void	game_over(int a, t_so_long *data);
int		movement(int key, t_so_long *data);
void	open_win(t_so_long *data, int x, int y);
void	game_end(t_so_long *data);
void	free_map(t_so_long *data);

#endif
