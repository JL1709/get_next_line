# get_next_line

This repo provides a get_next_line() function that can read content line by line (e.g. from a file or stdin).

## Installation

#### 1) Clone this repository 
```
git clone git@github.com:JL1709/get_next_line.git
```

#### 2) Execute Makfile (creates library file "libftprintf.a")
```
cd get_next_line/
make
```

#### 3)  Run program with library
Include header file to your code
```
#include "pathToPrintfFolder"/ft_printf.h
```
For example (main.c included in repo for test cases):
```ruby
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char c[5] = {'H', 'e', 'l', 'l', 'o'};
	char *src = "world";
	ft_printf("%c%c%c%c%c, %s!\n", c[0], c[1], c[2], c[3], c[4], src);
	
	return (0);
}
```

Compile your code with library file, e.g.
```
gcc main.c "pathToPrintfFolder"/libft.a
```

Run executable
```
./a.out
```
