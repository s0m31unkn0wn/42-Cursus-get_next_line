/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 23:01:42 by armirono          #+#    #+#             */
/*   Updated: 2024/09/04 16:20:50 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	k;

	if (!s)
		return (0);
	k = 0;
	while (s[k])
		k++;
	return (k);
}

char	*ft_strcat(char *dest, char *src)
{
	int	n;
	int	destlen;

	n = 0;
	destlen = ft_strlen(dest);
	while (src[n])
		dest[destlen++] = src[n++];
	dest[destlen] = 0;
	return (dest);
}

static char	*separate_line(char *buffer)
{
	int		i;
	char	*remains;

	i = 0;
	while (buffer[i] && (buffer[i] != 10))
		i++;
	if (!buffer[i] || !buffer[i + 1])
		return (NULL);
	remains = ft_substr(buffer, (i + 1), (ft_strlen(buffer) - i));
	if (!remains || !remains[0])
	{
		free(remains);
		return (NULL);
	}
	buffer[i + 1] = 0;
	return (remains);
}

static char	*line_filler(int fd, char *leftovers, char *buffer)
{
	ssize_t	trigger;
	char	*temp;

	trigger = 1;
	if (!leftovers)
		leftovers = strcpy_in_strdup("");
	while (trigger > 0)
	{
		if (ft_strchr(leftovers, '\n'))
			break ;
		trigger = read(fd, buffer, BUFFER_SIZE);
		if (trigger == -1)
		{
			free(leftovers);
			return (NULL);
		}
		if (trigger == 0)
			break ;
		buffer[trigger] = 0;
		temp = leftovers;
		leftovers = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (leftovers);
}

char	*get_next_line(int fd)
{
	static char	*leftov[MAX_FD];
	char		*buffer;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (leftov[fd]);
		leftov[fd] = 0;
		return (NULL);
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = line_filler(fd, leftov[fd], buffer);
	free(buffer);
	if (!line || !line[0])
	{
		free(line);
		return (NULL);
	}
	leftov[fd] = separate_line(line);
	return (line);
}
