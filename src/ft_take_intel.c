/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_intel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:09:03 by mbortnic          #+#    #+#             */
/*   Updated: 2018/03/16 17:09:05 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_filler.h"

/*
** Reading map.
*/

int		ft_take_map(t_filler *game)
{
	char	*str;
	int		i;

	i = -1;
	if (!game->map)
	{
		game->map = ft_malloc_tab(game->map_y, game->map_x);
		CHECK(game->map);
	}
	get_next_line(0, &str);
	while (++i <= game->map_y)
	{
		get_next_line(0, &str);
		if (str[0] >= '0' && str[0] <= '9')
			game->map[i] = ft_strdup(str + 4);
		else
			ft_take_figure(str, game);
	}
	if (game->player_x == 0 && game->player_y == 0 && \
			game->enemy_x == 0 && game->enemy_y == 0)
		ft_take_pos(game);
	return (0);
}

/*
** Reading given figure.
*/

int		ft_take_figure(char *str, t_filler *game)
{
	int		n;
	int		i;

	n = 6;
	i = -1;
	game->fig_y = ft_atoi(&str[6]);
	while (str[n] >= '0' && str[n] <= '9')
		n++;
	n++;
	game->fig_x = ft_atoi(&str[n]);
	if (!game->figure)
	{
		game->figure = ft_malloc_tab(game->fig_y, game->fig_x);
		CHECK(game->figure);
	}
	while (++i < game->fig_y)
	{
		get_next_line(0, &str);
		game->figure[i] = ft_strdup(str);
	}
	return (0);
}

/*
** Take players positions.
*/

void	ft_take_pos(t_filler *game)
{
	int		i;
	int		j;

	game->enemy = (game->player == PL_1) ? PL_2 : PL_1;
	i = -1;
	while (++i < game->map_y)
	{
		j = -1;
		while (++j < game->map_x)
		{
			if (game->map[i][j] == game->player)
			{
				game->player_x = j;
				game->player_y = i;
			}
			if (game->map[i][j] == game->enemy)
			{
				game->enemy_x = j;
				game->enemy_y = i;
			}
		}
	}
	game->log = (game->enemy_y > game->player_y) ? 1 : 0;
}
