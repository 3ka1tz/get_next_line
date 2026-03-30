# get_next_line

This project has been created as part of the 42 curriculum by elopez-u.

## Description

Whether it's a file, stdin, or even later a network connection, you'll always need a way to read content line by line. It's time to start working on this function, which will be essential for your future projects.

## Instructions

### 1. Clone the repository

```bash
git clone https://github.com/3ka1tz/get_next_line.git
```

### 2. Add a main function to the end of the get_next_line.c file

#### Option 1: Read from a file

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

#### Option 2: Read from stdin

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

These are just some main function examples.

### 3. Compile the code

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

If you omit `-D BUFFER_SIZE=42`, the value defined in get_next_line.h will be used.

### 4. Run the executable

#### Option 1: Read from a file

```bash
./gnl <input_file>
```

#### Option 2: Read from stdin

##### Option 2.1: Interactive input

```bash
./gnl
Hello
Hello
World
World
Ctrl + D
```

##### Option 2.2: Redirect output to a file

```bash
./gnl > <output_file>
Hello
World
Ctrl + D
```

These are just some example use cases. The real use of get_next_line is to use it for future bigger projects.

To use get_next_line in another project:
- Add get_next_line.c, get_next_line_utils.c and get_next_line.h to your project folder
- Include it with: #include "get_next_line.h"
- Add the .c files to your Makefile

If you want to use get_next_line in another project, just add these files and add #include "~/get_next_line.h" and .c files to Makefile.

## Resources

This tester can be very useful in order to test your get_next_line correctness before uploading it to the intra.

https://github.com/Tripouille/gnlTester
