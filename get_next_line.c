#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char	*extract_line(char *stash)
{
	char	*line;
	size_t	i;

	if (!stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + (stash[i] == '\n') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*save_remainder(char *stash)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new = malloc(gnl_strlen(stash) - i);
	if (!new)
		return (free(stash), NULL);
	i++;
	j = 0;
	while (stash[i])
		new[j++] = stash[i++];
	new[j++] = '\0';
	free(stash);
	return (new);
}

static char	*read_and_store(int fd, char *stash)
{
	char	*buf;
	int		bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!gnl_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buf), NULL);
		buf[bytes] = '\0';
		stash = gnl_strjoin(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_store(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = save_remainder(stash);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("input.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
}
