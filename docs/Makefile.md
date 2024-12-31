# Push Swap Makefile Documentation

## Available Targets

- `make all` (default): Compiles the libft library and builds the push_swap executable
- `make clean`: Removes all object files and build directories
- `make fclean`: Performs clean and also removes the executable
- `make re`: Performs fclean and rebuilds everything
- `make norm`: Runs norminette check on the codebase
- `make libft`: Builds only the libft library

## Build Configurations

The Makefile supports three build configurations controlled by the `BUILD` variable:

- `release` (default): Standard compilation with warnings
- `debug`: Includes debug symbols and AddressSanitizer
- `valgrind`: Includes debug symbols for valgrind analysis

Example usage:
```bash
make BUILD=debug
make BUILD=valgrind
```

## Important Variables

- `CC`: Compiler selection (defaults to gcc on macOS, cc on other platforms)
- `TARGET`: Output executable name (push_swap)
- `CFLAGS`: Compiler flags based on build configuration
- `INC`: Include directories
- `LIB`: Library flags for linking

## Directory Structure

- `src/`: Source files
- `include/`: Header files
- `obj/`: Object files (generated)
- `bin/`: Output executables
- `libft/`: libft library
- `gc_collector/`: Garbage collector library

## Dependencies

The build system automatically generates and maintains dependency files (.d) to ensure proper rebuilding when headers are modified.

## Platform Support

The Makefile includes automatic platform detection for macOS vs Linux, adjusting compiler and flags accordingly.
