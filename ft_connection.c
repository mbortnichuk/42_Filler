/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:23:26 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/23 16:23:28 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

//ft_go_contact1
int		ft_go_to_target(t_figure *figure, t_map *map)
{
	int i;
	int j;
	int result;

	i = map->y_cord - 1;
	result = 0;
	figure->finaly = 0;
	figure->finalx = 0;
	while (i > 0)
	{
		j = map->x_cord - 1;
		while (j > 0)
		{
			result = ft_can_be_placed(map, figure, i, j);
			if (result == 0)
			{
				ft_res_to_output(map, figure);
				return (0);
			}
			j--;
		}
		i--;
	}
	return (1);
}

//ft_go_contact2
int		ft_go_to_target2(t_figure *figure, t_map *map)
{
	int i;
	int j;
	int result;

	i = -1;
	result = 0;
	figure->finaly = 0;
	figure->finalx = 0;
	while (++i < map->y_cord - 1)
	{
		j = -1;
		while (++j < map->x_cord - 1)
		{
			result = ft_can_be_placed(map, figure, i, j);
			if (result == 0)
			{
				ft_res_to_output(map, figure);
				return (0);
			}
		}
	}
	return (1);
}
