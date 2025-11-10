# Get Next Line
Reading a line from a file descriptor is far too tedious.

**Summary:**
This project is about programming a function that returns a line read from a file descriptor.

## Goals
This project will not only allow you to add a highly useful function to your collection, but it will also teach you an important concept in C programming: static variables.

## Mandatory part
<table>
  <tr>
    <td><strong>Function name</strong></td>
    <td>get_next_line</td>
  </tr>
  <tr>
    <td><strong>Prototype</strong></td>
    <td>char *get_next_line(int fd);</td>
  </tr>
  <tr>
    <td><strong>Parameters</strong></td>
    <td>fd: The file descriptor to read from</td>
  </tr>
  <tr>
    <td><strong>Return value</strong></td>
    <td>
      Read line: correct behavior<br>
      NULL: there is nothing else to read, or an error occurred
    </td>
  </tr>
  <tr>
    <td><strong>External functions</strong></td>
    <td>read, malloc, free</td>
  </tr>
  <tr>
    <td><strong>Description</strong></td>
    <td>Write a function that returns a line read from a file descriptor</td>
  </tr>
</table>

- Repeated calls (e.g., using a loop) to your `get_next_line()` function should let you read the text file pointed to by the file descriptor, **one line at a time**.

- Your function should return the line that was read.<br>
If there is nothing left to read or if an error occurs, it should return `NULL`.

- Make sure that your function works as expected both when reading a file and when reading from the standard input.

- **Please note** that the returned line should include the terminating `\n` character, except when the end of the file is reached and the file does not end with a `\n` character.

- Your header file `get_next_line.h` must at least contain the prototype of the `get_next_line()` function.

- Add all the helper functions you need in the `get_next_line_utils.c` file.

A good start would be to know what a [static variable](https://en.wikipedia.org/wiki/Static_variable) is.

- Because you will have to read files in `get_next_line()`, add this option to your compiler call: `-D BUFFER_SIZE=n`<br>
It will define the buffer size for `read()`.<br>
The buffer size value will be adjusted by your peer evaluators and the Moulinette to test your code.

We must be able to compile this project with and without the -D BUFFER_SIZE flag in addition to the usual flags. You may choose any default value you prefer.

- You will compile your code as follows (a buffer size of 42 is used as an example): cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

- `get_next_line()` exhibits undefined behavior if the file associated with the file descriptor is modified after the last call, while `read()` has not yet reached the end of the file.

- `get_next_line()` also exhibits undefined behavior when reading a binary file. However, you can implement a logical way to handle this behavior if you want to.

Does your function still work if the BUFFER_SIZE value is 9999? If it is 1? 10000000? Do you know why?

Read as little data as possible each time `get_next_line()` is called. If a newline character is encountered, return the current line immediately. Don’t read the whole file and then process each line.

**Forbidden**
- You are not allowed to use your `libft` in this project.

- `lseek()` is forbidden.

- Global variables are forbidden.
