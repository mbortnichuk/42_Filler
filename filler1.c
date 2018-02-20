/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:22:44 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/20 13:22:51 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

char	**ft_strnew_upd1(int x, int y)
{
	char	**tab1;
	char	*tab2;
	int i;

	i = -1;
	tab1 = (char**)malloc(sizeof(char*) * y);
	tab2 = (char*)malloc(sizeof(char) * x * y);
	while (++i < y)
		tab1[i] = &tab2[i * x];
	return (tab1);
}

int		ft_take_symb(t_fillergame *sample, char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 6;

	sample->y_figure = ft_atoi(&str[6]);
	while (ft_isdigit(str[nb]))
		nb++;
	nb++;
	sample->x_figure = ft_atoi(&str[nb]);
	if (!sample->figure)
	sample->figure = ft_strnew_upd1(sample->y_figure, sample->x_figure);
	CHECK(sample->figure); // or return (-1);
	while (i < sample->y_figure)
	{
		get_next_line(0, &str);
		sample->figure[i]  = ft_strdup(str);
		i++;
	}
	return (0);
}