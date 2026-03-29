# get_next_line

This project has been created as part of the 42 curriculum by elopez-u.

## Description

Whether it's a file, stdin, or even later a network connection, you'll always need a way to read content line by line. It's time to start working on this function, which will be essential for your future projects.

## Instructions

1. Clone the repository
```bash
git clone https://github.com/3ka1tz/get_next_line.git
```

2. Add a main function to the end of the get_next_line.c file

**Option 1: Read from a file**
```c
#include <fcntl.h>
#include <stdio.h>

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
```

**Option 2: Read from stdin**
```c
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = STDIN_FILENO;
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
```

3. Compile the code
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

4. Run the executable
```bash
./gnl
```

## Resources

https://github.com/Tripouille/gnlTester
