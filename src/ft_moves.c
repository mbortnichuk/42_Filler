/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:22:50 by mbortnic          #+#    #+#             */
/*   Updated: 2018/03/16 17:22:52 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_filler.h"

/*
** Moving given token forward.
*/

void	ft_make_move(t_filler *game)
{
	if (game->log == 0)
		game->log = 3;
	else if (game->log == 1)
		game->log = 2;
	else if (game->log == 2)
		game->log = 1;
	else if (game->log == 3)
		game->log = 0;
	if (game->ko == 1)
	{
		game->endgame = 1;
		ft_putnbr(game->y_move);
		write(1, " ", 1);
		ft_putnbr(game->x_move);
		write(1, "\n", 1);
	}
	else
	{
		ft_putnbr(game->y_move);
		write(1, " ", 1);
		ft_putnbr(game->x_move);
		write(1, "\n", 1);
	}
}

int		ft_moves(t_filler *game)
{
	if (game->log == 0)
		return (ft_up_l(game));
	else if (game->log == 1)
		return (ft_down_r(game));
	else if (game->log == 2)
		return (ft_up_r(game));
	else if (game->log == 3)
		return (ft_down_l(game));
	else
		return (0);
}

/*
** Checking given token.
*/

int		ft_validate_figs(int i, int j, t_filler *game)
{
	int		superposition;
	int		y;
	int		x;

	superposition = 0;
	y = -1;
	while (++y < game->fig_y)
	{
		x = -1;
		while (++x < game->fig_x)
		{
			if ((game->map[i + y][j + x] == game->player ||
				game->map[i + y][j + x] == game->player + 32)
					&& game->figure[y][x] == '*')
				superposition++;
			if ((game->map[i + y][j + x] == game->enemy ||
				game->map[i + y][j + x] == game->enemy + 32)
					&& game->figure[y][x] == '*')
				return (0);
		}
	}
	return ((superposition == 1) ? 1 : 0);
}

int		ft_try_fig(int i, int j, t_filler *game)
{
	if (i + game->fig_y > game->map_y)
		return (0);
	else if (j + game->fig_x > game->map_x)
		return (0);
	else
		return (ft_validate_figs(i, j, game));
}
