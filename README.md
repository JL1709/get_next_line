# get_next_line

This repo provides a get_next_line() function that can read content line by line (e.g. from a file or stdin).
Tested on macOS Monterey.

## Installation

#### 1) Clone this repository 
```
git clone git@github.com:JL1709/get_next_line.git
```

#### 2)  Run program
Include header file to your code
```
#include "pathToGetNextLineFolder/get_next_line.h"
```
For example:
```ruby
#include "get_next_line.h"

int	main(void)
{
	int	i;
	char	*str;

	i = open("demo.txt", O_RDONLY);
	while ((str = get_next_line(i)))
	{
		printf("%s",str);
		free(str);
		str = NULL;
	}
	close(i);
	return (0);
}
```

Compile your code with desired buffer size
```
gcc -D BUFFER_SIZE=1 demo.c get_next_line.c get_next_line_utils.c
```

Run executable
```
./a.out
```

demo.c and demo.txt provided for testing.
