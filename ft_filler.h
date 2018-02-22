/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:09:57 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/21 13:09:59 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "./libft/libft.h"

typedef struct s_map
{
	int		player;
	char	*me;
	int		x_me;
	int		y_me;
	char	**map;
	int		x_cord;
	int		y_cord;
	char	*enemy;
	int		x_enemy;
	int		y_enemy;
	void	*victory;
	int		x_first_pos;
	int		y_first_pos;
	char	*res;
}				t_map;

typedef struct s_figure
{
	char	**figure;
	int		contact;
	int		contact_nb;
	int		x_size;
	int		y_size;
	int		x_size_real;
	int		y_size_real;
	int		x_first;
	int		x_last;
	int		y_first;
	int		y_last;
	int		x_temp;
	int		y_temp;
	int		finalx;
	int		finaly;
}				t_figure;

void	ft_player_config(t_map *map);
void	ft_take_player(t_map *map);
void	ft_strategic_pos(t_map *map, char *str, int i);
void	ft_take_map(t_map *map);
void	ft_mapsize(t_map *map, char *str);

#endif
