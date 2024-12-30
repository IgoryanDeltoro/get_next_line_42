/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:24:26 by ibondarc          #+#    #+#             */
/*   Updated: 2024/10/20 14:31:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_buf_by_line(int fd, char **total_str);
char	*extract_line(char *line_buffer);
char	*allocate_buffer(size_t size);

char	*get_next_line(int fd)
{
	static char	*total_str;
	char		*line;
	char		*temp_buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp_buf = fill_buf_by_line(fd, &total_str);
	if (!temp_buf)
		return (free(total_str), total_str = NULL, NULL);
	total_str = extract_line(temp_buf);
	line = ft_strdup(temp_buf);
	if (line)
		return (free(temp_buf), line);
	else
		return (free(line), temp_buf);
}

char	*fill_buf_by_line(int fd, char **total_str)
{
	ssize_t	buf_read;
	char	*temp;
	char	*buffer;

	buf_read = 1;
	buffer = allocate_buffer(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (buf_read > 0)
	{
		buf_read = read(fd, buffer, BUFFER_SIZE);
		if (buf_read == -1)
			return (free(buffer), NULL);
		if (buf_read == 0)
			break ;
		buffer[buf_read] = '\0';
		if (!(*total_str))
			*total_str = ft_strdup("");
		temp = *total_str;
		*total_str = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), *total_str);
}

char	*extract_line(char *total_str)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (total_str[i] != '\n' && total_str[i] != '\0')
		i++;
	if (total_str[i] == '\0')
		return (NULL);
	line = allocate_buffer(ft_strlen(total_str) - i);
	if (!line)
		return (NULL);
	while (j < (ft_strlen(total_str) - i))
	{
		line[j] = total_str[i + j + 1];
		j++;
	}
	if (line[0] == '\0')
	{
		free(line);
		line = NULL;
	}
	total_str[i + 1] = '\0';
	return (line);
}

char	*allocate_buffer(size_t size)
{
	char	*buffer;

	buffer = (char *)malloc((size) * sizeof(char));
	if (!buffer)
		return (NULL);
	return (buffer);
}
