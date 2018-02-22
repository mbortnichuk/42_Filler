/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:03:39 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/22 17:03:41 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

//ft_is_placable2
int		ft_can_be_placed_v2(t_figure *figure, int counter, int i, int j)
{
	if (counter == 1)
	{
		figure->finaly = i;
		figure->finalx = j;
		return (0);
	}
	return (1);
}

//ft_is_placable
int		ft_can_be_placed(t_map *map, t_figure *figure, int i, int j)
{
	int counter;
	int ii;
	int jj;

	ii = -1;
	counter = 0;
	if (i + figure->y_size > map->y_cord || jj + figure->x_size > map->x_cord)
		return (1);
	while (++ii <= (figure->y_size - 1))
	{
		jj = -1;
		while (++jj <= (figure->x_size - 1))
		{
			if (figure->figure[ii][jj] == '*' && (map->map[i + ii][j + jj] == \
				map->enemy[0] || map->map[i + ii][j + jj] == map->enemy[0] - 32))
				return (1);
			if (figure->figure[ii][jj] == '*' && (map->map[i + ii][j + jj] == \
				map->me[0] || map->map[i + ii][j + jj] == map->me[0] - 32))
				counter++;
		}
	}
	if (ft_can_be_placed_v2(figure, counter, i, j) == 0)
		return (0);
	return (1);
}