/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:27:32 by mbortnic          #+#    #+#             */
/*   Updated: 2018/03/08 14:27:56 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

//47  65  54

int		ft_validate_figs(int i, int k, t_filler *game)
{
	int superposition;
	int x;
	int y;

	superposition = 0;
	y = 0;
	while (y < game->fig_y)
	{
		x = 0;
		while (x < game->fig_x)
		{
			if ((game->map[i + y][k + x] == game->player || \
					game->map[i + y][k + x] == game->player + ' ') && \
					game->figure[y][x] == '*')
				superposition++;
			if ((game->map[i + y][k + x] == game->enemy || \
					game->map[i + y][k + x] == game->enemy + ' ') && \
				game->figure[x][y] == '*')
				return (0);
			x++;
		}
		y++;
	}
	return ((superposition == 1) ? 1 : 0);
}

int		ft_try_fig(int i, int k, t_filler *game)
{
	if (i + game->fig_y > game->map_y)
		return (0);
	else if (k + game->fig_x > game->map_x)
		return (0);
	else
		return (ft_validate_figs(i, k, game));
}

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

void	ft_take_pos(t_filler *game)
{
	int i;
	int k;

	i = 0;
	game->enemy = (game->player == 'O') ? 'X' : 'O';
	while (i < game->map_y)
	{
		k = 0;
		while (k < game->map_x)
		{
			if (game->map[i][k] == game->enemy)
			{
				game->enemy_x = k;
				game->enemy_y = i;
			}
			if (game->map[i][k] == game->player)
			{
				game->player_x = k;
				game->player_y = i;
			}
			k++;
		}
		i++;
	}
	game->log = (game->enemy_y > game->player_y) ? 1 : 0;
}

int		ft_read_figure(char *str, t_filler *game)
{
	int i;
	int j;

	i = 0;
	j = 6;
	game->fig_y = ft_atoi(&str[6]);
	while (ft_isdigit(str[j]))
		j++;
	j++;
	game->fig_x = ft_atoi(&str[j]);
	if (!game->figure)
		if (!(game->figure = ft_malloc_tab(game->fig_y, game->fig_x)))
			return (-1);
	while (i < game->fig_y)
	{
		get_next_line(0, &str);
		game->figure[i] = ft_strdup(str);
		i++;
	}
	return (0);

}

char	**ft_malloc_tab(size_t x, size_t y)
{
	size_t	i;
	char	**tab1;
	char	*tab2;

	i = 0;
	tab1 = (char**)malloc(sizeof(char*) * y);
	tab2 = (char*)malloc(sizeof(char) * x * y);
	while (i < y)
	{
		tab1[i] = &tab2[i * x];
		i++;
	}
	return (tab1);
}

int		ft_read_map(t_filler *game)
{
	char	*str;
	int i;

	i = 0;
	if (!game->map)
		if (!(game->map = ft_malloc_tab(game->map_y, game->map_x)))
			return (-1);
	get_next_line(0, &str);
	while (i <= game->map_y)
	{
		get_next_line(0, &str);
		if (ft_isdigit(str[0]))
			game->map[i] = ft_strdup(str + 4);
		else
			ft_read_figure(str, game);
		if (game->enemy_x == 0 && game->enemy_y == 0 && \
				game->player_x == 0 && game->player_y == 0)
			ft_take_pos(game);
		
	}
	return (0);
}

int		main(void)
{
	t_filler	*game;
	char		*str;

	game = (t_filler*)malloc(sizeof(t_filler));
	CHECK(game);
	get_next_line(0, &str);
	game->player = (ft_atoi(str + 10) == 1) ? 'O' : 'X';
	while (1)
	{
		get_next_line(0, &str);
		game->map_y = ft_atoi(&str[8]);
		game->map_x = ft_atoi(&str[11]);
		ft_read_map(game);
		// if (logic(game) == 0)
		// 	game->ko = 1;
		// ft_make_move(game);
		if (game->endgame == 1)
			break ;
	}
	free(game);
	return (0);
}