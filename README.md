# 🔄 Round-Robin CPU Scheduling Algorithm

A console-based implementation of the **Round-Robin (RR) CPU Scheduling Algorithm** written in C, developed as part of **CS-407: Operating Systems**. The program simulates RR scheduling both with and without process arrival times, visualizes execution via a Gantt chart, and computes key scheduling metrics.

---

## 📋 Table of Contents

- [Overview](#overview)
- [System Architecture](#system-architecture)
- [Key Features](#key-features)
- [Technical Stack](#technical-stack)
- [Getting Started](#getting-started)
- [Usage & Workflow](#usage--workflow)
- [Program Logic](#program-logic)
- [Known Limitations & Future Improvements](#known-limitations--future-improvements)
- [Project Team](#project-team)

---

## Overview

### What This Project Does

- **Dual Scheduling Modes:** Supports RR scheduling both without arrival time (all processes at t=0) and with varying arrival times
- **Gantt Chart Visualization:** Displays each process's execution intervals and remaining burst time in real-time
- **Scheduling Metrics:** Calculates individual and average Waiting Time (WT) and Turnaround Time (TAT) for all processes
- **Input Validation:** Rejects invalid inputs (negative burst times, zero quantum, non-menu choices) with clear error messages
- **Interactive Menu:** Menu-driven loop allows running multiple simulations without restarting

### Why This Project is Useful

This project demonstrates:
- Implementation of a core OS scheduling algorithm from scratch in C
- Manual queue and time-slice management without OS primitives
- Handling edge cases such as idle CPU time and non-zero arrival times
- Clean console UI design in a procedural paradigm

---

## System Architecture

The entire program is implemented in a **single-file procedural architecture** (`main.c`), following a straightforward top-down control flow:

```
main()
├── Menu Loop
│   ├── Option 1: RR Without Arrival Time
│   │   ├── Input: Number of processes, burst times, quantum
│   │   ├── Scheduling loop (index-based round-robin)
│   │   ├── Gantt Chart output
│   │   └── WT / TAT calculation and display
│   │
│   ├── Option 2: RR With Arrival Time
│   │   ├── Input: Number of processes, burst times, arrival times, quantum
│   │   ├── Sort by arrival time (bubble sort)
│   │   ├── Scheduling loop (arrival-aware, with idle detection)
│   │   ├── Gantt Chart output
│   │   └── WT / TAT calculation and display
│   │
│   └── Option 3: Exit
```

---

## Key Features

### ⚙️ Without Arrival Time (Option 1)
- Assumes all processes are available at time `t = 0`
- Cycles through processes using index-based modular arithmetic
- Skips already-completed processes (`remainingTime == 0`) without breaking the loop
- Correctly handles processes whose remaining time is less than the quantum

### ⏱️ With Arrival Time (Option 2)
- Accepts individual arrival times per process
- Sorts processes by arrival time using bubble sort before scheduling
- Detects CPU idle periods when no process has arrived yet and advances the clock by 1 unit
- Iterates through all arrived, incomplete processes each time unit

### 📊 Metrics
- **Turnaround Time (TAT):** Completion time − Arrival time
- **Waiting Time (WT):** TAT − Burst time
- **Averages:** Computed and displayed for both TAT and WT across all processes

---

## Technical Stack

| Component | Technology |
|-----------|-----------|
| **Language** | C (C99 compatible) |
| **Compiler** | GCC / Clang / MSVC |
| **I/O** | `stdio.h` — Console input/output |
| **Screen Clearing** | `stdlib.h` — `system("cls")` (Windows) |
| **Platform** | Primarily Windows; portable with minor modification |

### Libraries Used

- `<stdio.h>` — `printf`, `scanf` for all I/O
- `<stdlib.h>` — `system("cls")` for console clearing

---

## Getting Started

### Prerequisites

- **C Compiler:** GCC, Clang, or MSVC
- **Operating System:** Windows (primary); Linux/macOS with one-line modification (see note below)

### Installation & Compilation

1. **Clone the Repository**
   ```bash
   git clone https://github.com/ahmad-maqsood/Round-Robin-Algorithm-C.git
   cd Round-Robin-Algorithm-C
   ```

2. **Compile**
   ```bash
   # GCC (Linux/macOS)
   gcc main.c -o round_robin

   # GCC (Windows)
   gcc main.c -o round_robin.exe

   # Clang
   clang main.c -o round_robin

   # MSVC (Windows)
   cl main.c
   ```

3. **Run**
   ```bash
   # Linux/macOS
   ./round_robin

   # Windows
   round_robin.exe
   ```

> ⚠️ **Linux/macOS Note:** Replace `system("cls")` with `system("clear")` in `main.c` before compiling. There are multiple occurrences — replace all of them.

### First Run

On startup you will see:
```
====================================================================================================
----------ROUND ROBIN ALGORITHM----------
CS-407 : Operating Systems
====================================================================================================

=============================
Please Select an Option:-
1. Without Arrival Time.
2. With Arrival Time.
3. End the Program.
Input(1-3) :
```

---

## Usage & Workflow

### Option 1 — Without Arrival Time

1. Select `1` from the menu
2. Enter number of processes (max 20)
3. Enter burst time for each process (must be > 0)
4. Enter quantum time (must be > 0)
5. View the Gantt chart, individual WT/TAT, and averages

**Example output:**
```
====================Gant Chart==================
P1    || I.T : 0-2    || R.T : 2
P2    || I.T : 2-4    || R.T : 1
P3    || I.T : 4-6    || R.T : 0
P1    || I.T : 6-8    || R.T : 0
P2    || I.T : 8-9    || R.T : 0
```

### Option 2 — With Arrival Time

1. Select `2` from the menu
2. Enter number of processes (max 20)
3. Enter burst time and arrival time for each process
4. Enter quantum time
5. Processes are automatically sorted by arrival time before scheduling
6. CPU idle slots are shown in the Gantt chart when no process is available

---

## Program Logic

### Scheduling Algorithm — Without Arrival Time

```
index = (index + 1) % pN          // cycle through all processes
if remainingTime[index] == 0: skip
execTime = min(remainingTime[index], quantum)
remainingTime[index] -= execTime
currentTime += execTime
if remainingTime[index] == 0:
    TAT[index] = currentTime
    WT[index]  = TAT[index] - burstTime[index]
```

**Complexity:** O(n × (max_burst / quantum)) time, O(n) space.

### Scheduling Algorithm — With Arrival Time

```
for each process i where arrivalTime[i] <= currentTime and remainingTime[i] > 0:
    execute for min(remainingTime[i], quantum) units
if no process found:
    advance clock by 1 (idle)
```

**Complexity:** O(n² × (max_burst / quantum)) time in the worst case due to linear scan per time unit, O(n) space.

> **Note:** The arrival-time variant uses a linear scan each tick rather than a proper ready queue. This is correct but less efficient than a queue-based approach for large inputs. See [Future Improvements](#known-limitations--future-improvements).

---

## Known Limitations & Future Improvements

| Limitation | Description | Suggested Fix |
|------------|-------------|---------------|
| **`system("cls")` is platform-specific** | Only works on Windows without modification | Replace with `system("clear")` on Linux/macOS or use ANSI escape codes |
| **No ready queue** | Option 2 rescans all processes every tick — O(n²) | Use a `queue` or linked list to track arrived processes |
| **Bubble sort** | O(n²) sort for arrival times | Use `qsort()` from `<stdlib.h>` |
| **VLAs for process arrays** | `int burstTime[pN]` is a VLA (C99); not supported in MSVC by default | Use `malloc`/`free` for portable heap allocation |
| **No starvation detection** | Long quantum with many short processes can cause delays | Add aging or starvation warnings |
| **Process labels reset after sort** | After sorting by arrival time, `P1, P2...` labels no longer match original input order | Track original indices via a separate mapping array |
| **Max process hardcoded to 20** | Not dynamically configurable | Use `malloc` and remove the fixed cap |

---

## Project Team

**Course:** CS-407: Operating Systems  
**Institution:** University of Agriculture, Faisalabad

---

*Developed for educational purposes as part of the Operating Systems coursework.*
