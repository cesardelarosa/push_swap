# Push_Swap

[![GitHub repo](https://img.shields.io/badge/Repository-github-blue)](https://github.com/cesardelarosa/push_swap)
[![Status](https://img.shields.io/badge/status-active-brightgreen)]()

Push_Swap is a highly optimized sorting algorithm project written in C, designed under the strict 42 Norm standards. The project includes a main push_swap executable that sorts a list of integers using a limited set of operations, and a bonus checker program that validates the sequence of moves produced by push_swap.

---

## Table of Contents

- [Installation](#installation)
- [Compilation](#compilation)
- [Usage](#usage)
- [Algorithm Overview](#algorithm-overview)
  - [Align A](#align-a)
  - [a_to_b](#a_to_b)
  - [b_to_a](#b_to_a)
  - [Main Flow](#main-flow)
- [Bonus: Checker](#bonus-checker)
- [Performance](#performance)
- [Project Structure](#project-structure)
- [Code Style & Norms](#code-style--norms)
- [Contributing](#contributing)
- [License](#license)
- [Author](#author)

---

## Installation

Clone the repository with submodules (e.g., libft) using the following command:

```bash
git clone --recursive https://github.com/cesardelarosa/push_swap.git
```

---

## Compilation

A Makefile is provided to compile both the main project and the bonus checker.

- **Compile the main push_swap executable:**

  ```bash
  make
  ```

- **Compile the bonus (checker) executable:**

  ```bash
  make bonus
  ```

- **Compile both:**

  ```bash
  make both
  ```

- **Clean object files:**

  ```bash
  make clean
  ```

- **Clean executables and object files:**

  ```bash
  make fclean
  ```

---

## Usage

- **Running push_swap:**

  Provide the list of integers as arguments:

  ```bash
  ./push_swap 3 2 1 6 5 8
  ```

- **Using the bonus checker:**

  You can pipe the output of push_swap to the checker to validate the moves:

  ```bash
  ./push_swap 3 2 1 6 5 8 | ./checker 3 2 1 6 5 8
  ```

---

## Algorithm Overview

The Push_Swap algorithm is divided into several logical parts. Below are the mermaid diagrams representing the workflow of each key component.

### Align A

This function rotates stack A until the smallest element is at the top:

```mermaid
flowchart TD
    P3_Start[["align_a()"]] --> P3_Find[["min_idx = find_min_index(A)"]]
    P3_Find --> P3_Check{"min_idx ≤ n_a/2?"}
    P3_Check -- Yes --> P3_RA[["RA × min_idx"]]
    P3_Check -- No --> P3_RRA[["RRA × (n_a - min_idx)"]]
```

### a_to_b

The `a_to_b` function pushes elements from stack A to stack B based on a dynamic pivot determined by logarithmic heuristics, ensuring that smaller elements are pushed first.

```mermaid
flowchart TD
    A["Start a_to_b(stacks)"]
    B{"A unsorted && size > 3?"}
    D["Loop Start"]
    E{"Top of A < $$\lfloor \log_{1.065}(n_{total}) \rfloor$$-th smallest)"}
    F["PB"]
    G["RA"]
    H["Loop Continue?"]
    I["Outer Loop Continue?"]
    J{"A unsorted?"}
    K["SA"]
    L["End a_to_b"]

    A --> B
    B -- Yes --> D
    D --> E
    E -- Yes --> F
    E -- No --> G
    F --> H
    G --> H
    H -- Yes --> D
    H -- No --> I
    I -- Yes --> B
    I -- No --> J
    J -- Yes --> K
    J -- No --> L
    K --> L
```

### b_to_a

After the partitioning is complete, the `b_to_a` function pushes elements back to stack A in the correct order, calculating the optimal rotations to minimize the number of operations.

```mermaid
flowchart TD
    Start["b_to_a(stacks)"] --> CheckBEmpty{"Is stack B empty?"}
    CheckBEmpty -- Yes --> End[["Return"]]
    CheckBEmpty -- No --> BestMove

    subgraph BestMove [Calculate Optimal Move]
        direction TB
        BM_Start[["For each node in B:"]] --> BM_InitVars["current_idx=0\nbest_cost=INT_MAX"]
        BM_InitVars --> BM_Loop{"current_idx < n_b?"}
        BM_Loop -- Yes --> BM_CalcTarget["target_idx = find_insert_index(A, node_value)\nraw_ra = target_idx\nraw_rb = current_idx"]
        BM_CalcTarget --> BM_OptimizeRot["Optimize rotations:\nra = raw_ra > n_a/2 ? raw_ra - n_a : raw_ra\nrb = raw_rb > n_b/2 ? raw_rb - n_b : raw_rb"]
        BM_OptimizeRot --> BM_CalcCost["Calculate cost:\ncost = (ra*rb > 0) ? max(abs(ra),abs(rb)) : abs(ra)+abs(rb)"]
        BM_CalcCost --> BM_Compare{"cost < best_cost?"}
        BM_Compare -- Yes --> BM_UpdateBest["best_ra=ra\nbest_rb=rb\nbest_cost=cost"]
        BM_Compare -- No --> BM_Incr
        BM_UpdateBest --> BM_Incr["current_idx++"]
        BM_Incr --> BM_Loop
        BM_Loop -- No --> BM_End[["Return best_ra, best_rb"]]
    end

    BestMove --> ExecuteRotations

    subgraph ExecuteRotations [Execute Rotations]
        direction TB
        ER_Start[["best_ra = optimized A rotations\nbest_rb = optimized B rotations"]] --> ER_CheckRR{"Same direction?\n(best_ra > 0 && best_rb > 0)"}
        ER_CheckRR -- Yes --> ER_DoRR[["Execute RR:\nra_remaining = best_ra - 1\nrb_remaining = best_rb - 1"]]
        ER_CheckRR -- No --> ER_CheckRRR{"Reverse direction?\n(best_ra < 0 && best_rb < 0)"}
        ER_CheckRRR -- Yes --> ER_DoRRR[["Execute RRR:\nra_remaining = best_ra + 1\nrb_remaining = best_rb + 1"]]
        ER_CheckRRR -- No --> ER_Separate[["ra_remaining = best_ra\nrb_remaining = best_rb"]]
        
        ER_DoRR --> ER_ProcessA
        ER_DoRRR --> ER_ProcessA
        ER_Separate --> ER_ProcessA
        
        subgraph ER_ProcessA [Process A Rotations]
            direction LR
            PA_Check{"ra_remaining != 0?"} -- Yes --> PA_Dir{"ra_remaining > 0?"}
            PA_Dir -- Yes --> PA_RA[["RA (remaining--)"]]
            PA_Dir -- No --> PA_RRA[["RRA (remaining++)"]]
        end
        
        subgraph ER_ProcessB [Process B Rotations]
            direction LR
            PB_Check{"rb_remaining != 0?"} -- Yes --> PB_Dir{"rb_remaining > 0?"}
            PB_Dir -- Yes --> PB_RB[["RB (remaining--)"]]
            PB_Dir -- No --> PB_RRB[["RRB (remaining++)"]]
        end
        
        ER_ProcessA --> ER_ProcessB
    end

    ExecuteRotations --> PushA[["PA: Push to stack A\nn_a++\nn_b--"]] --> CheckBEmpty
```

### Main Flow

The overall execution of the push_swap program follows this sequence:

```mermaid
flowchart TD
    A["main()"]
    A --> B["parser(argc, argv)"]
    B --> C["a_to_b()"]
    C --> D["b_to_a()"]
    D --> E["align_a()"]
    E --> F["free_stacks()"]
```

---

## Bonus: Checker

The bonus component is a checker program that validates the output of push_swap. To use the checker, pipe the output of push_swap into checker:

```bash
./push_swap 3 2 1 6 5 8 | ./checker 3 2 1 6 5 8
```

The checker reads the list of moves from push_swap and verifies whether the sequence correctly sorts the provided input.

---

## Performance

The project includes a performance graph (`performance_graph.png`) which displays the number of moves required across different executions based on the number of elements to sort. This graph helps in visualizing the efficiency and scalability of the algorithm.

| Number of Elements | Max/Avg Moves          |
|--------------------|------------------------|
| 3 elements         | Max: 2                |
| 5 elements         | Max: 11               |
| 100 elements       | Avg: 565 (max ~650)   |
| 500 elements       | Avg: 4300 (max ~4800) |

![Performance Graph](performance_graph.png)

---

## Project Structure

```
push_swap/
├── align_a.mmd            # Mermaid diagram for align_a function
├── a_to_b.mmd             # Mermaid diagram for a_to_b function
├── b_to_a.mmd             # Mermaid diagram for b_to_a function
├── main.mmd               # Mermaid diagram for main program flow
├── bonus/                 # Bonus files (checker and related source files)
├── checker                # Checker executable (compiled from bonus)
├── libft/                 # Custom libft library
├── Makefile               # Build instructions
├── performance_graph.png  # Performance graph image
├── src/                   # Main source files for push_swap
└── tests/                 # Test cases and scripts
```

---

## Code Style & Norms

This project adheres strictly to the 42 Norm standards:
- **Tabs Only:** Code indentation uses tabs exclusively.
- **Variable Declaration:** Variables are declared before assignment.
- **Libft Usage:** Custom libft functions are used in place of standard library functions (e.g., avoiding string.h functions).
- **Control Structures:** The project avoids using forbidden constructs such as `for` loops and ternary operators, ensuring the code complies with the Norm.

---

## Contributing

Contributions, bug fixes, or suggestions are welcome! Feel free to fork the repository and open a pull request with your improvements.

---

## License

Distributed under the **GPL 3** License. See the [LICENSE](LICENSE) file for more details.

---

## Author

**Cesar De La Rosa**  
Email: [code@cesardelarosa.xyz](mailto:code@cesardelarosa.xyz)

---

*Happy sorting and code reviewing!*  
*And remember: if your code isn’t pushing, it isn’t sorted!*

