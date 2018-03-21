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

# include "../libft/libft.h"

# define PL_1 'O'
# define PL_2 'X'

typedef struct	s_filler
{
	char	player;
	char	enemy;
	\
	char	**map;
	int		map_x;
	int		map_y;
	\
	char	**figure;
	int		fig_x;
	int		fig_y;
	\
	int		player_x;
	int		player_y;
	\
	int		enemy_x;
	int		enemy_y;
	\
	int		x_move;
	int		y_move;
	\
	int		log;
	int		endgame;
	int		ko;
}				t_filler;

/*
** ft_take_intel.c
*/

int				ft_take_map(t_filler *game);
int				ft_take_figure(char *str, t_filler *game);
void			ft_take_pos(t_filler *game);

/*
** ft_log.c
*/

int				ft_down_l(t_filler *game);
int				ft_down_r(t_filler *game);
int				ft_up_l(t_filler *game);
int				ft_up_r(t_filler *game);

/*
** ft_moves.c
*/

void			ft_make_move(t_filler *game);
int				ft_moves(t_filler *game);
int				ft_validate_figs(int i, int k, t_filler *game);
int				ft_try_fig(int i, int k, t_filler *game);

/*
** main.c
*/

char			**ft_malloc_tab(size_t x, size_t y);

#endif
