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

char	**ft_malloc_tab(size_t x, size_t y)
{
	char	**tab1;
	char	*tab2;
	size_t	i;

	i = 0;
	tab1 = (char **)malloc(sizeof(char *) * y);
	tab2 = (char *)malloc(sizeof(char) * x * y);
	CHECK(tab1);
	CHECK(tab2);
	while (i < y)
	{
		tab1[i] = &tab2[i * x];
		i++;
	}
	return (tab1);
}

/*
** Driver function to run our program.
*/

int		main(void)
{
	char		*str;
	t_filler	*game;

	game = ft_memalloc(sizeof(t_filler));
	CHECK(game);
	get_next_line(0, &str);
	game->player = (ft_atoi(str + 10) == 1) ? 'O' : 'X';
	while (1)
	{
		get_next_line(0, &str);
		game->map_y = ft_atoi(&str[8]);
		game->map_x = ft_atoi(&str[11]);
		ft_take_map(game);
		if (ft_moves(game) == 0)
			game->ko = 1;
		ft_make_move(game);
		if (game->endgame == 1)
			break ;
	}
	free(game);
	return (0);
}
