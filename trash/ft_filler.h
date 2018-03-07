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
	// int		x_first_pos;
	// int		y_first_pos;
	char	*res;
}				t_map;

typedef struct s_figure
{
	char	**figure;
	int		connection;
	int		connection_nb;
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

/*
** ft_utils.c
*/
int		ft_is_digit(int c);
int		ft_last_chance(t_figure *figure, t_map *map);
int		ft_get_resutl(t_map *map, t_figure *figure);
void	ft_res_to_output(t_map *map, t_figure *figure);

/*
** ft_utils2.c
*/
void	ft_player_config(t_map *map);
void	ft_take_player(t_map *map);
void	ft_strategic_pos(t_map *map, char *str, int i);
void	ft_take_map(t_map *map);
void	ft_mapsize(t_map *map, char *str);

/*
** ft_canbeplaced.c
*/
int		ft_can_be_placed_v2(t_figure *figure, int counter, int i, int j);
int		ft_can_be_placed(t_map *map, t_figure *figure, int i, int j);
int		ft_connection_amount(t_figure *figure, t_map *map, int y, int x);
void	ft_take_connection(t_map *map, t_figure *figure);

/*
** ft_figure.c
*/
void	ft_figuresize(t_figure *figure);
void	ft_take_figure(t_figure *figure);
void	ft_take_figure_size(t_figure *figure, char *str);

/*
** ft_connection.c
*/
int		ft_go_to_target(t_figure *figure, t_map *map);
int		ft_go_to_target2(t_figure *figure, t_map *map);

/*
** ft_algorithms.c
*/
int		ft_first(t_figure *figure, t_map *map);
int		ft_first2(t_figure *figure, t_map *map);
int		ft_second(t_figure *figure, t_map *map);
int		ft_second2(t_figure *figure, t_map *map);
int		ft_third2(t_map *map, t_figure *figure, int connection_nb);
int		ft_third(t_figure *figure, t_map *map);

/*
** ft_game.c
*/
int		ft_small_gameboard(t_figure *figure, t_map *map);
int		ft_big_gameboard(t_figure *figure, t_map *map);
int		ft_game(t_figure *figure, t_map *map);

/*
** main.c
*/
void	ft_struct_initiation(t_map *map, t_figure *figure);

#endif
