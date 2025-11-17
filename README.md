# Get Next Line (C)

Get Next Line is a compact C implementation of get_next_line for reading lines from a file descriptor. It includes example usage, a simple test harness, and minimal plain-C helper functions for buffer handling.

## Features
- Read a single line from a file descriptor
- Minimal plain-C implementation (no external deps)
- Example usage and a simple test harness included

## Quick start

Build:
```
gcc -Wall -Wextra -Werror -o gnl get_next_line.c get_next_line_utils.c main.c
```

Run:
```
./gnl example.txt
```

API
- get_next_line(int fd) — returns a malloc'd string with the next line or NULL on EOF/error. See get_next_line.h for details.

Files of interest
- get_next_line.c — main implementation
- get_next_line_utils.c — helper functions
- get_next_line.h — public header
- main.c — small demo/test harness

## License
This project is available under the MIT License. See LICENSE for details.

