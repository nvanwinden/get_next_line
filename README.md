# get_next_line 
**Codam [42 Network] project**: write a function that returns a line read from a **file descriptor**, without the `\n`. Calling `get_next_line` in a loop allows you to read a file line by line. This function is implemented using **static variables** to keep track of the current reading thread. The bonus part is included in this project.

**Project requirements**

- The function prototype should be `int get_next_line(int fd, char **line);` in which the first parameter is the file descriptor for reading and the second parameter the value of what has been read
- Allowed external functions: **read**, **malloc**, **free**
- The program must compile with the flag `-D BUFFER_SIZE=[size]` which will be used as the buffer size for the `read` calls
- You should read as little as possible each time `get_next_line` is called i.e. don't read the while file at once and then process each line
- The use of global variables is forbidden

**Bonus**
- Use only a single static variable
- Be able to manage multiple file descriptors at the same time without losing the reading thread on each of the descriptors.

**Skills**
- Unix
- Rigor
- Algorithms & AI

**Return value**

|||
|--|--|
| 1 | a line has been read |
| 0 | EOF has been reached |
| -1 | an error happened |

[Read the full subject](https://github.com/nvanwinden/get_next_line/blob/main/en.subject.pdf).

## Instructions :clipboard:

### Clone repo

`git clone https://github.com/nvanwinden/get_next_line.git`

### Write a main.c

Read from a file:

```
#include "get_next_line.h"
#include <fcntl.h> /* open */
#include <stdio.h> /* printf */

int main () {

	int fd = open("get_next_line.c", O_RDONLY);
	char *line = NULL;
	ssize_t ret = 1;

	while (ret != 0) {

		ret = get_next_line(fd, &line);
		printf("[%zd] %s\n", ret, line);
		free(line);
	}
	close(fd);
	return (0);
}
```

Read from stdin:

```
#include "get_next_line.h"
#include <stdio.h> /* printf */

int main () {

	char *line = NULL;
	ssize_t ret = 1;

	while (ret != 0) {
		printf("Type something:\n");
		ret = get_next_line(STDIN_FILENO, &line);
		printf("[%zd] %s\n", ret, line);
		free(line);
	}
	return (0);
}
```

### Compile

`gcc -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c -o get_next_line`

### Run

`./get_next_line`
