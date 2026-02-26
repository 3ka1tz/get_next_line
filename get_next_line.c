#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	has_newline(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

ssize_t	read_from_fd(int fd, char **buf)
{
	char	*temp_buffer;
	ssize_t	bytes_read;
	char	*new_buffer;

	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (-1);
	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(temp_buffer);
		return (-1);
	}
	temp_buffer[bytes_read] = '\0';
	new_buffer = ft_strjoin(*buf, temp_buffer);
	free(temp_buffer);
	if (!new_buffer)
	{
		free(*buf);
		*buf = NULL;
		return (-1);
	}
	free(*buf);
	*buf = new_buffer;
	return (bytes_read);
}

char	*extract_line(char **buf)
{
	char	*new_line_pos;
	size_t	line_len;
	char	*line;
	char	*new_buffer;

	if (!*buf || **buf == '\0')
		return (NULL);
	new_line_pos = ft_strchr(*buf, '\n');
	if (new_line_pos)
		line_len = (new_line_pos - *buf) + 1;
	else
		line_len = (ft_strlen(*buf));
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *buf, line_len + 1);
	if (new_line_pos)
		new_buffer = ft_strdup(new_line_pos + 1);
	else
		new_buffer = NULL;
	free(*buf);
	*buf = new_buffer;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	ssize_t		bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!has_newline(buf))
	{
		bytes_read = read_from_fd(fd, &buf);
		if (bytes_read < 0)
		{
			free(buf);
			buf = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
	}
	line = extract_line(&buf);
	if (!line && buf)
	{
		free(buf);
		buf = NULL;
	}
	return (line);
}

// Reading from files
/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error: unable to open file descriptor\n");
		return (1);
	}
	line = NULL;
	while ((line = get_next_line(fd)))
	{
		if (line)
		{
			printf("%s", line);
			free(line);
		}
	}
	if (close(fd) < 0)
	{
		fprintf(stderr, "Error: unable to close file descriptor\n");
		return (1);
	}
	printf("\n");
	return (0);
}*/

// Reading from stdin
/*int	main(void)
{
	int		fd;
	char	*line;

	fd = STDIN_FILENO;
	line = NULL;
	while ((line = get_next_line(fd)))
	{
		if (line)
		{
			printf("%s", line);
			free(line);
		}
	}
	return (0);
}*/
