/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 00:16:32 by armirono          #+#    #+#             */
/*   Updated: 2024/09/03 20:57:53 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*memset_in_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;
	int		c;

	i = 0;
	c = 0;
	result = malloc(count * size);
	if (!result)
		return (0);
	while (i < count * size)
		((unsigned char *)result)[i++] = (unsigned char) c;
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;

	if (!s1 || !s2)
		return (0);
	joined = memset_in_calloc((ft_strlen(s1) +1 + ft_strlen(s2)), sizeof(char));
	if (!joined)
		return (NULL);
	ft_strcat(joined, (char *)s1);
	ft_strcat(joined, (char *)s2);
	return (joined);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		start = ft_strlen(s);
	if ((ft_strlen(s) - start) <= len)
		len = ft_strlen(s) - start;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while ((i < len) && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*strcpy_in_strdup(const char *src)
{
	char	*dest;
	int		k;

	if (!src)
		return (0);
	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (0);
	k = 0;
	while (src[k])
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = 0;
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s && s[i] && (s[i] != (char) c))
		i++;
	if (s && (s[i] == (char) c))
		return ((char *)&s[i]);
	return (0);
}
