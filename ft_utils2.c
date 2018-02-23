/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:37:21 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/21 13:37:22 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

// ft_wich_player
void	ft_player_config(t_map *map)
{
	if (map->player == 1)
	{
		map->me = "Oo";
		map->enemy = "Xx";
	}
	if (map->player == 2)
	{
		map->me = "Xx";
		map->enemy = "Oo";
	}
}

//ft_get_player
void	ft_take_player(t_map *map)
{
	char	*str;

	get_next_line(0, &str);
	if (ft_strncmp(str, "$$$", 2) == 0 && map->player == 0)
	{
		if (ft_strstr(str, "p2"))
			map->player = 2;
		if (ft_strstr(str, "p1"))
			map->player = 1;
		ft_player_config(map);
	}
	free(&str);
}

//ft_get_strat_pos
void	ft_strategic_pos(t_map *map, char *str, int i)
{
	int			k;
	static int	j;

	if (j == map->y_cord)
		return ;
	j = 0;
	while (++j < (map->y_cord))
	{
		i = 0;
		while (++k < (map->x_cord))
		{
			if ((map->map[j][k] == map->enemy[0] || \
				map->map[j][k] == map->enemy[1]))
			{
				map->x_enemy = k;
				map->y_enemy = j;
			}
			if ((map->map[j][k] == map->me[0] || \
				map->map[j][k] == map->me[1]))
			{
				map->x_me = k;
				map->y_me = j;
			}
		}
	}
}

//ft_get_map
void	ft_take_map(t_map *map)
{
	int		i;
	char	*str;

	i = 0;
	get_next_line(0, &str);
	free(&str);
	map->map = (char**)malloc(sizeof(char*) * (map->y_cord + 1));
	// CHECK(map->map);
	while (i <= (map->y_cord - 1))
	{
		get_next_line(1, &str);
		map->map[i] = ft_strdup((const char*)(&str[4]));
		free(&str);
		i++;
	}
	ft_strategic_pos(map, str, i);
}

//ft_get_map_size
void	ft_mapsize(t_map *map, char *str)
{
	int		i;
	int		temp;

	i = 0;
	map->x_cord = 0;
	map->y_cord = 0;
	while (str[i])
	{
		temp = 0;
		while (ft_isdigit(str[i]) == 1 && str[i])
		{
			temp = temp + (str[i] - '0');
			if (ft_isdigit(str[i + 1]) == 1)
				temp = temp * 10;
			i++;
		}
		if (map->y_cord == 0)
			map->y_cord = temp;
		else if (map->x_cord == 0)
			map->x_cord = temp;
		i++;
	}
	ft_take_map(map);
}
