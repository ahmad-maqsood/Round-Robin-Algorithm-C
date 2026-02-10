# Round-Robin Algorithm in C

This repository contains a **C program** that implements the **Round-Robin (RR) CPU Scheduling Algorithm**, a fundamental concept in **Operating Systems (CS-407)**. The program allows users to simulate RR scheduling **with and without arrival times**, calculate waiting and turnaround times, and display a Gantt chart for process execution.

---

## Features

- Choose between:
  - **Without Arrival Time**: Standard RR scheduling assuming all processes are available at time 0.
  - **With Arrival Time**: RR scheduling considering different process arrival times.
- User-friendly **menu-driven interface**.
- Displays:
  - Burst times (and arrival times, if applicable)
  - Gantt chart with execution intervals
  - Individual waiting times and turnaround times
  - Average waiting time and turnaround time
- **Dynamic input validation** to prevent negative or invalid entries.
- Limit of **20 processes** for simplicity.

---

## Program Flow

1. **Menu Selection**
   - Option 1: Round-Robin without arrival time
   - Option 2: Round-Robin with arrival time
   - Option 3: Exit program

2. **Input Process Details**
   - Number of processes (up to 20)
   - Burst time of each process
   - Arrival time (only for Option 2)
   - Quantum time

3. **Process Scheduling**
   - Executes processes in **round-robin order**.
   - Updates remaining burst times after each quantum.
   - Displays execution intervals in a **Gantt chart**.
   - Calculates **waiting times** and **turnaround times** for each process.

4. **Output**
   - Process table with burst/arrival times
   - Gantt chart
   - Individual waiting and turnaround times
   - Average waiting and turnaround times

---

## How to Run

1. Clone the repository:

git clone https://github.com/ahmad-maqsood/Round-Robin-Algorithm-C.git 

2. Compile the C program using gcc:

gcc round_robin.c -o round_robin

3. Run the compiled program:

./round_robin

---

# Sample Output

=============================
Please Select an Option:-
1. Without Arrival Time.
2. With Arrival Time.
3. End the Program.
Input(1-3) : 1

===========Number of Processes=========
Enter the Number of Processes(Max : 20) : 3

===========Burst Time=========
Process #1: 5
Process #2: 3
Process #3: 8

===========Quantum Time=========
Enter the Quantum Time : 2

====================Table==================
Process     BurstTime
P1          5
P2          3
P3          8

====================Gantt Chart==================
P1    || I.T : 0-2    || R.T : 3
P2    || I.T : 2-4    || R.T : 1
P3    || I.T : 4-6    || R.T : 6
...

---

*Note: This code is optimized for Windows environments (uses `system("cls")` for UI).*
