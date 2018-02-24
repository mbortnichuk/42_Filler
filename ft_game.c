/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:34:44 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/23 12:34:46 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

//ft_small_map
int		ft_small_gameboard(t_figure *figure, t_map *map)
{
	if (map->y_me < (map->y_cord / 2))
	{
		if (map->x_me < (map->x_cord / 2))
		{
			if (ft_second(figure, map) == 1)
				return (1);
		}
		else if (map->x_me >= (map->x_cord / 2))
				if (ft_second2(figure, map) == 1)
					return (1);
	}
	else if (map->y_me >= (map->y_cord / 2))
	{
		if (map->x_me < (map->x_cord / 2))
		{
			if (ft_first(figure, map) == 1)
				return (1);
		}
		else if (map->x_me >= (map->x_cord / 2))
				if (ft_first2(figure, map) == 1)
					return (1);
	}
	return (0);
}

//ft_big_map
int		ft_big_gameboard(t_figure *figure, t_map *map)
{
	int result;

	ft_take_connection(map, figure);
	if (figure->connection == 0)
	{
		if (map->y_me < map->y_enemy)
		{
			if (ft_go_to_target(figure, map) == 1)
				return (1);
		}
		else if (map->y_me >= map->y_enemy)
		{
			if (ft_go_to_target2(figure, map) == 1)
				return (1);
		}
	}
	else
	{
		result = ft_third(figure, map);
		if (result == 0)
			return (1);
	}
	return (0);
}

//ft_play
int		ft_game(t_figure *figure, t_map *map)
{
	if (map->y_cord < 20)
		return (ft_small_gameboard(figure, map));
	else if (map->y_cord >= 20)
		return (ft_big_gameboard(figure, map));
	return (0);
}
