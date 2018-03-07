/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:17:10 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/23 12:17:13 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

//ft_algo1
int		ft_first(t_figure *figure, t_map *map)
{
	int i;
	int j;
	int result;

	i = -1;
	result = 0;
	figure->finaly = 0;
	figure->finalx = 0;
	while (++i < map->y_cord)
	{
		j = map->x_cord;
		while (--j > 0)
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

//ft_algo1_2
int		ft_first2(t_figure *figure, t_map *map)
{
	int i;
	int j;
	int result;

	i = -1;
	result = 0;
	figure->finaly = 0;
	figure->finalx = 0;
	while (++i < map->y_cord)
	{
		j = -1;
		while (++j < map->x_cord)
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

//ft_algo2
int		ft_second(t_figure *figure, t_map *map)
{
	int i;
	int j;
	int result;

	i = map->y_cord;
	result = 0;
	figure->finaly = 0;
	figure->finalx = 0;
	while (i > 0)
	{
		 j = map->x_cord;
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

//ft_algo2_2
int		ft_second2(t_figure *figure, t_map *map)
{
	int i;
	int j;
	int result;

	result = 0;
	i = map->y_cord;
	figure->finaly = 0;
	figure->finalx = 0;
	while (i > 0)
	{
		j = -1;
		while (++j < map->x_cord)
		{
			result = ft_can_be_placed(map, figure, i, j);
			if (result == 0)
			{
				ft_res_to_output(map, figure);
				return (0);
			}
		}
		i--;
	}
	return (1);
}

//ft_algo3_2
int		ft_third2(t_map *map, t_figure *figure, int connection_nb)
{
	if (connection_nb == -1)
		return (0);
	figure->finaly = figure->y_temp;
	figure->finalx = figure->x_temp;
	ft_res_to_output(map, figure);
	return (1);
}

//ft_algo3
int		ft_third(t_figure *figure, t_map *map)
{
	int i;
	int j;
	int connection_nb;
	int temp_connection_nb;

	connection_nb = -1;
	figure->y_temp = 0;
	figure->x_temp = 0;
	i = map->y_cord - (figure->y_size - figure->y_last);
	while (--i >= 0)
	{
		j = map->x_cord - (figure->x_size - figure->x_last);
		while (--j >= 0)
			if (ft_can_be_placed(map, figure, i, j) == 0)
			{
				temp_connection_nb = ft_connection_amount(figure, map, i, j);
				if (temp_connection_nb > connection_nb)
				{
					connection_nb = temp_connection_nb;
					figure->y_temp = i;
					figure->x_temp = j;
				}
			}
	}
	return (ft_third2(map, figure, connection_nb));
}
