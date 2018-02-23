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
	}
	else if (map->y_me >= (map->y_cord / 2))
	{
		if (map->x_me < (map->x_cord / 2))
		{
			if (ft_first(figure, map) == 1)
				return (1);
		}
	}
	return (0);
}

//ft_play
int		ft_game(t_figure *figure, t_map *map)
{
	if (map->y_cord <= 19)
		return (ft_small_gameboard(figure, map)); //
	//else if (map->y_cord >= 20)
	//	return (ft_big_gameboard(figure, map)); // in work
	return (0);
}
