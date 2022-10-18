# get_next_line 
**Codam [42 Network] project**: write a function that returns a line read from a **file descriptor**, without the `\n`. Calling the `get_next_line` in a loop allows you to read a file line by line. This function is implemented using **static variables** to keep track of the current reading thread.

**Project requirements** :clipboard:

- The function prototype should be `int get_next_line(int fd, char **line);` in which the first parameter is the file descriptor for reading and the second parameter the value of what has been read
- Allowed external functions: **read**, **malloc**, **free**
- The program must compile with the flag `-D BUFFER_SIZE=[size]` which will be used as the buffer size for the `read` calls
- You should read as little as possible each time `get_next_line` is called i.e. don't read the while file at once and then process each line
- The use of global variables are forbidden

**Bonus**
- Use only a single static variable
- Be able to manage multiple file descriptors at the same time without losing the reading thread on each of the descriptors.

**Return value**

|||
|--|--|
| 1 | a line has been read |
| 0 | EOF has been reached |
| -1 | an error happened |

**Tests**
- Read from a file
- Read from stdin
- Read from a redirection
