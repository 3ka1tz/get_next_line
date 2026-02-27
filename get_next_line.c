#include "get_next_line.h"

#include <stdlib.h>
#include <unistd.h>

static int	has_newline(char *s)
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

static ssize_t	read_from_fd(int fd, char **buf)
{
	ssize_t	bytes_read;
	char	*tmp_buf;
	char	*new_buf;

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
	new_buf = ft_strjoin(*buf, tmp_buf);
	free(tmp_buf);
	if (!new_buf)
		return (-1);
	free(*buf);
	*buf = new_buf;
	return (bytes_read);
}

static char	*extract_line(char **buf)
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

	if (BUF_SIZE <= 0 || fd < 0)
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
