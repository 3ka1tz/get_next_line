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
    <td>Read line: correct behavior<br>NULL: there is nothing else to read, or an error occurred</td>
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
