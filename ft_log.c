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

#include "ft_filler.h"

int		to_down_l(t_filler *game)
{
	int i;
	int k;

	i = game->map_y;
	while (i > 0)
	{
		k = 0;
		while (k < game->map_x)
		{
			if (ft_try_fig(i, k, game) == 1)
			{
				game->x_move = k;
				game->y_move = i;
				return (1);
			}
			k++;
		}
		i--;
	}
	return (0);
}

int		to_down_r(t_filler *game)
{
	int i;
	int k;

	i = game->map_y;
	while (i > 0)
	{
		k = game->map_x;
		while (k > 0)
		{
			if (ft_try_fig(i, k, game) == 1)
			{
				game->x_move = k;
				game->y_move = i;
				return (1);
			}
			k--;
		}
		i--;
	}
	return (0);
}

int		to_up_l(t_filler *game)
{
	int i;
	int k;

	i = 0;
	while (i < game->map_y)
	{
		k = 0;
		while (k < game->map_x)
		{
			if (ft_try_fig(i, k, game) == 1)
			{
				game->x_move = k;
				game->y_move = i;
				return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}

int		to_up_r(t_filler *game)
{
	int i;
	int k;

	i = 0;
	while (i < game->map_y)
	{
		k = game->map_y;
		while (k > 0)
		{
			if (ft_try_fig(i, k, game) == 1)
			{
				game->x_move = k;
				game->y_move = i;
				return (1);
			}
			k--;
		}
		i++;
	}
	return (0);
}

int		ft_moves(t_filler *game)
{
	if (game->log == 0)
		return (to_up_l(game));
	else if (game->log == 1)
		return (to_down_r(game));
	else if (game->log == 2)
		return (to_up_r(game));
	else if (game->log == 3)
		return (to_down_l(game));
	else
		return (0);
}
