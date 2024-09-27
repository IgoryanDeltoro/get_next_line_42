/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:24:26 by ibondarc          #+#    #+#             */
/*   Updated: 2024/09/27 15:30:06 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_utils.c"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

static char    *_fill_line_buffer(int fd, char *left_c, char *buffer);
static char    *_set_line(char *line);
char	*ft_strchr(const char *s, int c);

char    *get_next_line(int fd)
{
    static char *left_c;
    char        *line;
    char        *buffer;
    

    /*
     * fd < 0 : this means the file descriptor is invalid
     * BUFFER_SIZE <= 0 : we'll read BUFFER_SIZE characters at a time,
     * we can't read 0 or less character
     * read(fd, 0, 0) < 0 : this check lets us see if the file exists and
     * that it has some content to read from, or event that the file is 
     * openable to read, maybe the file descriptor is more than 0, but it
     * was open in 'modify only', that means we can't read it.
     */

    /* We have to free the buffer variable here since we'll not be using
     * it later in the function, freeing it prevents memory leaks.
     */
 
}

static char *_set_line(char *line_buffer)
{
    char    *left_c;
    ssize_t    i;
    
    i = 0;
    /* This loop let's us find the end of the line
     * either when we encounter a \n or a \0
     */
  
    /* here we check if the current or next character is a \0
     * if this is the case, this means that the line is empty so
     * we return NULL, this is what the subject asks us, send NULL
     * if there is no next line
     */
  
    /* here we take a substring from the end of the line to the end
     * of the whole line_buffer, that's what's left from our line
     */
 
    /* don't forget to set the last character to \0 to NUL-terminate
     * the line
     */    

}

static char	*_fill_line_buffer(int fd, char *left_c, char *buffer)
{
        /* ssize_t type works the same way as siyze_t type, but it can be
         * a negative number, something that size_t can't do.
         * Since most of the system function we'll be using return -1 to
         * signify errors, it could be useful to be able to store 
         * negative numbers
         */
	ssize_t	b_read;
	char	*tmp;


		/* if b_read is -1, it means there was an error reading
		 * the file descriptor, so we free left_c and return NULL.
		 */
	
		/* if b_read is 0, this surely means we read the whole
		 * file so there-s no need to stay in the loop
		 */
	
		/* if we didn't read anything, we can break out of the
		 * loop
		 */
         
		/* don't forget to set the last character of the buffer
		 * to 0 to NUL-terminate the string
		 */
		
		/* there we check if the left_c static char * is empty
		 * because if it's empty, we can't use ft_strjoin on it
		 */
		
		/* once we set left_c to be empty, if it was NUL
		 * or just that something was left in it from the
		 * last time we called get_next_line
		 * we can join the buffer we just read to left_c
		 */
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		/* we search in the buffer we just read if we read
		 * a \n or not
		 * if yes, we can break out of the loop
		 * if not, we go in the loop once again to read more 
		 * from the file.
		 */
		if (ft_strchr(buffer, '\n'))
			break ;
	
	    /* at the end of this function, we return the left_c string
	     * it will contain everything we read and ensure there's is 
	     * either a \0 or a \n within it.
	     */
	    return (left_c);
}
