# Artificial Intelligence Laboratory (AI-LAB)

[![C++](https://img.shields.io/badge/Language-C%2B%2B17-blue.svg)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![AI Laboratory](https://img.shields.io/badge/Course-Artificial%20Intelligence%20Lab-success.svg)](#)

A comprehensive repository containing practical laboratory implementations of fundamental and advanced Artificial Intelligence algorithms, search heuristics, game playing techniques, machine learning models, knowledge representation inference engines, and evolutionary algorithms in C++.

---

## 👥 Student & Group Information

> [!IMPORTANT]
> **This repository and laboratory work belongs to the group with Enrollment Numbers:**
> - **Enrollment No. 25**
> - **Enrollment No. 22**
> - **Enrollment No. 11**
> - **Enrollment No. 71**
> - **Enrollment No. 45**

---

## 📚 Table of Contents

- [Repository Overview](#-repository-overview)
- [Lab Directory & Topics Summary](#-lab-directory--topics-summary)
- [Detailed Lab Breakdown](#-detailed-lab-breakdown)
  - [LAB 1: Graph Search & Linear Regression](#lab-1-graph-search--linear-regression)
  - [LAB 2: Heuristic & Informed Search](#lab-2-heuristic--informed-search)
  - [LAB 3: Logistic Regression & Classification](#lab-3-logistic-regression--classification)
  - [LAB 4: Classical AI & Backtracking](#lab-4-classical-ai--backtracking)
  - [LAB 5: Adversarial Search & Game Playing](#lab-5-adversarial-search--game-playing)
  - [LAB 6: Neural Networks (Perceptron)](#lab-6-neural-networks-perceptron)
  - [LAB 7: Knowledge Representation & Rule Inference](#lab-7-knowledge-representation--rule-inference)
  - [LAB 8: Genetic & Evolutionary Algorithms](#lab-8-genetic--evolutionary-algorithms)
- [Prerequisites & Build Instructions](#-prerequisites--build-instructions)
  - [Compilation Examples](#compilation-examples)
- [License](#-license)

---

## 🔍 Repository Overview

This repository organizes AI laboratory experiments across 8 dedicated modules (`LAB1` through `LAB8`). Each folder contains standalone, well-documented C++ source implementations designed for clean understanding of algorithmic mechanisms without heavy external dependencies.

```
ai-lab/
├── LAB1/
│   ├── BFS.cpp                    # Breadth-First Search graph traversal
│   ├── DFS.cpp                    # Depth-First Search graph traversal
│   └── Linear_regression.cpp      # Multivariate Linear Regression using Gradient Descent
├── LAB2/
│   ├── AO*.cpp                    # AO* Algorithm for AND-OR graphs
│   ├── Astar.cpp                  # A* Heuristic Search using Priority Queue
│   └── Hillclimb.cpp              # Hill Climbing local optimization
├── LAB3/
│   └── logistic_regression.cpp    # Logistic Regression binary classifier (Log-Loss)
├── LAB4/
│   ├── 8puzzlebfs.cpp             # 8-Puzzle problem solver via state-space BFS
│   ├── 8queens.cpp                # 8-Queens problem using Backtracking
│   └── tictactoe.cpp              # Interactive 2-Player Tic-Tac-Toe
├── LAB5/
│   └── Minmax.cpp                 # Minimax Algorithm for optimal game moves
├── LAB6/
│   └── singlelayerneuralnetwork.cpp # Single Layer Perceptron for Boolean Logic (AND)
├── LAB7/
│   ├── forwardChaining.cpp        # Forward Chaining inference engine
│   └── backwardChaining.cpp       # Backward Chaining goal-driven inference
├── LAB8/
│   └── genetic_algorithm.cpp      # Genetic Algorithm for function optimization
├── .gitignore                     # Build & system artifact exclusions
└── README.md                      # Project documentation and details
```

---

## 📋 Lab Directory & Topics Summary

| Lab | File | Algorithm / Topic | Description |
| :--- | :--- | :--- | :--- |
| **LAB 1** | `BFS.cpp` | Breadth-First Search | Explores level-by-level using a FIFO queue |
| **LAB 1** | `DFS.cpp` | Depth-First Search | Explores branch depth first using an iterative LIFO stack |
| **LAB 1** | `Linear_regression.cpp` | Linear Regression | Multivariate gradient descent for price prediction |
| **LAB 2** | `Astar.cpp` | A* Search Algorithm | Optimal graph search using $f(n) = g(n) + h(n)$ |
| **LAB 2** | `AO*.cpp` | AO* Search Algorithm | Evaluates AND-OR graphs to find minimum cost solution subgraphs |
| **LAB 2** | `Hillclimb.cpp` | Hill Climbing | Local search optimization finding the peak of an objective function |
| **LAB 3** | `logistic_regression.cpp` | Logistic Regression | Binary classification with Sigmoid activation and Log Loss |
| **LAB 4** | `8puzzlebfs.cpp` | 8-Puzzle Problem | BFS state space search to reach target sliding puzzle configuration |
| **LAB 4** | `8queens.cpp` | 8-Queens Problem | Constraint satisfaction & backtracking to place 8 non-attacking queens |
| **LAB 4** | `tictactoe.cpp` | Tic-Tac-Toe Game | 2-player interactive board game with win/draw validation |
| **LAB 5** | `Minmax.cpp` | Minimax Algorithm | Adversarial search finding optimal moves by maximizing utility |
| **LAB 6** | `singlelayerneuralnetwork.cpp` | Single Layer Perceptron | Perceptron weight update rule learning Boolean AND truth table |
| **LAB 7** | `forwardChaining.cpp` | Forward Chaining | Data-driven inference engine deriving new facts from rules |
| **LAB 7** | `backwardChaining.cpp` | Backward Chaining | Goal-driven deduction verifying sub-goals recursively |
| **LAB 8** | `genetic_algorithm.cpp` | Genetic Algorithm | Maximizes $f(x) = x^2$ via tournament selection, crossover, and mutation |

---

## 🔬 Detailed Lab Breakdown

### LAB 1: Graph Search & Linear Regression
- **`BFS.cpp`**: Demonstrates unweighted graph exploration starting from node `'A'` utilizing an `std::queue` and an `std::set` for visited states. Guarantees shortest path in unweighted graphs.
- **`DFS.cpp`**: Implements depth-first traversal using an explicit `std::stack` for robust traversal without deep recursion call-stack overhead.
- **`Linear_regression.cpp`**: Implements multiple linear regression with two features (square footage, bedrooms) to predict housing prices using batch gradient descent and mean squared error (MSE).

### LAB 2: Heuristic & Informed Search
- **`Astar.cpp`**: Computes shortest path from start node `'A'` to goal node `'D'` using a priority queue (min-heap). Balances path cost $g(n)$ and heuristic estimate $h(n)$.
- **`AO*.cpp`**: Implements heuristic search over AND-OR graph structures where tasks require either solving any one branch (OR) or all dependent sub-branches (AND).
- **`Hillclimb.cpp`**: Local search optimizer iteratively stepping towards neighboring states with higher evaluation scores until reaching local/global peak.

### LAB 3: Logistic Regression & Classification
- **`logistic_regression.cpp`**: Binary classification using the sigmoid activation function $\sigma(z) = \frac{1}{1 + e^{-z}}$, log-loss cost function, and gradient descent updates for weight $w$ and bias $b$.

### LAB 4: Classical AI & Backtracking
- **`8puzzlebfs.cpp`**: Models the 3x3 sliding tile puzzle state space. Discovers the sequence of tile swaps needed to transform a scrambled puzzle into the solved state.
- **`8queens.cpp`**: Backtracking solver placing 8 queens on an 8x8 chessboard such that no two queens share the same row, column, or diagonal.
- **`tictactoe.cpp`**: Complete terminal-based Tic-Tac-Toe implementation with board rendering and win/tie condition checks.

### LAB 5: Adversarial Search & Game Playing
- **`Minmax.cpp`**: Implements the classic Minimax algorithm for decision making in two-player zero-sum games. Evaluates recursive future states to select the optimal move against an optimal adversary.

### LAB 6: Neural Networks (Perceptron)
- **`singlelayerneuralnetwork.cpp`**: Models a single artificial neuron (Perceptron) with step activation. Iteratively adjusts weights and bias to linearly separate and learn the Boolean AND logic function.

### LAB 7: Knowledge Representation & Rule Inference
- **`forwardChaining.cpp`**: Starts from known facts (data-driven) and applies propositional Horn clauses to infer new conclusions until a fixed point is reached.
- **`backwardChaining.cpp`**: Starts from a hypothesis/goal (goal-driven) and works backwards, checking whether all necessary preconditions can be satisfied by known facts or other rules.

### LAB 8: Genetic & Evolutionary Algorithms
- **`genetic_algorithm.cpp`**: Evolutionary search algorithm optimizing the objective function $f(x) = x^2$. Employs a population of 5-bit binary chromosomes, tournament selection, single-point crossover, and bit-flip mutation over successive generations.

---

## 🛠️ Prerequisites & Build Instructions

### Prerequisites
- Modern C++ compiler supporting **C++17** or higher (`g++`, `clang++`, or MSVC).
- Git.

### Compilation Examples

You can compile any experiment using `g++` with C++17 support:

```bash
# Clone the repository
git clone https://github.com/prince00795/AI-LAB.git
cd AI-LAB

# Compile and run LAB 1: Breadth-First Search
g++ -std=c++17 LAB1/BFS.cpp -o LAB1_BFS && ./LAB1_BFS

# Compile and run LAB 2: A* Search
g++ -std=c++17 LAB2/Astar.cpp -o LAB2_Astar && ./LAB2_Astar

# Compile and run LAB 2: AO* Search (quote filename due to special character)
g++ -std=c++17 "LAB2/AO*.cpp" -o LAB2_AOStar && ./LAB2_AOStar

# Compile and run LAB 4: 8-Queens Problem
g++ -std=c++17 LAB4/8queens.cpp -o LAB4_8queens && ./LAB4_8queens

# Compile and run LAB 5: Minimax Algorithm
g++ -std=c++17 LAB5/Minmax.cpp -o LAB5_Minmax && ./LAB5_Minmax

# Compile and run LAB 6: Perceptron Neural Network
g++ -std=c++17 LAB6/singlelayerneuralnetwork.cpp -o LAB6_NN && ./LAB6_NN

# Compile and run LAB 8: Genetic Algorithm
g++ -std=c++17 LAB8/genetic_algorithm.cpp -o LAB8_GA && ./LAB8_GA
```

---

## 📜 Group Members / Enrollment Numbers

| S.No | Enrollment Number | Role / Contribution |
| :---: | :---: | :--- |
| 1 | **25** | AI Lab Implementation & Experimentation |
| 2 | **22** | AI Lab Implementation & Experimentation |
| 3 | **11** | AI Lab Implementation & Experimentation |
| 4 | **71** | AI Lab Implementation & Experimentation |
| 5 | **45** | AI Lab Implementation & Experimentation |

---

## 📄 License

This repository is available under the [MIT License](LICENSE).
