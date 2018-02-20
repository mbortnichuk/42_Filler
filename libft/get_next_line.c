/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:51:22 by mbortnic          #+#    #+#             */
/*   Updated: 2018/01/15 12:11:20 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, size_t size)
{
	size_t	i;
	char	*new;

	i = 0;
	new = (char *)malloc(sizeof(char) * (size + 1));
	CHECK(new);
	while (i < size)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int		find_n(char **res, char **line)
{
	char	*new;
	char	*temp;

	while ((new = ft_strchr(*res, '\n')))
	{
		*line = ft_strndup(*res, (new - *res));
		temp = ft_strdup(new + 1);
		free(*res);
		*res = temp;
		return (LINE);
	}
	if (**res)
	{
		*line = ft_strdup(*res);
		ft_bzero(*res, ft_strlen(*res));
		return (LINE);
	}
	return (END);
}

int		get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	static char	*res[FDS];
	char		*temp;
	int			bytes;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, 0, 0) < 0)
		return (ERROR);
	while ((bytes = read(fd, buffer, BUFF_SIZE)) != 0)
	{
		if (bytes <= 0)
			return (ERROR);
		buffer[bytes] = '\0';
		if (!res[fd])
			res[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(res[fd], buffer);
			free(res[fd]);
			res[fd] = temp;
		}
	}
	if (ft_strlen(res[fd]) > 0)
		return (find_n(&res[fd], line));
	return (END);
}
