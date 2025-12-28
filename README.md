*This project has been created as part of the 42 curriculum by thtinner.*

## Description

Push_swap sorts a stack of integers using two stacks (a and b) and a limited set of operations, aiming to minimize the number of moves. The program implements a **cost-based greedy algorithm** (also known as the Turk Algorithm) that:

1. Pushes 2 elements to stack B to initialize
2. Pushes remaining elements to B (except last 3), selecting the cheapest element each time based on rotation cost
3. Sorts the final 3 elements in stack A using a hardcoded optimal solution
4. Pushes elements back to A in sorted order, always taking the max from B and placing it in its correct position
5. Rotates A to position the minimum element at the top


## Instructions

**Compilation:**
```bash
make
```

**Usage:**
```bash
./push_swap 2 1 3 6 5 8
./push_swap "4 67 3 87 23"
```

**Testing:**
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

**Cleaning:**
```bash
make clean    # Remove object files
make fclean   # Remove all compiled files
make re       # Recompile everything
```

## Error Handling

The program handles and reports errors for:
- Non-integer arguments
- Numbers exceeding INT_MIN to INT_MAX
- Duplicate numbers
- Invalid input format

Errors display "Error" on stderr and exit gracefully.

## Project Structure

```
├── main.c               # Entry point and main algorithm flow
├── sorting.c            # Core sorting functions
├── rotation_cost.c      # Cost calculation for rotations
├── rotation.c           # Rotation operations with output
├── stack_manipulation.c # Basic stack operations (push, swap, rotate)
├── stack_management.c   # Stack utility functions (min, max, count)
├── synchronization.c    # Synchronized rotation optimization
├── utility.c            # Helper functions (cheapest finder, cost comparison)
├── memory_management.c  # Error handling and memory cleanup
├── push_swap.h          # Header with all function prototypes
└── libft/              # Minimal custom C library (atol, split, strlen)
```

## Resources

- Push_swap visualizer: https://github.com/o-reo/push_swap_visualizer
- Stack data structures and linked list implementation
- Greedy algorithms and cost optimization strategies

**AI Usage:**
AI was used for debugging compilation issues, code review, and writing the README.
