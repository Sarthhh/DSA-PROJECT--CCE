# Warehouse Navigation using Dijkstra's Algorithm (C++)

## Problem Statement
Develop a warehouse navigation graph with weighted paths, and apply Dijkstra's algorithm to find the shortest route from a charging station to a selected storage location.

## Overview
The warehouse is modelled as an **undirected weighted graph**:

- **Nodes**: the charging station, aisle junctions (`J1`-`J6`), storage racks (`Rack A1` ... `Rack C2`) and the packing area.
- **Edges**: aisles between nodes.
- **Weights**: distance in metres (can also represent travel time or congestion cost).

A robot/AGV starts at the **Charging Station**. The user selects a storage location, and Dijkstra's algorithm finds the minimum-cost route.

## Graph (Edge List)

| From | To | Weight (m) |
|------|----|-----------|
| Charging Station | J1 | 10 |
| Charging Station | J2 | 15 |
| J1 | J2 | 6 |
| J1 | J3 | 15 |
| J2 | J4 | 12 |
| J3 | J4 | 5 |
| J3 | J5 | 8 |
| J4 | J6 | 10 |
| J5 | J6 | 6 |
| J1 | Rack A1 | 7 |
| J2 | Rack A2 | 9 |
| J3 | Rack B1 | 4 |
| J4 | Rack B2 | 6 |
| J5 | Rack C1 | 5 |
| J6 | Rack C2 | 3 |
| J6 | Packing Area | 8 |
| Rack B1 | Rack B2 | 3 |

## Algorithm: Dijkstra
1. Set `dist[source] = 0` and all other distances to infinity.
2. Push `(0, source)` into a min-heap (`priority_queue`).
3. Pop the node `u` with the smallest distance (skip it if the entry is stale).
4. For every neighbour `v` with edge weight `w`: if `dist[u] + w < dist[v]`, update `dist[v]`, set `prev[v] = u` and push `(dist[v], v)`.
5. Repeat until the heap is empty.
6. Rebuild the path by following `prev[]` from the target back to the source, then reverse it.

**Time complexity:** O((V + E) log V) with a binary heap.
**Limitation:** works only with non-negative edge weights (the code rejects negative weights).

## Files
| File | Description |
|------|-------------|
| `warehouse_dijkstra.cpp` | Graph class, Dijkstra implementation, console menu |
| `README.md` | This document |

## Requirements
- A C++17 compiler (g++ 7+, clang, or MSVC)
- No external libraries

## How to Compile and Run
```bash
g++ -std=c++17 -o warehouse warehouse_dijkstra.cpp
./warehouse          # Windows: warehouse.exe
```
Enter the number of the storage location when asked.

## Sample Output
```
=== Warehouse Navigation (Dijkstra) ===
Available storage locations:
  1. Packing Area
  2. Rack A1
  3. Rack A2
  4. Rack B1
  5. Rack B2
  6. Rack C1
  7. Rack C2

Select destination number: 6

Shortest route to Rack C1:
  Charging Station -> J1 -> J3 -> J5 -> Rack C1
Total distance: 38 m

Step-by-step:
  Charging Station -> J1: 10 m
  J1 -> J3: 15 m
  J3 -> J5: 8 m
  J5 -> Rack C1: 5 m

Distance from charging station to all storage locations:
  Packing Area  45 m
  Rack A1       17 m
  Rack A2       24 m
  Rack B1       29 m
  Rack B2       32 m
  Rack C1       38 m
  Rack C2       40 m
```

## Customising
- Add or change aisles in `buildWarehouse()` using `g.addPath(a, b, weight)`.
- Change `START` to use a different charging station.
- To block an aisle, remove that edge or give it a very large weight.

## Possible Extensions
- Multiple charging stations (run from each and pick the minimum).
- Dynamic weights based on traffic or congestion.
- A* search with a heuristic for larger warehouses.
- Graph visualisation of the chosen path.

## Applications
Automated Guided Vehicles (AGVs), warehouse robots, pick-path optimisation, logistics planning.
