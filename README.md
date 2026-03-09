# Get Next Line

This project has been created as part of the 42 curriculum by [elopez-u](https://profile.intra.42.fr/users/elopez-u).

## Description

Whether it's a file, stdin, or even later a network connection, you'll always need a way to read content line by line. It's time to start working on this function, which will be essential for your future projects.

## Instructions

## Usage

```c
// Use only ONE of the following fd assignments at a time

int fd;
char *line;

fd = open("example.txt", O_RDONLY); // Read from a file
// fd = STDIN_FILENO; // Read from stdin
while (1)
{
	line = get_next_line(fd);
	if (!line)
		break;
	printf("%s", line);
	free(line);
}
close(fd);

// You may also check for open and close errors
```

## Resources

You can test this repository or your own version to this project in:  
https://github.com/Tripouille/gnlTester.
