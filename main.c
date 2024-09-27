#include "./get_next_line.c"

int main(void)
{
    int     fd;
    char    *line;

    // Open a test file in read-only mode
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    // Use get_next_line to read lines from the file and print them
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);  // Don't forget to free the line after it's printed
    }

    // Close the file descriptor after use
    close(fd);
    return (0);
}

// char	*ft_putchar_test_file(char c, int fd)
// {
// 	char		*buffer;
// 	char		*tmp;
// 	ssize_t		bytes_read;
// 	static char	*left_c;
// 	char err_message[] = "test.txt not found.\n";
// 	int i;
// 	int	err_fd;

// 	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	i = 0;
// 	// bytes_read = 1;
// 	if (fd > 0)
// 	{
// 		while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
// 		{
// 			if (!left_c)
// 				left_c = ft_strdup("");
// 			tmp = left_c;
// 			left_c = ft_strjoin(tmp, buffer);
// 			free(tmp);
// 			tmp = NULL;

// 			if (ft_strchr(buffer, '\n'))
// 				break ;
// 		}
// 	}
// 	else if (err_fd > 0)
// 	{
// 		err_fd =  open("error.txt", O_RDWR);
// 		while (err_message[i] != '\0')
// 		{
// 			write(err_fd, &err_message[i], 1);
// 			i++;
// 		}
// 		close(err_fd);
// 	}
// 	return (left_c);
// }
