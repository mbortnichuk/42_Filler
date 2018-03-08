/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:28:27 by mbortnic          #+#    #+#             */
/*   Updated: 2018/03/08 14:29:24 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "./libft/libft.h"

typedef struct	s_filler
{
	char	player;
	char	enemy;
	char	**map;
	int		map_x;
	int		map_y;
	char	*figure;
	int		fig_x;
	int		fig_y;
	int		player_x;
	int		player_y;
	int		enemy_x;
	int		enemy_y;
	int		x_move;
	int		y_move;
	int		err;
	int		endgame;
	int		ko;
}				t_filler;

#endif
