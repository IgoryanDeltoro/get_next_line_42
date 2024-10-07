/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:36:06 by igoryan           #+#    #+#             */
/*   Updated: 2024/10/07 23:02:21 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    line = get_next_line(fd);
    printf("\n%s ", line);
    line = get_next_line(fd);
    printf("%s ", line);
    line = get_next_line(fd);
    printf("%s ", line);
    line = get_next_line(fd);
    printf("%s \n", line);
    line = get_next_line(fd);
    printf("%s \n", line);
    
    free(line);
    close(fd);
    return (0);
}
