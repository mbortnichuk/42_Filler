/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:58:36 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/22 11:58:37 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

//ft_get_real_piece_size
void	ft_figuresize(t_figure *figure)
{
	int i;
	int j;

	i = -1;
	figure->x_first = figure->x_size;
	figure->y_first = figure->y_size;
	while (++i < figure->y_size)
	{
		j = -1;
		while (++j < figure->x_size)
		{
			if (figure->figure[i][j] == '*')
			{
				if (j < figure->x_first)
					figure->x_first = j;
				if (j > figure->x_last)
					figure->x_last = j;
				if (i < figure->y_first)
					figure->y_first = i;
				if (i > figure->y_last)
					figure->y_last = i;
			}
		}
	}
	figure->x_size_real = (figure->x_last - figure->x_first) + 1;
	figure->y_size_real = (figure->y_last - figure->y_first) + 1;
}

//ft_get_piece
void	ft_take_figure(t_figure *figure)
{
	char	*str;
	int		i;

	i = 0;
	if (!figure->figure)
		free(figure->figure);
	figure->figure = (char**)malloc(sizeof(char*) * (figure->y_size + 1));
	//CHECK(figure->figure);
	while (i < figure->y_size)
	{
		get_next_line(0, &str);
		figure->figure[i] = (char*)malloc(sizeof(char*) * (figure->x_size + 1));
		figure->figure[i] = ft_strcpy(figure->figure[i], (const char*)str);
		i++;
		free(&str);
	}
	ft_figuresize(figure);
}

//ft_get_piece_size
void	ft_take_figure_size(t_figure *figure, char *str)
{
	int temp;
	int i;

	i = 0;
	figure->x_size = 0;
	figure->y_size = 0;
	while (str[i] != '\0')
	{
		temp = 0;
		while (ft_isdigit(str[i]) == 1 && str[i])
		{
			temp = temp + (str[i] - '0');
			if (ft_isdigit(str[i + 1]) == 1)
				temp = temp * 10;
			i++;
		}
		if (figure->y_size == 0)
			figure->y_size = temp;
		else if (figure->x_size == 0)
			figure->x_size = temp;
		i++;
	}
	free(&str);
	ft_take_figure(figure);
}

