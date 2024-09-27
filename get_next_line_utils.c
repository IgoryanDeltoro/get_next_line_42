/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:17:00 by ibondarc          #+#    #+#             */
/*   Updated: 2024/09/27 12:59:24 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		src_len += size;
	else
		src_len += dst_len;
	i = 0;
	while (src[i] != '\0' && dst_len < (size - 1))
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;
	int		total_len;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen(s1) + 1;
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	result = (char *)malloc(sizeof(char) * total_len);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, s1_len);
	ft_strlcat(result, s2, total_len);
	return (result);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	int		s_len;

	s_len = ft_strlen(s) + 1;
	result = (char *)malloc(sizeof(char) * s_len);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s, s_len);
	return (result);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t s_len;
	size_t max_len;
	size_t actual_len;
	char *result;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	max_len = s_len - start;
	if (len < max_len)
		actual_len = len;
	else
		actual_len = max_len;
	result = (char *)malloc(actual_len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, actual_len + 1);
	return (result);
}