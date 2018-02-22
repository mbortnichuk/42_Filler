/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:57:55 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/20 10:57:57 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "./libft/libft.h"

typedef struct s_fillergame
{
	int		move_x;
	int		move_y;
	char	player;
	char	enemy;
	int		x_cord;
	int		y_cord;
	char	**map;
	int		x_figure;
	int		y_figure;
	char	**figure;
	int		x_player;
	int		y_player;
	int		x_enemy;
	int		y_enemy;
	int		invalid;
	int		ko;
	int		alg;
}				t_fillergame;

char	**ft_strnew_upd1(int x, int y);
int		ft_take_symb(t_fillergame *sample, char *str);
void	ft_take_position(t_fillergame *sample);
int		ft_take_map(t_fillergame *sample);

#endif
