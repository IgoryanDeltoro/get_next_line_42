/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:24:26 by ibondarc          #+#    #+#             */
/*   Updated: 2024/10/07 23:01:19 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//static char    *_fill_line_buffer(int fd, char *left_c, char *buffer);
//static char    *_set_line(char *line);

char    *get_next_line(int fd)
{
	static char	*total_str;
	char		*line;
	char		*buffer;
	char		*temp;
	ssize_t		byte_read;
	int		i;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,  0, 0) < 0)
	{
		free(total_str);
		free(buffer);
		total_str = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			buffer = NULL;
		}
		if (byte_read == 0)
			break ;
		buffer[byte_read] = '\0';
		if (!total_str)
			total_str = ft_strdup("");
		temp = total_str;
		total_str = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	buffer = NULL;
	line = total_str;
	if (!line)
		return (NULL);
	i = 0;
	while (total_str[i] != '\0' && total_str[i] != '\n')
		i++;		
	if (total_str[i] == '\0' || total_str[1] == '\0' )
	{	
		total_str = NULL;
	}
	else
	{
		total_str = ft_substr(line, i + 1, ft_strlen(line) - i);
		if (total_str[0] == 0)
		{
			free(total_str);
			total_str = NULL;
		}
		line[i + 1] = '\0';
	}
	return line;
}


