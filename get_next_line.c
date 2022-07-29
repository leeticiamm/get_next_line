/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:30:25 by lmagalha          #+#    #+#             */
/*   Updated: 2022/07/29 14:34:15 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *line)
{
	int		doing;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	doing = 1;
	while (doing != 0 && !ft_strchr(line, '\n'))
	{
		doing = read(fd, buf, BUFFER_SIZE);
		if (doing == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[doing] = '\0';
		if (!line)
		{
			line = malloc(sizeof(char));
			line[0] = '\0';
		}
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

static char	*ft_divide(char *line)
{
	size_t	i;
	char	*str;

	if (!*line)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, line, i + 1);
	if (line[i] == '\n')
		str[i] = '\n';
	str[i + 1] = '\0';
	return (str);
}

static char	*ft_clean(char *line)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!temp)
		return (NULL);
	while (line[i] != '\0')
		temp[j++] = line[++i];
	temp[j] = '\0';
	free(line);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read(fd, line);
	if (!line)
		return (NULL);
	str = ft_divide(line);
	line = ft_clean(line);
	return (str);
}
