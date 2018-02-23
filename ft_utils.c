/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:52:53 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/22 11:52:58 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

//ft_last_try
int		ft_last_chance(t_figure *figure, t_map *map)
{
	int i;
	int j;
	int result;

	i = 0;
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

//ft_print_result
void	ft_res_to_output(t_map *map, t_figure *figure)
{
	ft_putnbr(figure->finaly);
	ft_putchar(' ');
	ft_putnbr(figure->finalx);
	ft_putchar('\n');
	map->x_me = figure->finalx;
	map->y_me = figure->finaly;
}

//ft_get_the_ret
int		ft_get_result(t_map *map, t_figure *figure)
{
	char	*str;
	figure->figure = NULL;
	while (get_next_line(0, &str) > 0)
	{
		if (ft_strncmp(str, "Plateau", 6) == 0)
		{
			ft_mapsize(map, str);
			free(&str);
		}
		else if (ft_strncmp(str, "Piece", 4) == 0)
		{
			ft_take_figure_size(figure, str);
			return (1);
		}
		else
		{
			free(&str);
		}
	}
	return (0);
}