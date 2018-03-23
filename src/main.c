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

#include "../inc/ft_filler.h"

static void	ft_clean(t_filler *game)
{
	game->map = NULL;
	game->figure = NULL;
	game->map_x = 0;
	game->map_y = 0;
	game->fig_x = 0;
	game->fig_y = 0;
	// game->player_x = 0;
	// game->player_y = 0;
	// game->enemy_x = 0;
	// game->enemy_y = 0;
	game->x_move = 0;
	game->y_move = 0;
	game->log = 0;
	game->endgame = 0;
	game->ko = 0;
}

// char	**ft_malloc_tab(size_t x, size_t y)
// {
// 	char	**tab1;
// 	char	*tab2;
// 	size_t	i;

// 	i = -1;
// 	tab1 = (char **)malloc(sizeof(char *) * y);
// 	tab2 = (char *)malloc(sizeof(char) * x * y);
// 	CHECK(tab1);
// 	CHECK(tab2);
// 	while (++i < y)
// 		tab1[i] = &tab2[i * x];
// 	free(tab2);
// 	return (tab1);
// }

/*
** Driver function to run our program.
*/

int		main(void)
{
	char		*str;
	t_filler	*game;

	if (!(game = ft_memalloc(sizeof(t_filler))))
		return (-1);
	ft_clean(game);
	get_next_line(0, &str);
	game->player = (ft_atoi(str + 10) == 1) ? PL_1 : PL_2;
	free(str);
	while (42)
	{
		
		get_next_line(0, &str);
		game->map_y = ft_atoi(&str[8]);
		game->map_x = ft_atoi(&str[11]);
		if (str)
			ft_strdel(&str); //ios
		ft_take_map(game);
		if (ft_moves(game) == 0)
			game->ko = 1;

		if (game->map)
		{
			int i = -1;
			while (++i < game->map_y)
			{
				free (game->map[i]);
			}
			free(game->map);
			game->map = NULL;
		}
		if (game->figure)
		{
			int j = -1;
			while (++j < game->fig_y)
			{
				free (game->figure[j]);
			}
			free(game->figure);
			game->figure = NULL;
		}

		ft_make_move(game);
		if (game->endgame == 1)
		{
			// if (game)
			// {
			// 	if (game->map)
			// 		free(game->map);
			// 	if (game->figure)
			// 		free(game->figure);
			// 	free(game);
			// }
			break ;
		}
		// while (69);
	}
	return (0);
}
