# Banker's Algorithm for Deadlock Avoidance

## Aim

To implement Banker's Algorithm for Deadlock Avoidance using C.

## Description

Banker's Algorithm is a deadlock avoidance algorithm used in Operating Systems.
It checks whether the system is in a safe state before allocating resources.

## Algorithm

1. Initialize Allocation, Maximum and Available matrices.
2. Calculate the Need matrix.
3. Set Work equal to Available.
4. Find a process whose Need is less than or equal to Work.
5. If found, assume the process completes.
6. Add its allocated resources to Work.
7. Add the process to the safe sequence.
8. Repeat until all processes finish.
9. If all processes finish, the system is safe.
10. Otherwise, the system is unsafe.

## Formula

Need = Maximum - Allocation

## Technologies Used

- C
- Operating Systems
- GitHub

## Output

The program displays the Need Matrix and Safe Sequence.

## Result

Thus, Banker's Algorithm was successfully implemented to determine
whether the system is in a safe state and to avoid deadlock.
