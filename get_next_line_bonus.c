/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:24:26 by ibondarc          #+#    #+#             */
/*   Updated: 2024/10/20 14:29:40 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fill_buf_by_line(int fd, char **total_str);
char	*extract_line(char *line_buffer);
char	*allocate_buffer(size_t size);

char	*get_next_line(int fd)
{
	static char	*total_str[OPEN_FILE];
	char		*line;
	char		*temp_buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_FILE)
		return (NULL);
	temp_buf = fill_buf_by_line(fd, &total_str[fd]);
	if (!temp_buf)
	{
		free(total_str[fd]);
		total_str[fd] = NULL;
		return (NULL);
	}
	total_str[fd] = extract_line(temp_buf);
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
	while (total_str[i] != '\n' && total_str[i] != '\0')
		i++;
	if (total_str[i] == '\0')
		return (NULL);
	j = 0;
	line = allocate_buffer(ft_strlen(total_str) - i);
	if (!line)
		return (NULL);
	while (j < (ft_strlen(total_str) - i))
	{
		line[j] = total_str[i + j + 1];
		j++;
	}
	total_str[i + 1] = '\0';
	if (*line == 0)
	{
		free(line);
		line = NULL;
	}
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
