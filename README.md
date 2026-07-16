# BSQ

42 Piscine final project.

This repository contains my solution for the BSQ project completed during the 42 Piscine.  
The goal of the project is to find and display the biggest possible square on a map while avoiding obstacles.

## Project description

BSQ reads a map and replaces the largest valid square of empty cells with the full character defined in the map header.

A map contains:
- A first line describing the map
- Empty cells
- Obstacle cells

Example header:

```txt
9.ox
```

Meaning:

```txt
9 = number of lines
. = empty character
o = obstacle character
x = full character
```

## Usage

Compile the project:

```sh
make
```

Run with one map file:

```sh
./bsq maps/example_file
```

Run with multiple map files:

```sh
./bsq map1 map2 map3
```

Run with standard input:

```sh
./bsq < maps/example_file
```

or:

```sh
cat maps/example_file | ./bsq
```

## Example

Input:

```txt
4.ox
....
.o..
....
....
```

Example output:

```txt
..xx
.oxx
..xx
....
```

The program fills the biggest valid square using the `full` character from the map header.

## Project structure

```txt
BSQ/
├── includes/
│   └── bsq.h
├── maps/
│   └── example_file
├── scripts/
│   └── map_generator.pl
├── srcs/
│   ├── main.c
│   ├── ft_process_file.c
│   ├── ft_process_stdin.c
│   ├── ft_process_error.c
│   ├── ft_read_file.c
│   ├── ft_read_fd.c
│   ├── ft_parse_map.c
│   ├── ft_parse_header.c
│   ├── ft_parse_grid.c
│   ├── ft_solve_map.c
│   ├── ft_square_sizes.c
│   ├── ft_fill_square.c
│   ├── ft_print_map.c
│   ├── ft_free_map.c
│   ├── ft_init.c
│   └── ft_utils.c
├── Makefile
├── .gitignore
└── README.md
```

## Algorithm

The solver uses dynamic programming.

For each cell, the program stores the size of the biggest square ending at that position.

Rules:

```txt
obstacle cell -> 0
empty cell    -> 1 + min(top, left, top-left)
```

The biggest value found represents the largest square.  
The program then replaces that square with the map’s full character.

## Map validation

The program checks that:

- The first line starts with a valid positive number
- The last three characters of the first line are different printable characters
- All map lines have the same length
- The number of map lines matches the number in the header
- The map contains only the empty and obstacle characters
- The map has at least one valid line and one valid column

## Error handling

If a map is invalid or cannot be read, the program prints:

```txt
map error
```

For multiple files, an empty line is printed between each result or error message.

## Topics covered

- File reading with `open`, `read`, and `close`
- Standard input handling
- Dynamic memory allocation with `malloc` and `free`
- Map parsing and validation
- Structures
- Dynamic programming
- Error handling
- Makefile usage
- 42 Norminette formatting

## Testing

Example tests:

```sh
make fclean
make
./bsq maps/example_file
./bsq < maps/example_file
cat maps/example_file | ./bsq
./bsq maps/example_file maps/example_file
```

Invalid map tests should print:

```txt
map error
```

Memory should be checked with:

```sh
valgrind --leak-check=full ./bsq maps/example_file
```

## Notes

This repository is part of my work during the 42 Piscine.  
The goal of BSQ is to combine parsing, memory management, algorithmic thinking, and clean project organization in C.

Compiled binaries and object files should be removed or ignored before submitting.

## Author

KruKuma & arnmathey-afk
