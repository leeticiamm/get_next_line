<h1 align="center">Get Next Line</h1>
<p>Return the next line of given file descriptor every time you call the function

## Usage

1. Inside project dir create a text file (`file.txt`)

```
this is the first line
this is the second line
how many times you gonna call me?
```

2. Create a `main.c` file

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd)); // this is the first line
	printf("%s", get_next_line(fd)); // this is the second line
	printf("%s", get_next_line(fd)); // how many times you gonna call me?
	close(fd);
}
```

## Run

```sh
 gcc get_next_line.c get_next_line.h get_next_line_utils.c main.c && ./a.out
```
