/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canbeplaced.c                                   :+:      :+:    :+:   */
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
	if (i + figure->y_size > map->y_cord || j + figure->x_size > map->x_cord)
		return (1);
	while (++jj <= (figure->y_size - 1))
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

//ft_count_contact
int		ft_connection_amount(t_figure *figure, t_map *map, int y, int x)
{
	int i;
	int j;
	int k;

	i = -1;
	figure->connection_nb = 0;
	while (++i < figure->y_size)
	{
		j = -1;
		while (++j < figure->x_size)
			if (figure->figure[i][j] == '*')
			{
				k = 0;
				while (++k < 4)
					if ((j + x + k) < map->x_cord && (j + x - k) > 0 && \
						(i + y + k) < map->y_cord && (j + y - k) > 0)
						if (map->map[i + y][j + x + k] == map->enemy[0] || \
							map->map[i + y][j + x - k] == map->enemy[0] || \
							map->map[i + y + k][j + x] == map->enemy[0] || \
							map->map[i + y - k][j + x] == map->enemy[0])
							figure->connection_nb = figure->connection_nb + (4 - k);
			}
	}
	return (figure->connection_nb);
}

//ft_get_contact
void	ft_take_connection(t_map *map, t_figure *figure)
{
	int i;
	int j;

	i = 2;
	while (++i < map->y_cord - 3)
	{
		j = 2;
		while (++j < map->x_cord - 3)
		{
			if (map->map[i][j] == map->me[0] || map->map[i][j] == map->me[1])
			{
				if (map->map[i][j + 3] == map->enemy[0] || map->map[i][j - 3] == map->enemy[0] || \
					map->map[i + 3][j] == map->enemy[0] || map->map[i - 3][j] == map->enemy[0] || \
					map->map[i][j + 3] == map->enemy[1] || map->map[i][j - 3] == map->enemy[1] || \
					map->map[i + 3][j] == map->enemy[1] || map->map[i - 3][j] == map->enemy[1])
				{
					figure->connection = 1;
					return ;
				}
			}
		}
	}
}
