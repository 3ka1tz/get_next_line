# Get Next Line
Reading a line from a file descriptor is far too tedious.

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
