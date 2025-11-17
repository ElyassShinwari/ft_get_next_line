# get_next_line (short)

Minimal, Norminette-friendly implementation of the 42 project get_next_line.

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

License: educational / adapt freely.
![Uploading Get Next Line flow chart.png…]()
