# Get Next Line
Reading a line from a file descriptor is far too tedious.

<table>
  <tr>
    <td>**Function name**</td>
    <td>get_next_line</td>
  </tr>
  <tr>
    <td>**Prototype**</td>
    <td>char *get_next_line(int fd);</td>
  </tr>
  <tr>
    <td>**Parameters**</td>
    <td>fd: The file descriptor to read from</td>
  </tr>
  <tr>
    <td>**Return value**</td>
    <td>
      Read line: correct behavior
      NULL: there is nothing else to read, or an error occurred
    </td>
  </tr>
  <tr>
    <td>**External functions**</td>
    <td>read, malloc, free</td>
  </tr>
  <tr>
    <td>**Description**</td>
    <td>Write a function that returns a line read from a file descriptor</td>
  </tr>
</table>
