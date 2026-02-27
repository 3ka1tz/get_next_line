#include "get_next_line.h"

#include <fcntl.h>
#include <stdlib.h>
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
	ssize_t	bytes_read;
	char	*tmp_buf;
	char	*old_buf;

	tmp_buf = malloc(BUF_SIZE + 1);
	if (!tmp_buf)
		return (-1);
	bytes_read = read(fd, tmp_buf, BUF_SIZE);
	if (bytes_read < 0)
	{
		free(tmp_buf);
		return (-1);
	}
	tmp_buf[bytes_read] = '\0';
	tmp_buf = ft_strjoin(*buf, tmp_buf);
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

	if (fd < 0 || BUF_SIZE <= 0)
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
