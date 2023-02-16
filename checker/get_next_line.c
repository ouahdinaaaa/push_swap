/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:44:26 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/16 16:16:03 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_res(char *line)
{
	size_t	i;
	char	*str;

	if (!*line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_delete(char	*line)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	str = NULL;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i])
	{
		str = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
		if (!str)
			return (str);
		if (line[i] == '\n')
			i++;
		while (line[i])
			str[j++] = line[i++];
		str[j] = '\0';
	}
	free(line);
	return (str);
}

char	*ft_free(char *line, char *buff)
{
	if (line)
		free(line);
	if (buff)
		free(buff);
	return (NULL);
}

static
char	*ft_retry(int fd, char **buff, t_dataa *data, int boolean)
{
	static char	*line;

	if (boolean)
	{
		free(*buff);
		free(line);
		return (0);
	}
	while (data->ret && !ft_strchr(line, '\n'))
	{
		data->ret = read(fd, *buff, BUFFER_SIZE);
		if (data->ret == -1)
			return (ft_free(line, *buff), NULL);
		(*buff)[data->ret] = '\0';
		line = ft_gnl_strjoin(line, *buff);
		if (!line)
			return (ft_free(line, *buff), NULL);
		if (BUFFER_SIZE > (int)ft_strlen(*buff))
			break ;
	}
	data->res = ft_res(line);
	line = ft_delete(line);
	free(*buff);
	return (data->res);
}

char	*get_next_line(int fd, t_dataa *data, int boolean)
{
	char		*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buff)
		return (NULL);
	data->ret = 1;
	return (ft_retry(fd, &buff, data, boolean));
}
