/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:39:11 by mbortnic          #+#    #+#             */
/*   Updated: 2018/03/13 14:39:14 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_filler.h"

/*
** Algos for player to move.
*/

int		ft_down_l(t_filler *game)
{
	int		i;
	int		j;

	i = game->map_y;
	while (i > 0)
	{
		j = -1;
		while (++j < game->map_x)
		{
			if (ft_try_fig(i, j, game) == 1)
			{
				game->x_move = j;
				game->y_move = i;
				return (1);
			}
		}
		i--;
	}
	return (0);
}

int		ft_down_r(t_filler *game)
{
	int		i;
	int		j;

	i = game->map_y;
	while (i > 0)
	{
		j = game->map_x;
		while (j > 0)
		{
			if (ft_try_fig(i, j, game) == 1)
			{
				game->x_move = j;
				game->y_move = i;
				return (1);
			}
			j--;
		}
		i--;
	}
	return (0);
}

int		ft_up_l(t_filler *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->map_y)
	{
		j = -1;
		while (++j < game->map_x)
		{
			if (ft_try_fig(i, j, game) == 1)
			{
				game->x_move = j;
				game->y_move = i;
				return (1);
			}
		}
	}
	return (0);
}

int		ft_up_r(t_filler *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->map_y)
	{
		j = game->map_x;
		while (j > 0)
		{
			if (ft_try_fig(i, j, game) == 1)
			{
				game->x_move = j;
				game->y_move = i;
				return (1);
			}
			j--;
		}
	}
	return (0);
}
