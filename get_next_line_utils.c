/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:17:00 by ibondarc          #+#    #+#             */
/*   Updated: 2024/10/08 16:02:36 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	result = malloc(sizeof(char) * (total_len + 1));
	if (!result)
		return (NULL);
	result[total_len] = '\0';
	while (s1_len--)
	{
		result[s1_len] = s1[s1_len];
	}
	while (total_len-- > ft_strlen(s1))
	{
		result[total_len] = s2[--s2_len];
	}
	return (result);
}

char	*ft_strdup(char *s)
{
	char	*result;
	int		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	result = malloc(sizeof(char) * (s_len + 1));
	if (!result)
		return (NULL);
	result[s_len] = '\0';
	while (s_len--)
		result[s_len] = s[s_len];
	return (result);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
