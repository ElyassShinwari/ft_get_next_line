# get_next_line (short)

Get Next Line is a small C implementation of get_next_line to read lines from a file descriptor. It is designed for simple file I/O tasks and learning C buffer-handling and line parsing.

## Features
- Read a line from a file descriptor
- Minimal dependencies — plain C
- Example usage and simple tests included

## Quick start
```sh
# build (example)
gcc -Wall -Wextra -Werror -o gnl get_next_line.c main.c
./gnl example.txt
```

## Build
make fclean all

Or compile manually:
```sh
gcc -D BUFFER_SIZE=32 -Wall -Wextra -Werror -I. get_next_line.c get_next_line_utils.c -o gnl
```

## Usage
```c
int fd = open("file.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```
Returns a malloc'd string (includes `\n` if present). Caller must free.

## API
- `char *get_next_line(int fd);` — returns next line or `NULL` on EOF/error.

## Notes
- Uses a static `leftover` buffer to keep unread data between calls.
- Avoid repeated concatenation of a growing string inside the read loop — that caus<img width="1476" height="4959" alt="Get Next Line flow chart" src="https://github.com/user-attachments/assets/555a980e-bae6-404e-bfac-0008153bc8fd" />
es O(n^2) behavior and timeouts on very large single-line files with small BUFFER_SIZE.
- For large single-line files prefer an approach that minimizes realloc/copy (chunked buffers, doubling growth, or assemble final line once).

## Testing
Use your usual francinette/getcheck setup:
```sh
getcheck francinette --strict
```

## License
This project is available under the MIT License. See LICENSE for details.

License: educational / adapt freely.

