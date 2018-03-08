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

int		main(void)
{
	t_filler	*game;
	char		*str;

	game = (t_filler*)malloc(sizeof(t_filler));
	CHECK(game);
	get_next_line(0. &str);
	game->player = (ft_atoi(str + 10) == 1) ? 'O' : 'X';
	while (1)
	{
		get_next_line(0, str);
		game->map_y = ft_atoi(&str[8]);
		game->map_x = ft_atoi(&str[11]);
		//
		if (game->endgame == 1)
			break ;
	}
	free(game);
	return (0);
}