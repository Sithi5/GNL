/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:42:27 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/15 10:10:44 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free_s1(char const *s1, char const *s2)
{
	long long	size_s1;
	long long	size_s2;
	long long	i;
	char		*dest;

	if (s1 && s2)
	{
		i = 0;
		size_s1 = ft_strlen((char *)s1);
		size_s2 = ft_strlen((char *)s2);
		if (!(dest = (char *)malloc(sizeof(char) * (size_s1 + size_s2 + 1))))
			return (NULL);
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
		dest[i] = '\0';
		ft_strcat(dest, s2);
		ft_strdel((char **)&s1);
		return (dest);
	}
	else
		return (NULL);
}

int		ft_read_loop(char **next, int fd)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (ret);
		buf[ret] = '\0';
		if (!(*next = ft_strjoin_free_s1(*next, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

int		ft_assign(char **tmp, char **line, char **next)
{
	char *swap;

	swap = *tmp;
	if (!(*tmp = ft_strdup(*tmp + 1)))
		return (-1);
	if (!(*line = ft_strdup(*next)))
		return (-1);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*next;
	char		*tmp;
	int			ret;

	if ((fd < 0 || !line || read(fd, 0, 0) < 0) ||
			(!next && !(next = (char *)malloc(0))) ||
			((ret = ft_read_loop(&next, fd) < 0)))
		return (-1);
	if (ret <= 0 && !(*next))
		return (ret);
	if ((tmp = ft_strchr(next, '\n')))
	{
		tmp[0] = 0;
		if (ft_assign(&tmp, line, &next) == -1)
			return (-1);
		ft_strdel(&next);
		next = tmp;
	}
	else
	{
		if (!(*line = ft_strdup(next)))
			return (-1);
		ft_strclr(next);
	}
	return (1);
}
