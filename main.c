/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:54:48 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/21 12:56:16 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_struct_initation(t_map *map, t_figure *figure)
{
	map->map = NULL;
	map->player = 0;
	map->x_enemy = 0;
	map->y_enemy = 0;
	map->x_me = 0;
	map->y_me = 0;
	map->x_cord = 0;
	map->y_cord = 0;
	figure->connection = 0;
	figure->x_first = 0;
	figure->x_last = 0;
	figure->y_first = 0;
	figure->y_last = 0;
	figure->x_size = 0;
	figure->y_size = 0;
	figure->finalx = 0;
	figure->finaly = 0;
}

int main(void)
{
	t_map		*map;
	t_figure	*figure;

	map = (t_map*)malloc(sizeof(*map));
	figure = (t_figure*)malloc(sizeof(*figure));
	ft_struct_initation(map, figure);
	ft_player_config(map);
	while (1)
	{
		ft_res_to_output(map, figure);
	}
	return (0);
}
